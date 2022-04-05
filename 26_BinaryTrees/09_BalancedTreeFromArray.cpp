//  BALANCED TREE FROM ARRAY INPUT

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

// Balanced Tree from array input
Node* buildBalancedTree (int* arr, int start, int end)
{
    // base case
    if (start > end)
    {
        return NULL;
    }

    int mid = (start + end) / 2;
    Node* root = new Node(arr[mid]);

    root->left = buildBalancedTree(arr, start, mid - 1);
    root->right = buildBalancedTree(arr, mid+1, end);

    return root;
}

// bfs with new line character after every level of the tree
void bfsPrintWithLevels(Node* root)
{
    queue<Node*> myQ;
    myQ.push(root);
    myQ.push(NULL);
    
    while (not myQ.empty())
    {
        if (myQ.front() == NULL)
        {
            cout << endl; // print a new line immediately
            myQ.pop(); // push it out as this is done!
            
            if (not myQ.empty())
            {
                myQ.push(NULL); // only push it IF THE QUEUE IS NOT EMPTY OTHERWISE ENDLESS LOOP
            }
        }
        else // otherwise, do our normal BFS printing
        {
            if (myQ.front()->left != NULL)
            {
                myQ.push(myQ.front()->left);
            }

            if (myQ.front()->right != NULL)
            {
                myQ.push(myQ.front()->right);
            }
            
            cout << myQ.front()->data << "  ";

            myQ.pop();
        }
    }
}

int main()
{
//  Building a Balanced tree from user input of array
    int arr[ ] = {1,2,3,4,5,6,7};
    int size = 7;

    Node* root = buildBalancedTree(arr, 0, size-1);

//  Inorder, Preorder, Postorder Traversals

    cout << "Breadth First Traversal: " << endl;
    bfsPrintWithLevels(root);
    cout << endl;

    return 0;
}