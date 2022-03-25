// reverse a linked list recursively

/*
    Suppose we have a linked list:
    1->2->3->4->5
    then what we do is keep (1) and then return reversed (2->3->4->5)
        then keep (2) and return reversed (3->4->5)
            then keep (3) and return reversed (4->5)
                then keep (4) and return reversed (5)

    In the end the reverse linked list is returned.

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

// reversing a linked list through iterative process
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

// reversing linked list using a recursive approach
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

int main ()
{
    node* head;
    cin >> head;

    cout << head;
    head = recursiveReverse(head);
    cout << head;

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