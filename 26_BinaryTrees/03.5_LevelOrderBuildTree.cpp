// Building a tree whose level order is given as input
// implementation using a QUEUE in O(n) time complexity

/*
    INPUT:
    1 2 3 -1 -1 4 -1 -1 -1

    OUTPUT:
    1
    2 3
    4

    INPUT:
    1 2 3 4 5 -1 6 -1 -1 7 -1 -1 -1 -1 -1
    
    OUTPUT:
    1  
    2  3  
    4  5  6  
    7 
*/

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

// Building a tree using level order as input
Node* levelOrderBuild () {

    int data;
    cin >> data;

    Node* root = new Node(data);

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* curr = q.front();
        q.pop();

        int child1, child2;

        cin >> child1 >> child2;

        if (child1 != -1) {
            curr->left = new Node(child1);
            q.push(curr->left);
        }

        if (child2 != -1) {
            curr->right = new Node(child2);
            q.push(curr->right);
        }
    }

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
//  Building a tree from user input

    Node* root = levelOrderBuild();

// BFS with hierarchy (new line after every level of tree)
    bfsPrintWithLevels(root);

    return 0;
}