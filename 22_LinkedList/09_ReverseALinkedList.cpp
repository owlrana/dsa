/*
    At first, swapping comes to mind when we think about reversing things (swap 1st with last etc.)
    but we cannot do this as SWAPPING IS AN EXPENSIVE OPERATION!!!
    It may look alright for a list of integers (only 4 bytes) but imagine if it were a playlist of songs!!!

    So reversing a linked list can be done by just changing the links between elements;
    Eg.                 (head) 1 -> 2 -> 3 -> 4 -> 5
    can be turned into:
                        (head) 5 -> 4 -> 3 -> 2 -> 1

    This is what we will do in this program.

    set prev as NULL
    then current->next = prev (when initialises, sets the first node the NULL and subsequent ones to previous)
    (when you do this 2nd part, you automatically lose the address of the element next to it, so save it as N before 2)
    
    So the final flow is going to look like:
    
    1.  prev = NULL

    2.  n = c -> next;
    3.  c -> next = prev;
    4.  prev = c;
    5.  c = n;
    
    6.  REPEAT FROM 2 to 5, unless c == NULL
    
*/

// OVERLOADING THE cin and cout Operators ( >> and <<) for our linked list

/*
    such that 
        cin >> head; // inserts element
        cout << head; // prints the whole linked list

    to do that, we need to overload the operator of left shift:
        // first object that you need to pass the the "cout" object, then what you want as output
        void operator<< (ostream &os, node* head) // not passing by reference as printing may change real head
        {
            print(head); //our pre-written function for linked list printing is called!
        }
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

// node* &head means we are passing the head by reference so the REAL head is changed after the function call is over
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

// passing this head by VALUE, if it was reference then ACTUAL head will become NULL and whole list is ruined
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

// it is possible that linked list does not exist and someone calls it so thats why head by reference
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

// inserting into middle, but passing head by reference. why? what is someone tells to insert at 0: then we need to change head REAL VALUE
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

int main ()
{
    node* head;
    cin >> head;

    cout << head;
    reverse(head);
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