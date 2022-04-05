// This function finds out the height of a Binary Tree
// Time complexity is O(N)

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

// finding the height of this tree
int findHeight (Node* root) {

    if (root == NULL) {
        return 0;
    }

    int leftHeight = findHeight(root->left);
    int rightHeight = findHeight(root->right);

    return 1 + max(leftHeight, rightHeight);
}

int main()
{
//  Building a tree from user input

    Node* root = buildTree();

    cout << "Preorder Traversal: ";
    printTreePreorder(root);
    cout << endl;

    cout << "Height of the tree is: ";
    findHeight(root);
    cout << endl;

    return 0;
}