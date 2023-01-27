#include <iostream>

using namespace std;

class Node
{
    public:
int key;
int data;
Node* next;
Node()
{
key = 0;
data = 0;
next = NULL;
}

Node (int k, int d )
{
key = k;
    data = d;
    next=NULL;
}
}
class SinglyLinkedList
{
    public:
    Node *head; // Will only point towards class Node
    //Use template
        
        void PushFront(Node *h); // Takes one integer
        void TopFront(); // Takes one integer
        void PopFront(); //Takes one integer
        void PushBack(Node *n);//Takes one integer
        void TopBack();//Takes one integer
        void PopBack();//Takes one integer
        void Find(); //Will be a boolean asking for an intege
        void Erase(key); //Takes one integer
        void Empty(key); // Boolean that asks for an integer
        void AddBefore(); // Takes one integer
        void AddAfter(); //Takes one integer
    
}

int main()
{
    cout<<"Hello World";

    return 0;
}
