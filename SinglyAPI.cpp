/*
 * @SinglyAPI.cpp
 * @author Jaleel Rogers (jrogers1239@floridapoly.edu)
 * @brief Singly Linked List
 * @version 0.1
 * @date 2023-02-02
 * 
 * @copyright Copyright (c) 2023
 */

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

    void MakeTail() //Made to update the tail pointer | Causing pointer errors, need to find a better solution
    {
        /*
         * Caused me to receive : Process finished with exit code -1073741819 (0xC0000005)
         * Dosen't properly handle the case where the head pointer is a nullptr
        Node *curr = head; //Initializing pointer called curr to the head of the list

        if(tail -> next != nullptr) //Checks if the next pointer is not equal to nullptr
        {
            while(curr -> next != nullptr)  //If not empty function enters a loop
            {
                curr = curr -> next; //curr is updated to the next node in the list until next pointer is equal to nullptr
            }
            */

        Node *curr = head; //Intialize curr pointer to the head of the list
        if (head == nullptr) //If the list is empty
        {
            tail = nullptr; //Tail is also set to null
        }
        else //If the list is not empty
        {
            while (curr->next != nullptr) //Function will enter a loop where curr is updated to next node in the list until next pointer is equal to nullptr
            {
                curr = curr->next;
                tail = curr; //Then tail pointer is updated to curr, which will point to the last node in the list
            }
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
    {
        Node *temp = new Node; // Creates new instance of node and assigns it to a pointer called temp. 'new' is used to dynamically allocate memory for the new node
        temp -> data = key; //Assigns the value of the variable "value" to the "data" field of the node object that "temp" is pointing to.
        temp -> next = head; //Assigns the value of the "head" pointer to the "next" field of the node object that "temp" is pointing to. It links the new node to the current head of the list.
        head = temp; //Assigns the value of the "temp" pointer to the "head" pointer, making the new node the new head of the list.
        MakeTail();//Purpose: update the tail after remove the front item in list.
        //This ensures the tail will always point to the last node in the list.
    }

    int TopFront()//Returns data to the front of the list
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

        Node *temp = new Node;
        temp -> data = key;
        tail -> next = temp;
        tail = temp;
    }

    int TopBack()//Returns the last node
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

        if (Empty()) //If the linked list is empty, will return following statement
        {
            cout << "List is empty" << endl;
            return;
        }

        while (curr -> next != nullptr) //If not empety. curr will move throught linked list updating curr to next till end of list
        {
            prev = curr;
            curr = curr -> next;
        }
        //Change order of tail and delete and prev and tail

        delete curr;
        prev -> next = nullptr;
        tail = prev;

    }

    bool FindKey(int key)//Will be a boolean asking for an integer | boolean will output 1 (true) or 0 (false) respectively
    {
        Node *curr = head;
        if (Empty())
        {
            return false;
        }
        while (curr -> next != nullptr)
        {
            if (curr -> data == key)
            {
                return true;
            }
            curr = curr -> next;
        }
        return false;
    }

    void Erase(int key)//Remove key from list | Bonus function added
    {
        Node *curr = head;
        Node *prev = new Node;

        if (Empty())
        {
            cout << "List is empty" << endl;
            return;
        }

       while (curr -> next != nullptr)
       {
           if (curr -> data == key)
           {
               prev -> next = curr -> next;
               delete curr;
               return;
           }
           prev = curr;
           curr = curr -> next;
       }

       MakeTail(); //Tail pointer should always point to the last node in the list, removing elements can affect the list
                        //So the tail pointer needs to be updated accordingly
    }

    void EraseAll()//Removes all elements from list
    {
        Node *curr = head;
        Node *prev = new Node;

        if(Empty())
        {
            cout << "List is empty" << endl;
            return;
        }

        while (curr != nullptr)
        {
            prev = curr;
            curr = curr -> next;
            delete prev;
        }
        head = nullptr;
        tail = nullptr;
    }

    bool Empty()//Boolean that asks for an integer
    {
        return ((head == nullptr)? true : false);
    }

    void AddBefore(int pos, int data)//Adds key before node
    {
        Node *curr = head;
        Node *prev = NULL;

        if (Empty())
        {
            cout << "List is empty" << endl;
            return;
        }
        if (pos < 0) // Simplified expression from (!(pos >= 0)) to pos < 0
        {
            cout << "Position does not exist" << endl;
            return;
        }

        for (int i = 0; i < pos; i++)
        {
            prev = curr;
            curr = curr -> next;
        }

        Node *newNode = new Node;
        newNode -> data = data;
        newNode -> next = curr;

        if (prev == NULL)
        {
            head = newNode;
        }
        else
        {
            prev -> next = newNode;
        }
    }

    void AddAfter(int pos, int data)//Adds key after node
    {
        //Creating three pointers
        Node *curr = head;

        if (Empty())
        {
            cout << "List is empty" << endl;
            return;
        }

        if (pos < 0) // Simplified expression from (!(pos >= 0)) to pos < 0
        {
            cout << "Position cannot be negative" << endl;
            return;
        }

       int count = 0;
       while (curr != nullptr && count < pos)
       {
           curr = curr -> next;
           ++count;
       }

       if (curr == nullptr)
       {
           cout << "Position does not exist" << endl;
       }

        Node *newNode = new Node;
        newNode -> data = data;
        newNode -> next = curr -> next;
        curr -> next = newNode;
        MakeTail();
    }

    void DisplayAll()//Prints all the elements of the list
    {
        Node *curr = head; // Temporary node
        int count = 0;

        if (Empty())
        {
            cout << "List is empty" << endl;
            return;
        }

        while (curr != nullptr)
        {
          cout << curr -> data << ((curr -> next == nullptr)?"":",");
           curr = curr -> next;
        }
        cout << endl;
    }

    int Size()//Returns the number of elements | iffy if it works
    {
        int count = 0;
        Node *curr =head;

        if (Empty())
        {
            cout << "List is empty" << endl;
            return count;
        }

        while (curr != nullptr)//An iterative approach to finding the length
        {
            count++;
            curr = curr -> next;
        }
        return count;
    }

    void ReplaceKey(int pos, int data)//Overwrite the key to a given node
    {
        Node *curr = head;

        if (Empty())
        {
            cout << "List is empty" << endl;
            return;
        }

        for (int i = 0; i < pos; i++)
        {
            curr = curr -> next;
        }
        curr -> data = data;
        MakeTail();
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

        cout << "List 1: ";
        list1.DisplayAll();
        cout<< "Top: " <<list1.TopFront() << endl;
        cout<< "Bottom: " <<list1.TopBack() << endl;
        list1.PopFront();

        cout << "List 1: ";
        list1.DisplayAll();
        cout << endl;

       list1.PopFront();
       cout << "List 1: ";
       list1.DisplayAll();

       list1.PushBack(10);
       list1.PushBack(12);
       list1.PushBack(14);

       cout << "List 1: ";
       list1.DisplayAll();
       cout << list1.FindKey(25) << endl;
       cout << list1.FindKey(6) << endl;
       cout <<list1.Empty() << endl;

       list1.AddBefore(3,94);
       cout << "List 1: ";
       list1.DisplayAll();

       list1.AddAfter(2,5);
       cout << "List 1: ";
       list1.DisplayAll();

       cout << "Size of list is " << list1.Size() << endl;
       list1.ReplaceKey(6,87);
       cout << "List 1: ";
       list1.DisplayAll();

       list1.PopFront();
       list1.PopFront();
       list1.PopFront();
       list1.PopFront();
       list1.PopFront();
       list1.PopFront();
       list1.PopFront();
       list1.PopFront();

       cout << list1.Empty() << endl;

cout << "BONUS content (The shits and giggles edition)" << endl;
    SinglyLinkedList list2;

        list2.PushFront(35);
        list2.PushFront(990);
        list2.PushFront(56);
        list2.PushFront(76);
        list2.PushFront(69);

        list2.Erase(990);
        cout << "List 2: ";
        list2.DisplayAll();

        list2.EraseAll();
        cout << "List 2: ";
        list2.DisplayAll();

    SinglyLinkedList list3;
        cout << "List 3: ";
        list3.DisplayAll();
}
