// Creating a BST and different methods available for it

// for the input: 5 3 7 1 6 8 -1
// you will get: 
/*
    5
    3 7 
    1 6 8
*/

// ---------- VERY IMPORTANT POINT TO REMEMBER ABOUT BINARY SEARCH TREE ----------
// INORDER PRINT of a binary search tree is ALWAYS SORTED!!!

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

// Printing Inorder of BST to see if it is always sorted or not
void printInorder (Node* root)
{
    if (root == NULL)
    {
        return;
    }

    // handling the recursive cases and printing the node
    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);

    return;
} 

// Searching in a BST
bool searchData (Node* root, int key)
{
    if (root == NULL)
    {
        return false;
    }

    // if our root value is equal to what we wanted to search for
    if (root->data == key)
    {
        return true;
    }

    // else we decide any single subtree and send recursive call to them
    
    if (key <= root->data) // if they key entered is smaller, it may be in the left subtree
    {
        return searchData(root->left, key);
    }
    else
    {
        return searchData(root->right, key); // if the key enteres is bigger, may be in right subtree
    }
}

//  Deleting Node in a BST
Node* deleteNode(Node* root, int key)
{
    if (root == NULL)
    {
        return NULL;
    }

    if (key < root->data)
    {
        root->left = deleteNode(root->left, key);
        return root;
    }
    else if (key == root->data)
    {
        // There will be 3 cases in this 

        // CASE 1 - Node has both left & right subtree as NULL
        if (root->left == NULL and root->right == NULL)
        {
            // in this case, just delete this node as nothing depends on it. Returns NULL to parent.
            delete root;
            return NULL;
        }

        // CASE 2 - NODE HAS ONLY A SINGLE SUBTREE (LEFT / RIGHT) AS NULL
        
        // 1. Left NOT null but right is NULL
        if (root->left != NULL and root->right == NULL)
        {
            // in this case we need to have the data of left node with us
            Node* temp = root->left;
            delete root->left;
            return temp;
        }

        // 2. Right is NOT null but left is NULL
        if (root->right != NULL and root->left == NULL)
        {
            // in this case we need to have the data of right node with us
            Node* temp = root->right;
            delete root;
            return temp;
        }

        // CASE 3 - in this case neither of them is NULL.
        // Here, we need to find some value from subtree's leafs that can be replaced here
        Node* replace = root->right;

        while (replace->left != NULL)
        {
            replace = replace->left;
        }

        root->data = replace->data;
        root->right = deleteNode(root->right, replace->data);
        return root;
    }
    else
    {
        root->right = deleteNode(root->right, key);
        return root;
    }
}

int main()
{
//  CHECKING THE BUILD OF THE BST
    Node* root = build();
    bfsPrintWithLevels(root);
    cout << endl;

//  INORDER PRINT OF A BINARY SEARCH TREE IS ALWAYS GOING TO BE SORTED
    printInorder(root);
    cout << endl;

//  SEARCHING FOR A KEY IN THE BINARY SEARCH TREE
    int key = 8;
    bool found = searchData(root, key);
    if (found)
    {
        cout << "Element was found!" << endl;
    }
    else
    {
        cout << "Element not found" << endl;
    }

//  DELETION IN A BINARY SEARCH TREE
    
    printInorder(root);
    cout << endl;
    deleteNode(root, 7);
    cout << endl;
    printInorder(root);

    return 0;
}