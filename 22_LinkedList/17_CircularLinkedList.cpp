/*
    Circular Linked List and inserting elements in a Circular Linked List

    In this linked list, the last element instead of pointing to NULL or another member in between,
    it points to the head of the list. So this forms a circle, upon which this structure is named.

    Uses:
    1.  Used in CPU algorithms
    2.  Also used in queue

    In this program we will do:
    1.  Create a Circular Linked List
    2.  Insert Elements in the Circular Linked List
    3.  Print the Circular Linked List
    4.  Search if a particular element is present in the Linked List
    5.  Delete a given element from our Linked List
*/

# include<iostream>
using namespace std;

class node
{
    public:
        int data;
        node* next;

        //constructor
        node (int aData)
        {
            data = aData;
            next = NULL;
        }
};

// insertion in circular linked list
void insert(node* &head, int data)
{
    node* n = new node(data);
    node* temp = head;

    n->next = head;
    if (temp != NULL) // this means that we are not creating the first node
    {
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = n;

    }
    else // if this is a single node in the linked list, it should point at itself
    {
        n->next = n;
    }
    head = n;
}

void print(node* head)
{
    node* temp = head;
    while(temp->next != head)
    {
        cout << temp->data<<" -> ";
        temp = temp->next;
    }

    //  IMPORTANT!!! 
    //  Print the last node explicitly by writing down this
    cout << temp->data << endl;
    return;
}

// searching if a node exists in linked list or not
node* getNode(node* head, int data)
{
    node* temp = head;

    // loop for all nodes except the last node as the while condition terminates upon reaching last node
    while (temp->next != head)
    {
        if (temp->data == data)
            return temp;

        temp = temp->next;
    }
    // out of the loop and need to check for the last node
    if (temp->data == data)
    {
        return temp;
    }

    return NULL;
}

// delete any given node in a linked list
void deleteNode (node* &head, int data)
{
    node* del = getNode(head, data);
    if (del == NULL) // means the node is not present in the linked list
        return;

    //otherwise
    if (head == del)
        head = head->next; // if head needs to be deleted, just move head to next position xD

    node* temp = head;
    // stop one step behind the node to be deleted
    while (temp->next != del)
    {
        temp = temp->next;
    }
    temp->next = del->next;
    delete del;
}

int main()
{
    node* head = NULL;
    insert(head, 1);
    insert(head, 2);
    insert(head, 3);
    insert(head, 4);
    insert(head, 5);
    print(head);

    deleteNode(head, 3);
    print(head);
    deleteNode(head, 1);
    print(head);

    return 0;
}