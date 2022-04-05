// COMPUTING THE DIAMETER OF TREE (BOTTOM UP APPROACH BY STORING HEIGHT)
// implementation to compute diameter in O(n) time complexity

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

// FINDING THE DIAMETER OF A TREE BY OPTIMISED APPROACH (STORING HEIGHTS)
class Pair 
{
public:
    int height;
    int diameter;
};

Pair findDiameter (Node* root)
{
    Pair p;

    // return if base case reached (values initialised)
    if (root == NULL)
    {
        p.diameter = p.height = 0;
        return p;
    }
    // otherwise build on the base values now

    Pair left = findDiameter(root->left);
    Pair right = findDiameter(root->right);

    p.height = max(left.height, right.height) + 1;
    p.diameter = max(left.height + right.height, max(left.diameter, right.diameter));

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

//  DIAMETER OF A TREE
    Pair answer = findDiameter(root);
    cout << "Diameter: " << answer.diameter << endl;
    cout << "Height: " << answer.height << endl;
    
    return 0;
}