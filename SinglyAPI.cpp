#include <iostream>

using namespace std;

struct Node // struct is a user-defined data type in C++ the creates a data type that can be usd to group items public by default unlike a class
        //Node contains two data fields, data and next
{
int data; // Represents any data type such as a int, float, or char
Node* next; // A pointer to the next node, pointing to the next node in the list

Node()
{
    next = nullptr; //nullptr is a safer way to create a new node than NULL because it is made for pointers
                       //Last node has to point to a null value
}

};

class SinglyLinkedList
{
private:
    Node *head; // A pointer variable holding the address of the node with the value 1
    Node *tail; // A pointer variable holding the address of the last node

    void MakeTail() //Made to update the tail pointer
    {
        Node *curr = head; //Initializing pointer called curr to the head of the list

        if(tail -> next != nullptr) //Checks if the next pointer is not equal to nullptr
        {
            while(curr -> next != nullptr)  //If not empty function enters a loop
            {
                curr = curr -> next; //curr is updated to the next node in the list until next pointer is equal to nullptr
            }
            tail = curr; //Then tail pointer is updated to curr, which will point to the last node in the list
        }
    };
public:

    SinglyLinkedList():head(nullptr)
    {
        //Setting values to NULL because NULL is used for pointers
            //In order to avoid garbage values by point to no valid object
      // this->  head = nullptr;
      // this-> tail = nullptr;
// All functions should handle the case of an empty List
    }

    void PushFront(int key) //Add to front
    //Function runs fine
    {
       Node *temp = new Node; // Creates new instance of node and assigns it to a pointer called temp. 'new' is used to dynamically allocate memory for the new node
       temp -> data = key; //Assigns the value of the variable "value" to the "data" field of the node object that "temp" is pointing to.
       temp -> next = head; //Assigns the value of the "head" pointer to the "next" field of the node object that "temp" is pointing to. It links the new node to the current head of the list.
       head = temp; //Assigns the value of the "temp" pointer to the "head" pointer, making the new node the new head of the list.
       MakeTail();//Purpose: update the tail after remove the front item in list.
        //This ensures the tail will always point to the last node in the list.
    }

    int TopFront()//Returns data to the front of the list
    //Function runs fine
    {
        if (!Empty()) //Empty is a function used to check whether the set container is empty or not
        {
            return head -> data; //If the list is not empty, returns the data stored in the first node, pointing towards the head
        }
        else
        {
            cout << "List is  empty" << endl;
            return -1;
        }

    }

    void PopFront()//Remove front item
    //Function runs fine
    {
        Node *temp = head;
        if (Empty())
        {
            cout << "List is empty" << endl;
            return;
        }
        head = head -> next;
        delete temp; //temp is no longer needed, so it is appropriate to deallocate memory
        MakeTail(); //Also, inside PopFront because it modifies the head while PushBack and POPBack only modify
                        // the last node, so tail pointer does not need to be updated.
    }

    void PushBack(int key)//Add to back | Exactly the same structure as PushFront but instead of head it will be tail
    {
    //Function runs fine
        Node *temp = new Node;
        temp -> data = key;
        tail -> next = temp;
        tail = temp;
    }

    int TopBack()//Returns the last node
    //Functions runs fine
    {
        if (Empty()) ///Exactly like TopFront
        {
            cout << "List is empty" << endl;
            return -1;
        }
        return tail -> data;
    }

    void PopBack()//Takes one integer
    {
        Node *curr = head;
        Node *prev = nullptr;

        if (Empty())
        {
            cout << "List is empty" << endl;
            return;
        }

        while (curr -> next != nullptr)
        {
            prev = curr;
            curr = curr -> next;
        }
        //Change order of tail and delete and prev and tail

        delete curr;
        prev -> next = nullptr;
        tail = prev;

    }
    bool Find(int key)//Will be a boolean asking for an integer
    {
        Node *curr = head;
        while (curr -> next != nullptr)
        {
            if (curr -> data == key)
                return true;
            curr = curr -> next;
        }
        return false;
    }

    void Erase(int key)//Remove key from list
    {
        Node *curr = new Node;
        Node *prev = new Node;

        curr = head;
        for (int i = 1; i < key; i++)
        {
            prev = curr;
            curr = curr -> next;
        }
        prev -> next = curr -> next;

        Node *temp = new Node;
        temp = head;
        head = head -> next;
        delete temp;
    }

    void EraseAll(int key)//Removes all elements from list
    {
        while(Find(key))
        {
            Erase(key);
        }
    }
    bool Empty()//Boolean that asks for an integer
    {
        return ((head == nullptr)? true : false);
    }
    void AddBefore(int pos, int value)//Adds key before node
    {
        Node *head = new Node;
        Node *curr = new Node;
        Node *temp = new Node;

        curr = head;
        for (int i = 1; i < pos; i++)
        {
            head = curr;
            curr = curr ->next;
        }
        temp -> data = value;
        head -> next = temp;
        temp -> next = curr;
    }
    void AddAfter(int pos, int value)//Adds key after node
    {
        //Creating three pointers
            Node *tail = new Node;
            Node *curr = new Node;
            Node *temp = new Node;
        curr = tail;
        for (int i = 1; i < pos; i++)
        {
            tail = curr;
            curr = curr -> next;
        }
        temp -> data = value;
        tail -> next = temp;
        temp -> next = curr;
    }

    void DisplayAll()//Prints all the elements of the list
    {
        Node *temp = new Node; // Temporary node
        temp = head; // Passing the value stored in head in temp

        while (temp != nullptr)
        {
            cout << temp -> data << " "; //Passing the address of data to temp
            temp = temp -> next; // Passing the address of next to temp and assigning it to temp
        }
    }
    int Size()//Returns the number of elements | iffy if it works
    {
        int count = 0;

        Node *curr =head;

        while (curr != nullptr)//An iterative approach to finding the length
        {
            count++;
            curr = curr -> next;
        }
        return count;
    }
    void static ReplaceKey(Node *node, int newKey)//Overwrite the key to a given node
    {
        node -> data = newKey;
    }

};

int main()
{
    SinglyLinkedList list1;

    list1.PushFront(25);
    list1.PushFront(50);
    list1.PushFront(90);
    list1.PushFront(40);
    list1.PushFront(35);

    cout << "List: ";
    list1.DisplayAll();
    cout << "\n";


    //cout<< "Top: " <<list1.TopFront() << endl;
    //cout<< "Bottom: " <<list1.TopBack() << endl;
    //list1.DisplayAll();

    return 0;
}
