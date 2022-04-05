// FINDING OPTIMAL PATH THAT RESULTS IN THE MAXIMUM SUM

// input should be: 1 2 4 6 -1 -1 7 10 -1 -1 11 -1 -1 5 8 -1 -1 9 -1 -1 3 -1 -1
// output is: 38

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

// FINDING OPTIMAL PATH FOR MAX SUM

class Pair
{
public:
    int branchSum;
    int maxSum;

    Pair ()
    {
        branchSum = 0;
        maxSum = 0;
    }
};

Pair maxSumPath (Node* root)
{
    Pair p;

    if (root == NULL)
    {
        return p;
    }

    Pair left = maxSumPath(root->left);
    Pair right = maxSumPath(root->right);

    // construct options
    int option1 = root->data;
    int option2 = left.branchSum + root->data;
    int option3 = right.branchSum + root->data;
    int option4 = left.branchSum + right.branchSum + root->data;

    int current_ans_through_root = max(option1, max(option2, max(option3, option4)));

    // branch sum for the current root node
    p.branchSum = max(left.branchSum, max(right.branchSum, 0)) + root->data;
    p.maxSum = max(left.maxSum, max(right.maxSum, current_ans_through_root));

    return p;
}


int main()
{
//  Building a tree from user input

    Node* root = buildTree();
    
//  FINDING OPTIMAL PATH FOR THE MAX SUM 
    Pair answer = maxSumPath(root);
    cout << answer.maxSum << endl;

    return 0;
}