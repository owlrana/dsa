//  CREATING A TREE FROM GIVEN PRE ORDER AND INORDER ARRAYS

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


// TREE FROM PRE-ORDER AND IN-ORDER ARRAYS
Node* buildTreeFromPreorderInorder (int* preorder, int* inorder, int start, int end)
{
    // we need a global variable or a static variable to keep track of PREORDER for order
    static int position = 0;

    // base case
    if (start > end)
    {
        return NULL;
    }

    Node* root = new Node(preorder[position]);

    // finding the position of current elememnt
    int index = -1;
    for (int i = start; i <= end; i++)
    {
        if (preorder[position] == inorder[i])
        {
            index = i;
            break;
        }
    }

    position++;

    // now recursively call the left and the right sides
    root->left = buildTreeFromPreorderInorder(preorder, inorder, start, index - 1);
    root->right = buildTreeFromPreorderInorder(preorder, inorder, index + 1, end);

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
    int inorder[] = {3, 2, 8, 4, 1, 6, 7, 5};
    int preorder[] = {1, 2, 3, 4, 8, 5, 6, 7};
    int size = sizeof(inorder)/sizeof(int);

    Node* root = buildTreeFromPreorderInorder(preorder, inorder, 0, size-1);

//  Inorder, Preorder, Postorder Traversals

    cout << "Breadth First Traversal: " << endl;
    bfsPrintWithLevels(root);
    // cout << endl;

    return 0;
}