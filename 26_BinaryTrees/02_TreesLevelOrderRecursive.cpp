// Level order print of a tree using recursive approach
// Implementation using height finding and recursion in O(n^2) time

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
        return;
    }

    // otherwise, print the root, and then print the subtrees
    cout << root->data << "  ";
    printTreeInorder(root->left);
    printTreeInorder(root->right);
}

// LEVEL ORDER PRINTING USING RECURSIVE APPROACH

// part 1 - finding the height of a tree first
int findHeight(Node* root)
{
    if (root == NULL)
    {
        return 0;
    }

    // recursively find for left and the right subroots
    int leftDepth = findHeight(root->left);
    int rightDepth = findHeight(root->right);

    // the height/depth depends upon the deepest root thats holding it
    return max(leftDepth, rightDepth) + 1;
}

// part 2 - printing the level
void printLevel(Node* root, int level)
{
    // if found that a given level does not exist, get out
    if (root == NULL)
    {
        return;
    }

    // because when we reach the number 1, thats when we would have covered 4 levels
    // if we go to 0, then we would have k + 1 levels,,,,, not what we need....
    if (level == 1)
    {
        cout << root->data << " ";
        return;
    }

    printLevel(root->left, level-1);
    printLevel(root->right, level-1);

    return;
}

int main()
{
//  Building a tree from user input

    Node* root = buildTree();

//  Inorder, Preorder, Postorder Traversals

    cout << "Inorder Traversal: ";
    printTreeInorder(root);
    cout << endl;

//  Level order printing of tree

    // finding the height of the tree
    cout << findHeight(root) << endl;

    // printing a single level of tree
    int level = 3;
    printLevel(root, level);

    // to print all levels, just find out the height of tree and create
    // a loop from level 1 to EQUAL TO height
    for (int i = 0; i <= findHeight(root); i ++)
    {
        printLevel(root, i);
        cout << endl;
    }

    return 0;
}