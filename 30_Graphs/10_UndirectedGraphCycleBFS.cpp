// detecting cycle in a undirected graph (and thus if its a tree or not)

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

    bool is_tree()
    {
        bool *visited = new bool[V];
        int *parent = new int[V];

        queue<int> q;

        // no node is visited, each node has itself as parents
        for (int i = 0; i < V; i ++)
        {
            visited[i] = false;
            parent[i] = i;
        }

        // now doing BFS
        int src = 0;
        q.push(src);
        visited[src] = true;

        // pop out one node and visit its nbrs
        while (!q.empty())
        {
            int node = q.front();
            q.pop();

            for (int nbr: l[node])
            {
                // current parent of that node should not be the neighbour
                if (visited[nbr] == true and parent[node] != nbr)
                {
                    return false;
                }
                else if (!visited[nbr])
                {
                    // if not visited then we can visit that node
                    visited[nbr] = true;
                    parent[nbr] = node;
                    q.push(nbr);
                }
            }
        }
        // if false is not returned from any node thus far, then its not cyclic 
        return true;
    }
};

int main()
{
    Graph g(4);

    g.addEdge(0, 1);
    g.addEdge(3, 2);
    g.addEdge(1, 2);
    //g.addEdge(0, 3); // it should be a tree with this statement COMMENTED

    if (g.is_tree())
    {
        cout << "DAMN THATS A TREE YO" << endl;
    }
    else
    {
        cout << "nah, not a tree... not this one dawg" << endl;
    }

    return 0;
}