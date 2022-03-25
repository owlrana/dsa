#include<iostream>
using namespace std;

class Node
{   
    public:
        int data;
        Node* next; // DOES NOT TAKE ANY MEMORY

        // constructor
        Node (int d)
        {
            data = d;
            next = NULL;
        }
};

// inserting in a circular linked list
void insertAtHead (Node* &head, int data)
{
    Node* n = new Node(data); // storing the data in heap memory with pointer n pointing it

    n->next = head; // just making chain from n to head, later on we can point tail to n and be done!

    Node* temp = head; // temp will traverse to the tail (tail is when temp->next == head) 
    // or NULL, in case the list is empty currently, so we need to keep that in mind as well

    if (temp != NULL) // check if this is the first node being inserted or not...
    {
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = n;
    }
    else // means this is the first node, it should be a self loop and should point to itself!
    {
        n->next = n;
    }

    head = n; // this is what you just inserted, now the loop will start from n
}

// printing the linked list
void printList (Node* head)
{
    Node* temp = head;
    while (temp != NULL and temp->next != head)
    {
        cout << temp->data;
        temp = temp->next;
    }
    cout << temp->data; // this last would not be printed in above loop as temp->next would be head
    
    return;
}

// searching to find out where a node with particular value lies.
Node* getNode (Node* head, int key)
{
    Node* temp = head;

    while (temp->next != head)
    {
        if (temp->data == key)
            return temp;
        temp = temp->next;
    }
    if (temp->data == key)
    {    
        return temp;
    }

    return NULL;
}

// deletion in the circular linked list
void deleteList (Node* &head, int key)
{
    // two cases will be there:
    // 1. if the given node to be deleted is a head node (tail node will be required to change)
    // 2. other nodes (only the adjacent nodes will be required to change)

    Node* del = getNode(head, key);

    if (del == NULL)
        return;

    // if the key to be deleted is head, then move head by one step (as it will anyways be the new head)
    // and then the process of deletion can take place easily.
    if (head == del)
    {
        head = head->next;
    }

    Node* temp = head;

    // need to stop one step behind what is to be deleted
    while (temp->next != del)
    {
        temp = temp->next;
    }
    temp->next = del->next;

    delete del;
}

int main()
{
    // inserting nodes in the head
    Node* head;
    insertAtHead(head, 5);
    insertAtHead(head, 4);
    insertAtHead(head, 3);
    insertAtHead(head, 2);
    insertAtHead(head, 1);
    
    // printing the linked list
    printList(head);

    printList(head);
    insertAtHead(head, 29);
    cout << endl; 
    printList(head);
    cout << endl;

    // deleting different nodes
    deleteList(head, 5);
    printList(head);
    cout << endl;
    deleteList(head, 29);
    printList(head);
    return 0;
}