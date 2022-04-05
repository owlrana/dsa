// Depth first search for Graphs

// traversing a graph neighbour by neighbour using a Queue

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

    // dfs function that initialises the visited map and calls helper function
    void dfs(T src)
    {
        map<T, bool> visited;

        // marks all the nodes as not visited in the beginning
        for (auto p: m)
        {
            T node = p.first;
            visited[node] = false;
        }

        // calls the helper function to print DFS
        dfs_helper(src, visited);
    }
};

int main()
{
    Graph<int> g;
    g.addElement(0, 1);
    g.addElement(0, 3);
    g.addElement(1, 2);
    g.addElement(3, 2);
    g.addElement(3, 4);
    g.addElement(4, 5);
    
    // output should be 0, 1, 2, 3, 4, 5 as DFS
    g.dfs(0);
    
}