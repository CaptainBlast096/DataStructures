#include <iostream>
#include <string>
#include <vector>
#include <list> //Will be used for chaining

using std::string;
using std::vector;
using std::list;
using std::cin;
using namespace std;

struct Query //A structure containing string type and s along with size_t ind.
{
    string type, s;
    size_t ind;
};

class QueryProcessor
{
    int bucket_count; // number of buckets
// store all strings in one vector
    vector<list<string>> elems; // A vector of lists of strings to store the contacts.

    size_t hash_func(const string& s) const // A function to calculate the hash value of a string.
    {
        static const size_t multiplier = 263;
        static const size_t prime = 1000000007;
        unsigned long long hash = 0;
        for (int i = static_cast<int> (s.size()) - 1; i >= 0; --i) //i is assigned the size of the string minus 1. i is greater than or equal to 0. i is decremented by 1.
            hash = (hash * multiplier + s[i]) % prime;
        return hash % bucket_count;
    }

public:

    explicit QueryProcessor(int bucket_count): bucket_count(bucket_count), elems(bucket_count) {}

    Query readQuery() const
    {
        Query query;
        cin >> query.type;
        if (query.type != "check")
            cin >> query.s;
        else
            cin >> query.ind;
        return query;
    }

    void writeSearchResult(bool was_found) const
    {
        cout << (was_found ? "yes\n" : "no\n");
    }

    void processQuery(const Query& query)
    {
    if (query.type == "check")
    {
        for (const auto& s : elems[query.ind])
            cout << s << " ";
        cout << "\n";
    }
    else
    {
        size_t hash_val = hash_func(query.s);
        auto &lst = elems[hash_val]; //Get the list for the hash value
        auto it = ::find(lst.begin(), lst.end(), query.s); //Find the query string in the list
        if (query.type == "find")
            writeSearchResult(it != lst.end());
        else if (query.type == "add")
        {
            if (it == lst.end())
                lst.push_front(query.s);
        }
        else if (query.type == "del")
        {
            if (it != lst.end())
                lst.erase(it);
        }
    }

    }

    void processQueries()
    {
        cout << "Output:" << endl;
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i)
            processQuery(readQuery());
    }

    string add(const string& s)
    {
        size_t hash_value = hash_func(s);
        auto& lst = elems[hash_value];
        auto it = ::find(lst.begin(), lst.end(), s); //Find the query string in the list
        if (it != lst.end()) //If the string is already present, return the string
        {
            return s;
        }
        else
        {
            lst.push_front(s); //Else add the string to the list and return an empty string
            return ""; //Return an empty string
        }
    }
    string del(const string& s)
    {
        size_t hash_value = hash_func(s);
        auto& lst = elems[hash_value];
        auto it = ::find(lst.begin(), lst.end(), s); //Find the query string in the list
        if (it != lst.end()) //If the string is already present, return the string
        {
            lst.erase(it);
            return s;
        }
        else
        {
            return "not found"; //Return an empty string
        }
    }

    string find(const string& s)
    {
        size_t hash_value = hash_func(s);
        auto& lst = elems[hash_value];
        auto it = ::find(lst.begin(), lst.end(), s); //Find the query string in the list
        if (it != lst.end()) //If the string is already present, return the string
        {
            return "yes";
        }
        else
        {
            return "no"; //Return an empty string
        }
    }

    void check(int i)
    {
        const auto& lst = elems[i];
        for (const auto& s : lst)
        {
            cout << s << " ";
        }
        cout << endl;
    }
};

int main()
{
    cout << "Input:" << endl;
    ios_base::sync_with_stdio(false);
    int bucket_count;
    cin >> bucket_count;
    QueryProcessor proc(bucket_count);
    proc.processQueries();
    return 0;
}
