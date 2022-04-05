// Cycle detection in Undirected graph using DSU

#include<iostream>
#include<list>
using namespace std;

class Graph
{
    int V;
    list< pair< int, int> > l;

public:
    Graph (int V)
    {
        this->V = V;
    }

    void addEdge(int u, int v)
    {
        l.push_back(make_pair(u, v));
    }

    // finding the set a number belongs to 
    int findSet (int i, int parent[])
    {
        // base case
        if (parent[i] == -1)
        {
            return i;
        }

        return findSet(parent[i], parent);
    }

    // creating unions of two numbers given
    // union is a keyword in C++ and C so calling it makeUnion
    void makeUnion (int x, int y, int parent[])
    {
        int s1 = findSet(x, parent);
        int s2 = findSet(y, parent);

        if (s1 != s2)
        {
            parent[s1] = s2;
            // can also do parent[s2] = s1; // doesnt matter...
        }
    }

    // DSU logic to check if contains a cycle or not
    bool contains_cycle()
    {
        int *parent = new int[V];
        
        for (int i = 0; i < V; i ++)
        {
            parent[i] = -1;
        }

        // iterate over the edge list
        for (auto edge: l)
        {
            int i = edge.first;
            int j = edge.second;

            int s1 = findSet(i, parent);
            int s2 = findSet(j, parent);

            if (s1 != s2)
            {
                makeUnion(s1, s2, parent);
            }
            else
            {
                cout << "SAME PARENTS! " << s1 << ", " << s2 << endl;
                return true;
            }
        }
        delete [] parent;
        return false;
    }

};

int main()
{
    // indexing should start from 0
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 0);

    // SAME PARENTS! 3, 3

    cout << g.contains_cycle() << endl;

    return 0;
}
