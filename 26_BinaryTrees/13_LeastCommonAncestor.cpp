// FINDING OUT THE LOWEST COMMON ANCESTOR OF A GIVEN TREE AND TWO NODES

// ---------- Assumptions ----------
// 1. both A & B given nodes are present inside the tree for sure.
// 2. all values inside the tree are UNIQUE.

// run for input tree: 1 2 4 6 -1 -1 7 10 -1 -1 11 -1 -1 5 8 -1 -1 9 -1 -1 3 -1 -1
// output should be: 2

#include<iostream>
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
        cout << -1 << " ";
        return;
    }

    // otherwise, print the root, and then print the subtrees
    cout << root->data << "  ";
    printTreeInorder(root->left);
    printTreeInorder(root->right);
}

//  FINDING LCA
Node* findLCA (Node* root, int a, int b)
{
    if (root == NULL)
    {
        return NULL;
    }

    if (root->data == a or root->data == b)
    {
        return root;
    }

    Node* leftAns = findLCA(root->left, a, b);
    Node* rightAns = findLCA(root->right, a , b);

    if (leftAns != NULL and rightAns != NULL)
    {
        return root;
    }

    if (leftAns != NULL)
    {
        return leftAns;
    }

    return rightAns;
}

int main()
{
//  Building a tree from user input

    Node* root = buildTree();
    
//  Finding LCA 

    int a = 7, b = 9;

    Node* answer = findLCA(root, a, b);
    cout << answer->data << endl;

    return 0;
}