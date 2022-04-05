// printing the vertical order of a binary tree, imagined in vertical lines

/*
OUTPUT OF THIS PROGRAM SHOULD BE AS FOLLOWS

-2 -> 4, 
-1 -> 2, 
0 -> 1, 5, 6, 
1 -> 8, 3, 
2 -> 7, 
3 -> 9, 

*/

#include<iostream>
#include<map>
#include<vector>
using namespace std;

class node 
{
public:
    int data;
    node* left;
    node* right;

    node (int d)
    {
        data = d;
        left = right = NULL;
    }
};

// by default STL containers are passed by value. Their copies are made...
// we dont want that
void verticalOrderPrint(node* root, int d, map<int,vector<int> > &m)
{
    //base case
    if (root == NULL)
    {
        return;
    }

    //otherwise
    m[d].push_back(root->data);
    verticalOrderPrint(root->left, d-1, m);
    verticalOrderPrint(root->right, d+1, m);
    return;
}

int main()
{
//  IGNORE BUILDING TREE
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);

    root->right->left = new node(6);
    root->right->right = new node(7);

    root->right->right->right = new node(9);
    root->left->right->right = new node(8);

    // store the keys and nodes inside the map (in sorted manner as map STL)
    map<int, vector<int> > m;
    int d = 0;
    verticalOrderPrint(root, d, m);

    // now our map must be containing all the keys
    for (auto p: m)
    {
        // p is a node, and each node has 2 things: integer and the vector
        cout << p.first << " -> ";
        for (auto x: p.second)
        {
            cout << x << ", ";
        }
        cout << endl;
    }

    return 0;
}