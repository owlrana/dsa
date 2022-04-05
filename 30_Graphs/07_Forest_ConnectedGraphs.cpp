// Traversing all nodes in a graph, even with non connected edges

#include<iostream>
#include<list>
#include<queue>
#include<map> // can also use unordered_map. map is just shorter text.
using namespace std;

// Graphs class that accepts custom class T nodes
template<class T>
class Graph
{
    map<T, list<T> > m;

public:

    void addElement (T x, T y)
    {
        // assuming a bidirectional graph
        m[x].push_back(y);
        m[y].push_back(x); 
    }

    // recursive helper function to traverse the DFS recursively
    // visited map should be passed by reference otherwise we wont be able
    // to track which nodes are visited...
    void dfs_helper(T src, map<T, bool> &visited)
    {
        // recursive function that will traverse through the graph
        cout << src << " ";
        visited[src] = true;

        // go to all neighbours of that node that is not visited
        for (T nbr: m[src])
        {
            if (!visited[nbr])
            {
                dfs_helper(nbr, visited);
            }
        }
    }

    // traversing all nodes connected or not
    void dfsForest()
    {
        map<T, bool> visited;

        // marks all the nodes as not visited in the beginning
        for (auto p: m)
        {
            T node = p.first;
            visited[node] = false;
        }

        // iterate over all the vertices and init a dfs call
        int cnt = 0; // to count the number of different components
        for (auto p: m)
        {
            T node = p.first;

            if (!visited[node])
            {
                cout << "Component " << cnt << " --> ";
                dfs_helper(node, visited);
                cnt ++;
                cout << endl;
            }
        }
    }
};

int main()
{
    Graph<int> g;
    g.addElement(0, 1);
    g.addElement(1, 2);
    g.addElement(2, 3);
    g.addElement(0, 3);
    g.addElement(0, 4);

    g.addElement(5, 6);
    g.addElement(6, 7);

    g.addElement(8, 8);
    
    g.dfsForest();
    
}