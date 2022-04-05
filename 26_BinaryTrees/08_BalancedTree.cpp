//  BALANCED TREE
//  Finding out if a tree is balanced or not

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

//  FINDING IF A TREE IS BALANCED OR NOT

// creating a new class just for better understanding & not calculating height each time
class HBPair
{
public:
    int height;
    bool balance;
};

// finding out if a tree is balanced or not using this function
HBPair isBalanced (Node* root)
{
    HBPair p;
    if (root == NULL)
    {   
        // null tree is always a balanced tree
        p.height = 0;
        p.balance = true;
        return p;
    }

    // recursive case
    HBPair left = isBalanced(root->left);
    HBPair right = isBalanced(root->right);

    // updating the height
    p.height = max(left.height, right.height) + 1; // compute the ehight if this current tree

    // updating balance
    if (abs(left.height - right.height) <= 1 and left.balance and right.balance)
    {
        p.balance = true;
    }
    else
    {
        p.balance = false;
    }

    return p;
}

int main()
{
//  Building a tree from user input

    Node* root = buildTree();

//  Inorder, Preorder, Postorder Traversals

    cout << "Inorder Traversal: ";
    printTreeInorder(root);
    cout << endl;

//  FINDING OUT IF A TREE IS BALANCED OR NOT

    // should output NOT Balanced (0) for 8 10 1 -1 -1 6 9 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1
    cout << isBalanced(root).balance;

    return 0;
}