// replace  a node by the nearest square (even for even index, odd for odd index)
// indexing starts from 1

# include <iostream>
#include<vector>
#include<math.h>
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

// search a linked list while traversing
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

// searching a linked list using recursion
int recursiveSearch(node *head, int key, int index)
{
    if (head == NULL)
        return -1;

    if (head->data == key)
        return index;
    else
        return recursiveSearch(head->next, key, index+1);
}

int findNearestPrime(int value, int place)
{
    int root = sqrt(value);
    if (root > 1)
        root = root - 1;

    vector<int> ans;
    for (int i = 0; i < 4; i ++)
    {
        if ((root*root)%2 == place%2)
        {
            ans.push_back(root*root);
        }
        root += 1;
    }

    int minVal = INT_MAX;
    int answer = *(ans.begin());
    for (int i = 0; i < ans.size(); i ++)
    {
        int minCurr = abs(ans[i] - value);
        if (minCurr < minVal)
        {
            answer = ans[i];
            minVal = abs(ans[i] - value);
        }
    }

    return answer;
}

node* perfect_square_linked_list(node* head)
{
    node* temp = head;
    int place = 1;

    while (temp != NULL)
    {
        int number = findNearestPrime(temp->data, place);
        // cout << temp->data  << "[" << place << "]" << ", ";
        temp->data = number;
        place += 1;
        temp = temp->next;
    }

    return head;
}

int main ()
{
    node* head = NULL; 

    insertAtHead(head, 16);
    insertAtHead(head, 9);
    insertAtHead(head, 16);
    insertAtHead(head, 1);
    insertAtHead(head, 4); 
    
    printLL(head);

    cout << endl << "Answer:" << endl;

    perfect_square_linked_list(head);
    //cout << findNearestPrime(19, 5);
    
    printLL(head);

    return 0;
}