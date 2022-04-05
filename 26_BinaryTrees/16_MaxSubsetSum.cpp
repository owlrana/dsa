// Find the largest sum of a subset of nodes in a binary tree such that
// if a node is included in the sum then its parent and children must not be included
// in the subset sum

// Complexity of our solution is O(N)

/*
    for this prorder input:
    1 2 4 -1 -1 5 7 -1 -1 -1 3 -1 6 -1 -1

    you should get the output as: 18
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

// helper pair class, we are not using inbuilt pair because it gets confusing
class Pair {
public:
    int included;
    int excluded;
};

// Working function
Pair maxSubsetSum (Node* root) {

    // Pair p will keep track for the current node
    Pair p;

    // base case if we hit the leaf node
    if (root == NULL) {
        p.included = 0;
        p.excluded = 0;

        return p;
    }

    // recursive condition to find out for left and right subtree
    Pair left = maxSubsetSum(root->left);
    Pair right = maxSubsetSum(root->right);

    // if p is included, then its data will be added BUT the data from its chidlren WONT
    p.included = root->data + left.excluded + right.excluded;

    // if p is excluded, we can either include its children or we can choose to exclude them
    // whatever helps us give the maximum result
    p.excluded = max(left.included, left.excluded) + max(right.included, right.excluded);

    return p;
}

int main()
{
//  Building a tree from user input

    Node* root = buildTree();

    cout << "Preorder Traversal: ";
    printTreePreorder(root);
    cout << endl;

    Pair p = maxSubsetSum (root);

    cout << max (p.included, p.excluded) << endl;

    return 0;
}