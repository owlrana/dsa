// Checking if a given tree is a binary tree or not

// you can use LONG_MIN and LONG_MIN instead of INT_MIN and INT_MAX for large numbers if required!

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

// FUNCTION TO CHECK IF THE GIVEN TREE IS A BST OR NOT
bool checkBST(Node* root, long minV = LONG_MIN, long maxV = LONG_MAX)
{
    if (root == NULL)
    {
        return true;
    }
    
    //  need to check 4 things here:
    //  1.  if root->data is <= maxV (which is LONG_MAX for the root node only)
    //  2.  if root->data is >= minV (which is LONG_MIN for the root node only)
    //  3.  if left subtree is a BST (with maxV passed as the root node's data)
    //  4.  if right subtree is a BST (with minV passed as the root node's data)
    if (root->data <= maxV and root->data >= minV and checkBST(root->left, minV, root->data) and checkBST(root->right, root->data, maxV))
    {
        return true;
    }
    
    return false;
}

int main()
{
    Node* root = build();
    bfsPrintWithLevels(root);
    cout << endl;
    bfsPrintWithLevels(root);
    cout << endl;

//  FUNCTION TO CHECK IF THE GIVEN TREE IS A BST OR NOT

    if (checkBST(root))
    {
        cout << "It is a BST!" << endl;
    }
    else
    {
        cout << "It is NOT a BST" << endl;
    }

    return 0;
}