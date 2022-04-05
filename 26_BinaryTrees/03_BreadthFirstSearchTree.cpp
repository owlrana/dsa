// Breadth First Traversal of a tree
// implementation using a QUEUE in O(n) time complexity

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

// BREADTH FIRST TRAVERSAL OF TREE (iterative approach to Level Order Printing)
void bfsPrint(Node* root)
{
    queue<Node*> myQ;
    myQ.push(root);

    while (not myQ.empty())
    {
        // making sure that the child element exists
        if (myQ.front()->left != NULL)
        {
            // you could have also done Node* temp = myQ.front() and then used temp->left etc.
            myQ.push(myQ.front()->left);
        }

        // making sure that the child element exists
        if (myQ.front()->right != NULL)
        {
            myQ.push(myQ.front()->right);
        }

        // printing out the FRONT element before popping it out
        cout << myQ.front()->data << "  ";
        myQ.pop();
    }
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
//  Building a tree from user input

    Node* root = buildTree();

//  Inorder, Preorder, Postorder Traversals

    cout << "Inorder Traversal: ";
    printTreeInorder(root);
    cout << endl;

//  Breadth First Traversal of a Tree
    bfsPrint(root);
    cout << endl;

// BFS with hierarchy (new line after every level of tree)
    bfsPrintWithLevels(root);

    return 0;
}