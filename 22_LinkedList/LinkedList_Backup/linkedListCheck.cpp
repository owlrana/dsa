/*
    RUN THIS PROGRAM AS:
    cd "/Users/rahulrana/C++/Linked List/" && g++ -std=c++17 linkedListCheck.cpp -o linkedListCheck && "/Users/rahulrana/C++/Linked List/"linkedListCheck < inputList.txt

    All the things you need for a linked list are here.
    Every algorithm is explained carefully in the copy. 
    Have fun!
*/

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

// passing a pointer by reference so no copy of head is created
// now we have access to the real head of the linked list
void insertAtHead(Node* &head, int data)
{
    if (head == NULL)
    {
        head = new Node(data); //just initialise a Node with data d
        // done this dynamically so the data remains in memory
        // even when the function call is over!
        return;
    }

    Node* n = new Node(data);
    n->next = head;
    head = n;
    return;
}

// function to print the linked list
// no need to have ref as dont want to move head pointer anywhere in real
void printLinkedList (Node* head)
{
    while(head!= NULL) // when it reaches the end
    {
        cout << head->data <<", ";
        head = head->next; // need to move head to next, once printed
    }
    cout << endl;
}

// to find the length of a linked list
int length(Node* head)
{
    int size = 0;
    while (head != NULL)
    {
        size ++;
        head = head->next;
    }
    return size;
}

// inserting at the tail of a linked list
void insertAtTail (int data, Node* &head)
{
    if (head == NULL)
    {
        Node* temp = new Node(data);
        head = temp;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    Node* newNode = new Node(data);
    temp->next = newNode; // this already points to NULL by default
    return;
}

// inserting AFTER any position given. imagine it as index
void insertAtPosition(int data, int pos, Node* &head)
{
    if (head == NULL)
    {
        Node* temp = new Node(data);
        head = temp;
        return;
    }
    else if (pos > length(head))
    {
        insertAtTail(data, head);
        return;
    }
    else
    {
        int jump = 1; // need to take pos-1 jumps
        Node* temp = head;
        while (jump < pos)
        {
            temp = temp->next;
            jump++;
        }

        // create a new node
        Node*n = new Node (data);
        n->next = temp->next;
        temp->next = n;
    }
}

//deletion from the head
void deleteHead(Node* &head)
{
    // corner case: if the linked list is already empty
    if (head == NULL)
        return;

    Node* temp = head->next;
    delete head;
    head = temp;

    return;
}

// deletion from the middle
void deleteIndex(Node* &head, int index)
{
    if (head == NULL)
        return;
    else if (index == 0)
    {
        deleteHead(head);
        return;
    }
    else if (index >= length(head))
    {
        deleteIndex(head, length(head) - 1);
        return;
    }

    Node* temp = head;
    int jump = 1;
    while (jump++ < index)
    {
        temp = temp->next;
    }

    Node* toBeDeleted = temp->next;
    temp->next = (temp->next)->next;

    delete toBeDeleted;

    return;
}

// simple search in linked list
bool simpleSearch(Node* head, int key)
{
    while (head != NULL)
    {
        if (head->data == key)
        {
            return true;
        }
        head = head->next;
    }
    return false;
}

// recursive search in linked list
bool recursiveSearch (Node* &head, int key)
{
    if (head == NULL)
    {
        return false;
    }

    if (head->data == key)
    {
        return true;
    }
    else
    {
        return recursiveSearch(head->next, key);
    }
}

// this function takes input from .txt files as input buffer.
// add " < inputText.txt" after normal calling of program to use this efficiently
// otherwise, also works with normal inputs, just need to insert a character in the end to stop
Node* take_input () 
{
    int d;
    Node* head = NULL;
    while (cin >> d)
    {
        insertAtTail(d, head);
    }

    return head;


}

//using cout<< to output the linked list
ostream& operator<< (ostream &os, Node* head)
{
    printLinkedList(head);
    return os;
}

// using cin>> to input a linked list
istream& operator>> (istream &is, Node* head)
{
    head = take_input();
    return is;
}

// simple reverse linked list
void reverseLinkedList (Node* &head)
{
    if (head == NULL)
        return;

    Node* prev = NULL;
    Node* temp; 

    while (temp != NULL)
    {
        temp = head->next;
        head->next = prev;
        prev = head;
        head = temp;
    }

    head = prev;
}

// recursively reverse a linked list (you need to use head = recursiveReverse(head); in int main())
Node* recursiveReverseLinkedList (Node* &head)
{
    // smallest linked list we need to reverse
    if (head->next == NULL or head == NULL) // the second case is only present if linked list is NULL
        return head;

   // recursive case: make a call on smaller part of linked list
    Node* smallHead = recursiveReverseLinkedList(head->next); // this gives you small head

    Node* temp = smallHead;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    head->next = NULL;
    temp->next = head;

    return smallHead;

    // optimisation of this code beneath
}

// optimised reverse a linked list
Node* optimisedReverseLinkedList (Node* &head)
{
    // smallest linked list we need to reverse
    if (head->next == NULL or head == NULL) // the second case is only present if linked list is NULL
        return head;

    // recursive case: make a call on smaller part of linked list
    Node* smallHead = recursiveReverseLinkedList(head->next); // this gives you small head

    // we already know the place of smallHead linked list's tail. It is head->next...
/*  
    Node* temp = smallHead;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
*/

    Node* temp = head->next;
    temp->next = head;
    head->next = NULL;

    return smallHead;
    // optimisation of this code beneath
}

// find the midpoint of the linked list
// in case of odd nodes N, returns the exact mid point 
// in case of even nodes N, returns the N/2th node.
Node* midpoint(Node* &head)
{
    // corner case
    if (head == NULL or head->next == NULL)
        return head;

    Node* fast = head->next; // do as fast = head; if you want (n/2) -1 th node in even nodes case
    Node* slow = head;

    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }

    return slow;
}

// recursively merge two sorted linked lists into one
Node* mergeList(Node* &list1, Node* &list2)
{
    // base case (returns any of the other array if one is empty now)
    if (list1 == NULL)
        return list2;
    if (list2 == NULL)
        return list1;

    // new node to catch all the recursive smaller lists during returning of function
    Node* newList;

    if (list1->data < list2->data)
    {   
        newList = list1; // assign the head of this list as next
        newList->next = mergeList(list1->next, list2); // now call merge with smaller part of list
    }
    else // do the same, but with the other list
    {
        newList = list2;
        newList->next = mergeList(list1, list2->next);
    }

    return newList;
}

// detecting cycle in a linked list
bool cycleDetection (Node* head)
{
    Node* slow = head;
    Node* fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow)
            return true;
    }

    return false;    

}


int main()
{
    Node* head; // this is a pointer of Node data type, and it is NOT a node in itself!!!
    // it is only required so we can point to the Node data type
/*
    Node devang(10);
    head = &devang;
    cout << "hellow" << endl;
 
    cout << (*head).data; // to access member functions/variable of a class stored through POINTER
    // can also do this: 
    // cout << head->data;
    printLinkedList(head);
*/ 

    //inserting at head of a linked list
    insertAtHead(head, 60); 
    insertAtHead(head, 50);
    insertAtHead(head, 40);
    insertAtHead(head, 20);
    insertAtHead(head, 10);
    printLinkedList(head);

    // inserting at a specific index
    insertAtPosition(30, 2, head); 
    printLinkedList(head);

    // deleting the head of linked list
    deleteHead(head); 
    printLinkedList(head);

    // deleting a particular index of linked list
    deleteIndex(head, 20);
    printLinkedList(head);

    // simple searching in linked list
    cout << simpleSearch(head, 5) << endl;

    // recursive searching in linked list
    cout << recursiveSearch(head, 40) << endl;

    // taking list as input from file (input buffer [add " < inputList.txt" in program call])
    Node* newHead = take_input();
    // printLinkedList(newHead); // commented only to check the lines below this
    cout << newHead;

    // reversing the linked list using iterative method
    reverseLinkedList(newHead);
    cout << newHead;

    // recursively reversing a linked list
    newHead = recursiveReverseLinkedList(newHead);
    cout << newHead;

    // optimised recursion in the linked list
    newHead = optimisedReverseLinkedList(newHead);
    cout << newHead;

    insertAtHead(newHead, 0);
    insertAtTail(100, newHead);
    cout << endl;
    cout << newHead;

    // midpoints of the linked list
    cout << midpoint(newHead)->data;
    cout << endl;
    
    // recursively merge two sorted lists
    Node* list1;
    insertAtTail(2, list1);
    insertAtTail(4, list1);
    insertAtTail(6, list1);
    insertAtTail(8, list1);
    insertAtTail(10, list1);
    
    Node* list2;
    insertAtTail(1, list2);
    insertAtTail(3, list2);
    insertAtTail(5, list2);
    insertAtTail(7, list2);
    insertAtTail(9, list2);

    cout << list1 << ", " << list2 << endl;
    cout << mergeList(list1, list2);

    // checking for a circular linked list


    return 0;
}