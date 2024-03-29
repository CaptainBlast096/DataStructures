#include <iostream>
#include <vector>
#include <string>
using namespace std;
using std::string;
using std::vector;
using std::cin;

struct Query // A structure to store a query to the phone book with a type (add, del, find) and a number (for the find query) or a number and a name (for the add query).
{
    string type, name;
    int number;
};

vector<Query> read_queries()
{
    int n;
    cin >> n;
    vector<Query> queries(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> queries[i].type;
        if (queries[i].type == "add")
            cin >> queries[i].number >> queries[i].name;
        else
            cin >> queries[i].number;
    }
    return queries;
}

void write_responses(const vector<string>& result)
{
    cout << "Output:\n";
    for (size_t i = 0; i < result.size(); ++i)
        cout << result[i] << "\n";
}

void add (vector<Query>& contacts, int number, string name) // A function to add a contact to the phone book or rewrite the name of a contact if it already exists.
{
    bool was_founded = false; // A flag to check if the contact already exists.
    for (size_t j = 0; j < contacts.size(); ++j) // A loop to check if the contact already exists.

        if (contacts[j].number == number) // If the contact already exists, rewrite its name.
        {
            contacts[j].name = name; // Rewrite the name of the contact.
            was_founded = true; // Set the flag to true.
            break;
        }

    if (!was_founded) // If the contact does not exist, add it to the phone book.
    {
        Query new_contact; // Create a new contact.
        new_contact.number = number; // Set the number of the new contact.
        new_contact.name = name; // Set the name of the new contact.
        contacts.push_back(new_contact); // Add the new contact to the phone book.
    }
}

void del (vector<Query>& contacts, int number) // A function to delete a contact from the phone book.
{
    for (size_t j = 0; j < contacts.size(); ++j) // A loop to check if the contact exists.
        if (contacts[j].number == number) // If the contact exists, delete it.
        {
            contacts.erase(contacts.begin() + j); // Delete the contact.
            break;
        }
}

string findNumber (vector<Query>& contacts, int number) // A function to find a contact in the phone book.
{
    string response = "not found"; // A string to store the response.
    for (size_t j = 0; j < contacts.size(); ++j) // A loop to check if the contact exists.
        if (contacts[j].number == number) // If the contact exists, return its name.
        {
            response = contacts[j].name; // Set the response to the name of the contact.
            break;
        }
    return response;
}
//Kept original function in order to compare with the new one
vector<string> process_queriesBeta(const vector<Query>& queries) // A function to process queries to the phone book.
{
    vector<string> result; // A vector to store the responses to the queries.
// Keep list of all existing (i.e. not deleted yet) contacts.
    vector<Query> contacts; // A vector to store the contacts in the phone book.
    for (size_t i = 0; i < queries.size(); ++i) // A loop to process the queries.
        if (queries[i].type == "add") // If the query is to add a contact, add it to the phone book.
        {
            bool was_founded = false; // A flag to check if the contact already exists.
// if we already have contact with such number,
// we should rewrite contact's name
            for (size_t j = 0; j < contacts.size(); ++j) // A loop to check if the contact already exists.
                if (contacts[j].number == queries[i].number) // If the contact already exists, rewrite its name.
                {
                    contacts[j].name = queries[i].name; // Rewrite the name of the contact.
                    was_founded = true; // Set the flag to true.
                    break;
                }
// otherwise, just add it
            if (!was_founded) // If the contact does not exist, add it to the phone book.
                contacts.push_back(queries[i]); // Add the contact to the phone book.
        }
            else if (queries[i].type == "del") // If the query is to delete a contact, delete it from the phone book.
            {
            for (size_t j = 0; j < contacts.size(); ++j) // A loop to check if the contact exists.
                if (contacts[j].number == queries[i].number) // If the contact exists, delete it.
                {
                    contacts.erase(contacts.begin() + j); // Delete the contact.
                    break;
                }
        }
            else
        {
            string response = "not found";
            for (size_t j = 0; j < contacts.size(); ++j)
                if (contacts[j].number == queries[i].number)
                {
                    response = contacts[j].name;
                    break;
                }
            result.push_back(response);
        }
    return result;
}

vector<string> process_queries(const vector<Query>& queries)
{

    vector<string> result;
    vector<Query> contacts;
    for (size_t i = 0; i < queries.size(); ++i) // A loop to process the queries.
        if (queries[i].type == "add")
            add(contacts, queries[i].number, queries[i].name);
        else if (queries[i].type == "del")
            del(contacts, queries[i].number);
        else
            result.push_back(findNumber(contacts, queries[i].number));
    return result;
}

int main()
{
    cout << "Input: " << endl;

    write_responses(process_queries(read_queries()));
    return 0;
}

