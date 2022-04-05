// Undirected graph cycle detection using DFS only

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
        l[y].push_back(x);
    }

    // helper fn
    bool cycleHelper(int node, bool *visited, int parent)
    {
        visited[node] = true;

        for (auto nbr: l[node])
        {
            // two cases
            if (!visited[nbr])
            {
                bool cycle_mila = cycleHelper(nbr, visited, node);
                if (cycle_mila)
                {
                    return true;
                }
            }
            // else if the nbr is visited AND NOT THE PARENT...
            else if (nbr != parent)
            {
                return true;
            }
        }
        return false;
    }

    bool containsCycle ()
    {
        // check for cycle in directed graph
        bool *visited = new bool[V];
        for (int i = 0; i < V; i ++)
        {
            visited[i] = false;
        }

        // to find a cycle we do this
        return cycleHelper(0, visited, -1);
    
        // if however, we wanted to find MULTIPLE different cycles,
        // we would have run this in a loop of all nodes
    }
};

int main()
{
    Graph g(7);

    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    // g.addEdge(4, 0); // with this edge contains a cycle

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