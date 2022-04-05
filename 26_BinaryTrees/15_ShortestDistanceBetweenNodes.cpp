// FINDING SHORTEST DISTANCE BETWEEN TWO GIVEN NODES

// ---------- Assumptions ----------
// All elements are unique inside the tree

// OUTPUT
// for the input: 1 2 4 6 -1 -1 7 10 -1 -1 11 -1 -1 5 8 -1 -1 9 -1 -1 3 -1 -1
// output should be: 4

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

// FINDING SHORTEST PATH BETWEEN THE NODES

// finding the level of given node from any node
int search (Node* root, int key, int level)
{
    if (root == NULL)
    {
        return -1;
    }

    if (root->data == key)
    {
        return level;
    }

    int left = search(root->left, key, level + 1);

    if (left != -1)
    {
        return left;
    }

    return search(root->right, key, level + 1);
}

// we also require the lca fucntion to calculate the distance as from LCA we will find the levels
Node* lca(Node* root, int a, int b)
{
    if (root == NULL)
    {
        return NULL;
    }

    if (root->data == a or root->data == b)
    {
        return root;
    }

    Node* leftAns = lca(root->left, a, b);
    Node* rightAns = lca(root->right, a , b);

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

// function to find the distance
int findDistance (Node* root, int a, int b)
{
    Node* lca_node = lca(root, a, b);

    int l1 = search(lca_node, a, 0); // zero is the starting level that we have to input
    int l2 = search(lca_node, b, 0);

    return l1 + l2;
}

int main()
{
//  Building a tree from user input

    Node* root = buildTree();
    
//  FINDING THE SHORTEST PATH BETWEEN TWO NODES

    cout << findDistance(root, 7, 8) << endl;

    return 0;
}