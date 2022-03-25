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
    // corner case
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
        // take index-1 jumps
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

int main ()
{
    node* head = NULL; 

    insertAtHead(head, 3);
    insertAtHead(head, 2);
    insertAtHead(head, 1);
    
    printLL(head);

    insertAtMiddle(head, 3, 999);   
    insertAtMiddle(head, 1, 999);   
    insertAtMiddle(head, 10, 999);

    printLL(head);

    return 0;
}