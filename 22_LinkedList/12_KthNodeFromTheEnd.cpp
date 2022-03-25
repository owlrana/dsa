// finding the Kth node from the end of a linked list

/*
    Suppose we have a linked list:
    1->2->3->4->5->6->7
    and we need to find the 3rd node from the end of this linked list, which is = 5;

    APPROACH #1: double pass approach
    You can iterate N-K times from the beginning (if you know the length N of the linked list)
    otherwise it will require two traversals.

    APPROACH #2: slow-fast pointer approach
    1.  Pointer 1 iterates and goes to kth element from the start
    2.  Pointer 2 starts from the head, and BOTH POINTER 1 AND POINTER 2 now iterate one element at a time
    3.  Keep iterating until POINTER 1 reaches the end, in the mean time, POINTER 2 reaches N-Kth node!!

*/

# include <iostream>
using namespace std;

class node
{
    public:
        int data;
        node *next;

        node (int aData)
        {
            data = aData;
            next = NULL;
        }
};

void insertAtHead (node *&head, int data)
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

void printLL (node *head)
{
    while (head != NULL)
    {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "\b\b\b\b      " << endl;
}

int length(node *head)
{
    int len = 0;
    while (head!= NULL)
    {
        len ++;
        head = head->next;
    }
    return len;
}

void insertAtTail (node *&head, int data)
{
    if (head == NULL)
    {
        head = new node(data);
        return;
    }

    node *tail = head;
    while (tail->next != NULL)
    {
        tail = tail->next;
    }

    tail->next = new node(data);
    return;
}

void insertAtMiddle (node *&head, int index, int data)
{
    if (head == NULL or index == 1)
    {
        insertAtHead(head, data);
        return;
    }
    else if (index > length(head))
    {
        insertAtTail(head, data);
    }
    else
    {
        int jump = 1;
        node *temp = head;
        while (jump < index - 1)
        {
            temp = temp->next;
            jump ++;
        }

        node *n = new node(data);
        n->next = temp->next;
        temp->next = n;
    }

}

void deleteHead (node *&head)
{
    if (head == NULL)
        return;

    node *temp = head->next;
    delete head; // deletes the memory in dynamic area, the varable "head" is static and is NOT deleted
    head = temp;
    return; 
}

void deleteAtPosition (node *&head, int position)
{
    if (head == NULL or position == 1)
    {
        deleteHead(head);
        return;
    }
    
    node *prev = head;
    int jump = 0;
    while (jump < position - 2)
    {
        jump += 1;
        prev = prev->next;
    }

    // printLL(prev); // currently at this place
    node *storage = prev->next->next;
    delete prev->next;
    prev->next = storage;
    return;
}

int searchLinkedList(node *head, int key)
{
    int count = 0;
    while (head != NULL)
    {   
        count += 1;
        if (head->data == key)
            return count;
        head = head->next;
    }
    return -1;
}

int recursiveSearch(node *head, int key, int index)
{
    if (head == NULL)
        return -1;

    if (head->data == key)
        return index;
    else
        return recursiveSearch(head->next, key, index+1);
}

void take_input(node* head)
{

}

node* take_input2()
{
    int d;
    cin >> d;

    node *head = NULL;

    while (d != -1)
    {
        insertAtHead(head, d);
        cin >> d;
    }

    return head;
}

ostream& operator<< (ostream &os, node* head)
{
    printLL(head);
    return os; // this is cascading of operators, read comments in main() for more information
}

istream& operator>> (istream &is, node* &head)
{
    head = take_input2();
    return is; // returning cin , input stream
}

void reverse (node* &head)
{
    node* C = head;
    node* P = NULL;
    node* N;

    while (C != NULL)
    {
        // save the next node
        N = C->next;

        // make the current node point to prev
        C->next = P;

        // update P and C and take them one step forward
        P = C;
        C = N; 
        // most important thing is the order of these steps above^
    }
    head = P;
}

node* recursiveReverse (node* head)
{
    // base case
    // smallest linked list to reverse would be either 1 node or 0 node
    if (head->next == NULL or head == NULL)
    {
        return head;
    }

    // recursive case
    node* smallHead = recursiveReverse(head->next);

    node* temp = smallHead;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    head->next = NULL;
    temp->next = head;
    return smallHead;
}

// finding the mid point of a linked list in single pass
node* midpoint (node* head)
{
    if (head == NULL or head->next == NULL)
    {
        return head;
    }

    node* slow = head;
    node* fast = head->next;

    // a condition on fast such that we do not access a NULL or NULL->next as it will give error
    while (fast != NULL and fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    
    return slow;
}

int main ()
{
    node* head;
    cin >> head;

    cout << head;

    node* mid = midpoint(head);
    cout << mid->data;

    /*
    node* head = take_input2();
    printLL(head);
    insertAtHead(head, 6);
    insertAtHead(head, 5);
    insertAtHead(head, 4);
    insertAtHead(head, 3);
    insertAtHead(head, 2);
    insertAtHead(head, 1);
    
    printLL(head);

    cout << searchLinkedList(head, 8) << endl;
    cout << recursiveSearch(head, 5, 1) << endl;

    printLL(head);
    */

    return 0;
}