// building a tree, traversing a tree
// Preorder, Inorder, Postorder traversals

/*
This is the tree that we are building:
by the input: 3 4 -1 6 -1 -1 5 1 -1 -1 -1
Inorder: 4 6 3 1 5

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

// printing by PREORDER TRAVERSAL
void printTreePreorder(Node* root)
{
    if (root == NULL)
    {
        return;
    }

    // otherwise call the left first, then print root, then go to print right
    cout << root->data << "  ";
    printTreePreorder(root->left);
    printTreePreorder(root->right);
}

// printing by POSTORDER TRAVERSAL
void printTreePostorder(Node* root)
{
    if (root == NULL)
    {
        return;
    }

    // otherwise print Left first, then right, and in the end the root node
    printTreePostorder(root->left);
    printTreePostorder(root->right);
    cout << root->data << "  ";
}

int main()
{
//  Building a tree from user input

    Node* root = buildTree();

//  Inorder, Preorder, Postorder Traversals

    cout << "Inorder Traversal: ";
    printTreeInorder(root);
    cout << endl;

    cout << "Preorder Traversal: ";
    printTreePreorder(root);
    cout << endl;

    cout << "Postorder Traversal: ";
    printTreePostorder(root);
    cout << endl;

    return 0;
}