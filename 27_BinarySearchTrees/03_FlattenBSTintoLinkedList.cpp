// FLATTENING A BST INTO A SORTED LINKED LIST

//  doing this WITHOUT ANY EXTRA SPACE by just changing nodes and pointers

#include<iostream>
#include<queue>
using namespace std;

// Node class for the Binary Search Tree
class Node
{
public:
    int data;
    Node* left;
    Node* right;

    Node(int aData)
    {
        data = aData;
        left = NULL;
        right = NULL;
    }
};

// helper function for build() to insert numbers into a BST through its root
// this function accepts the old root node & data and then returns the NEW root node
Node* insertInBST (Node* root, int data)
{
    // base case
    if (root == NULL)
    {
        return new Node(data);
    }

    // recursive case
    if (data <= root->data)
    {
        root->left = insertInBST(root->left, data);
    }
    else
    {
        root->right = insertInBST(root->right, data);
    }

    return root;
}

// building the binary search tree
Node* build ()
{
    // returns a list of numbers till -1 is reached inserted into a BST

    int d;
    cin >> d;

    Node* root = NULL;

    while (d != -1)
    {
        // keep going on inserting until d is -1
        root = insertInBST(root, d);
        cin >> d;
    }
    return root;
}

// Helper function only to print and check the build of BST we are creating
void bfsPrintWithLevels(Node* root)
{
    queue<Node*> myQ;
    myQ.push(root);
    myQ.push(NULL);
    
    while (not myQ.empty())
    {
        if (myQ.front() == NULL)
        {
            cout << endl; // print a new line immediately
            myQ.pop(); // push it out as this is done!
            
            if (not myQ.empty())
            {
                myQ.push(NULL); // only push it IF THE QUEUE IS NOT EMPTY OTHERWISE ENDLESS LOOP
            }
        }
        else // otherwise, do our normal BFS printing
        {
            if (myQ.front()->left != NULL)
            {
                myQ.push(myQ.front()->left);
            }

            if (myQ.front()->right != NULL)
            {
                myQ.push(myQ.front()->right);
            }
            
            cout << myQ.front()->data << "  ";

            myQ.pop();
        }
    }
}

// FLATTENING A BST INTO A SORTED LINKED LIST

// required a pair class to keep track of head and tails
class LinkedPair
{
    public:
        Node* head;
        Node* tail;
};

// function to create the linked list in place. Can be traversed by using RIGHT node here.
LinkedPair flattenIntoLinkedList(Node* root)
{
    LinkedPair l;

    // this base case is different!
    // this will ONLY HIT if the whole tree is ACTUALLY NULL
    // ideally we should not hit this base case....
    if (root == NULL)
    {
        l.head = l.tail = NULL;
        return l;
    }

    // so ideally this should be the only base case
    if (root->left == NULL and root->right == NULL)
    {
        l.head = l.tail = root;
        return l;
    }

    // if left is not null but right is...
    if (root->left != NULL and root->right == NULL)
    {
        LinkedPair leftSubList = flattenIntoLinkedList(root->left);

        // now the tail of this linked list should point to the root
        leftSubList.tail = root;

        // we also need to update our "l" linked List pair pointer
        l.head = leftSubList.head;
        l.tail = root;
        return l;
    }
    // opposite case now
    // if right is not null but left is
    if (root->right != NULL and root->left == NULL)
    {
        LinkedPair rightSubList = flattenIntoLinkedList(root->right);

        root->right = rightSubList.head;

        l.head = root;
        l.tail = rightSubList.tail;

        return l;
    }

    // last simple case
    // if both of the sides are not null
    // get one linked list from left, get one from the right, and then work on root node

    // this is insertion from the middle, it is evident from here that we're doing POST ORDER traversal

    LinkedPair leftSubList = flattenIntoLinkedList(root->left);
    LinkedPair rightSubList = flattenIntoLinkedList(root->right);

    // now we need to insert the node of root between these
    leftSubList.tail = root;
    root->right = rightSubList.head;

    // now assign these final values to our l pointer thats tracking latest versions
    l.head = leftSubList.head;
    l.tail = rightSubList.tail;

    return l;
}

int main()
{
    Node* root = build();

//  FLATTENING A BST INTO A SORTED LINKED LIST
    LinkedPair l = flattenIntoLinkedList(root);
    Node* temp = l.head;

    while (temp != NULL)
    {
        cout << temp->data << " --> ";
        temp = temp->right;
    }
    cout << endl;

    return 0;
}