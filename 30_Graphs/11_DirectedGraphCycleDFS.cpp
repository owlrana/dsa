// Detecting cycle in a Directed Graph using Depth First Search

#include<iostream>
#include<list>
#include<queue>
#include<map>
using namespace std;

// Graphs class that accepts custom class T nodes
class Graph
{
    list<int> *l;
    int V;

public:
    Graph(int V)
    {
        this->V = V;
        l = new list<int> [V];
    }
    void addEdge(int x, int y)
    {
        l[x].push_back(y);
    }

    // helper fn
    bool cycleHelper(int node, bool *visited, bool *stack)
    {
        // mark this node as visited
        visited[node] = true;
        // this node also becomes part of current path
        stack[node] = true;

        // check if that node contains a cycle or leads to a cycle...
        for (int nbr: l[node])
        {
            // two cases
            // 1. if you find a neighbour in the call stack
            if (stack[nbr] == true)
            {
                // this is a case of back edge, it leads to direct cycle
                return true;
            }
            // 2. the subsequent nodes may contain the cycle so check for that
            else if (visited[nbr] == false) // only if neighbour is not already visited then you make the call
            {
                bool cycle_mila = cycleHelper(nbr, visited, stack); // subseqnt cycles
                if (cycle_mila == true)
                {
                    return true;
                }
            }
        }

        // while leaving, this is visited but no longer part of the stack
        stack[node] = false;
        return false;

    }

    bool containsCycle ()
    {
        // Check for cycle in directed graph
        bool *visited = new bool[V];
        bool *stack = new bool[V]; // stack named but array to get O(1) access time

        for (int i = 0; i < V; i ++)
        {
            visited[i] = stack[i] = false;
        }
        
        return cycleHelper(0, visited, stack);
    }

};

int main()
{
    Graph g(7);

    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 5);
    g.addEdge(1, 5);
    g.addEdge(5, 6);
    g.addEdge(4, 2); // back edge, should be positive with this

    if (g.containsCycle())
    {
        cout << "Oh bette cycle mil gya" << endl;
    }
    else
    {
        cout << "Nope, no cycle around here" << endl;
    }

    return 0;
}