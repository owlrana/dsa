//  PRINTING THE RIGHT VIEW OF THE BINARY TREE

/*
    STRCUTURE FOR OUR FUNCTION OF RIGHT VIEW:
                1.  Check for root (if maxLevel < currentLevel) & print if new level
                2.  go to the right subtree
                3.  go to the left subtree
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


// printing the right view of our binary tree
// we dont need to make a copy of maxlevel as it needs to be shared...
void printRight (Node* root, int level, int &maxLevel)
{
    if (root == NULL)
    {
        return;
    }

    // check for root
    if (maxLevel < level)
    {
        // means that we have discovered a new level and stumbled upon the right most node of it
        cout << root->data << " ";
        maxLevel = level;
    }

    // got to RIGHT then LEFT
    printRight(root->right, level + 1, maxLevel);
    printRight(root->left, level + 1, maxLevel);

}


int main()
{
//  Building a tree from user input
    Node* root = buildTree();

//  Printing the right view
    int maxLevel = -1;
    printRight(root, 0, maxLevel);

    return 0;
}