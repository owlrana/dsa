// Counting the number of nodes in a tree

/*
This is the tree that we are building:
by the input: 3 4 -1 6 -1 -1 5 1 -1 -1 -1
Preorder: 4 6 3 1 5

            3
          /   \
        4      5
         \     /
          6   1

*/

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

// for the input:
// 3 4 -1 6 -1 -1 5 1 -1 -1 -1
// Inorder output should be: 3, 4, 6, 5, 1, 

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

// printing a tree (this is INORDER TRAVERSAL)
void printTreeInorder( Node* root)
{
    if (root == NULL)
    {
        return;
    }

    // otherwise, print the root, and then print the subtrees
    printTreeInorder(root->left);
    cout << root->data << "  ";
    printTreeInorder(root->right);
}

int countNodes (Node* root)
{
    if (root == NULL)
    {
        return 0;
    }

    int nodes = 0;

    nodes += countNodes(root->left);
    nodes += countNodes(root->right);

    return nodes + 1;
}

int main()
{
//  Building a tree from user input

    Node* root = buildTree();

//  Inorder, Preorder, Postorder Traversals

    cout << "Inorder Traversal: ";
    printTreeInorder(root);
    cout << endl;

//  Counting the number of nodes in a tree
    cout << countNodes(root) << endl;

    return 0;
}