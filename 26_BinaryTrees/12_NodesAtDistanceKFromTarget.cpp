// NODES AT DISTANCE K FROM A GIVEN TARGET NODE

// THIS SOLUTION IS VERIFIED FROM LEETCODE, DO NOT CHANGE ANYTHING!!!
// https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/submissions/

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

//  Just a utility function to print a level (done earlier)
void printLevel(Node* root, int level)
{
    if (root == NULL)
    {
        return;
    }
    
    if (level == 0)
    {
        cout << root->data << " ";
        return;
    }

    printLevel(root->left, level-1);
    printLevel(root->right, level-1);

    return;
}

//  PRINTING NODES AT K DISTANCE FROM THE TARGET NODE
int printNodesAtDistanceK(Node* root, Node* target, int k)
{
    // base case if target node is not present
    if (root == NULL)
    {
        return -1;
    }

    // when we reach the target node there are 2 things to do:
    // 1. find out the nodes at distance K INSIDE the subtree of this target node
    // 2. find out the nodes at distance K OUTSIDE this target node
    if (root == target)
    {
        printLevel(target, k);
        return 0; // distance of this node from target node will be 0 as IT IS the target node
        // this wil be used while we are coming down in call stack from recursion
        // to identify that we just hit the target node in previous call!
    }

    // next step is to know the ancestors to look outside this node
    int DL = printNodesAtDistanceK(root->left, target, k);

    if (DL != -1)
    {
        // again 2 cases
        // 1. it is the ancestor itself which is at K distance away from this target node
        // 2. the node lies in the subtree of the ancestor (always in the right subtree in this case)
        
        if (DL + 1 == k)
        {
            cout << root->data << " ";
        }
        else
        {
            printLevel(root->right, k - DL - 2); // passing new effective level for this node
            // doing "- DL" because this is the number of nodes we are ABOVE the target node
            // doing "- 2" because while going from this node to its right subtree we're 
            // essentially bypassing 2 edges, so those need to be counted for   
        }

        return DL + 1; // when we come out of this node, we are moving another step up from target
    }

    // similar almost mirror step needs to be taken for the right subtrees
    int DR = printNodesAtDistanceK(root->right, target, k);

    if (DR != -1)
    {
        if (DR + 1 == k)
        {
            cout << root->data << " ";
        }
        else
        {
            printLevel(root->left, k - DR -2);
        }

        return DR + 1;
    }

    // if the node was not present in the right/left subtree just return -1 in the end as well
    return -1;
}

int main()
{
//  Building a tree from user input

    Node* root = buildTree();
    printTreeInorder(root);
    cout << endl;
    Node* target = root->left->left; // this is the target node
    cout << target->data << endl;
    int K = 0; // this is the distance from the target node

//  Printing nodes at K level from the target node
    printNodesAtDistanceK(root, target, K);

    return 0;
}