// Replacing nodes by the sum of their child nodes (subtree)
// Version 1: By changing leaf nodes to their subtree sum (0)
// Version 2: By NOT CHANGING leaf nodes

// Use this for input: 8 10 1 -1 -1 6 9 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1

#include<iostream>
#include<queue>
using namespace std;

// Node Class for a tree
class Node
{
    public:
        int data;
        Node* left;
        Node* right;

    Node (int aData)
    {
        data = aData;
        left = NULL;
        right = NULL;
    }
};

// Building a tree
Node* buildTree ()
{
    int d;
    cin >> d;

    if (d == -1)
        return NULL;

    Node* root = new Node(d);

    // recursively build both the lower nodes
    root->left = buildTree();
    root->right = buildTree();

    return root;
}

// printing a tree (only for check,this is Preorder)
void printTreeInorder( Node* root)
{
    if (root == NULL)
    {
        return;
    }

    // otherwise, print the root, and then print the subtrees
    cout << root->data << "  ";
    printTreeInorder(root->left);
    printTreeInorder(root->right);
}

// VERSION: 1
//  Replacing nodes by sum of their child nodes by CHANGING LEAF NODES
int ReplaceBySumOfNodes1 (Node* &root)
{
    if (root == NULL)
    {
        return 0;
    }

    int left = ReplaceBySumOfNodes1(root->left);
    int right = ReplaceBySumOfNodes1(root->right);
    
    int myData = root->data;

    root->data = left + right;

    return left + right + myData;
}

//  VERSION: 2
//  Replacing nodes by sum of their child nodes by CHANGING LEAF NODES
int ReplaceBySumOfNodes2 (Node* root)
{
    if (root == NULL)
    {
        return 0;
    }

    if (root->left == NULL and root->right == NULL)
    {
        return root->data;
    }

    int left = ReplaceBySumOfNodes2(root->left);
    int right = ReplaceBySumOfNodes2(root->right);
    
    int myData = root->data;

    root->data = left + right;

    return left + right + myData;
}

int main()
{
//  Building a tree from user input

    Node* root = buildTree();

//  Inorder, Preorder, Postorder Traversals

    cout << "Inorder Traversal: ";
    printTreeInorder(root);
    cout << endl;

/*
//  Replacing nodes by sum of their child nodes by CHANGING LEAF NODES
    ReplaceBySumOfNodes1(root);
    cout << "REPLACING DONE (changed nodes)!" << endl;
    printTreeInorder(root);
    cout << endl;
*/

// Replacing nodes by sum of their child nodes by NOT CHANGING LEAF NODES
    ReplaceBySumOfNodes2(root);
    cout << "REPLACING DONE (without change)!" << endl;
    printTreeInorder(root);
    cout << endl;

    return 0;
}