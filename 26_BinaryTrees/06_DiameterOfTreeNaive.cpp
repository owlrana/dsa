// COMPUTING THE DIAMETER OF TREE USING HEIGHT AND RECURSION
// implementation to compute the diameter of tree in O(N^2) time complexity
// no. of edges is diameter NOT nodes!

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

// FINDING THE DIAMETER OF A TREE

// first computing the height of the tree
int findHeight (Node* root)
{
    if (root == NULL)
    {
        return 0;
    }

    int left = findHeight(root->left);
    int right = findHeight(root->right);

    return max(left, right) + 1;
}

// computing the diameter for tree
int findDiameter(Node* root)
{
    if (root == NULL)
    {
        return 0;
    }

    int op1 = findHeight(root->left) + findHeight(root->right);
    int op2 = findDiameter(root->left);
    int op3 = findDiameter(root->right);

    return max(op1, max(op2, op3));
}

int main()
{
//  Building a tree from user input

    Node* root = buildTree();

//  Inorder, Preorder, Postorder Traversals

    cout << "Inorder Traversal: ";
    printTreeInorder(root);
    cout << endl;

//  DIAMETER OF A TREE
    cout << findHeight(root) << endl;
    cout << findDiameter(root) << endl;

    return 0;
}