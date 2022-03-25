/*

    Implementing a linked list and inserting values in it.

*/

# include <iostream>
using namespace std;

class node
{
    public:
        int data;
        node *next;

        // constructor
        node (int aData)
        {
            data = aData;
            next = NULL;
        }
};

// now we can either create function to perform linked list behavior (procedural programming)
// or we can create a linked list class to create our own data structure (object oriented programming)

// we are going to create functions for each different task as usually in an interview you need to complete these functions

// node* &head means we are passing the head by reference so the REAL head is changed after the function call is over
void insertAtHead (node* &head, int data)
{
    if (head == NULL)
    {
        head = new node(data);
        return;
    }

    node* temp = new node(data);
    temp->next = head; // or can do: (*temp).next = (*head).next;
    head = temp;
}

// passing this head by VALUE, if it was reference then ACTUAL head will become NULL and whole list is ruined
void printLL (node* head)
{
    while (head != NULL)
    {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "\b\b\b\b      " << endl;
}

int main ()
{
    // since we do not have the linked list class, we need a variable to keep track of the head of the linked list
    node* head = NULL; 

    insertAtHead(head, 3);
    insertAtHead(head, 2);
    insertAtHead(head, 1);
    insertAtHead(head, 0);
    
    printLL(head);
    printLL(head);

    return 0;
}