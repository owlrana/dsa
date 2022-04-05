// Topological Sort (Dependencies etc.) using DFS 

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
        // directed edge only
        // m[y].push_back(x); 
    }

    // recursive helper function to traverse the DFS recursively
    // visited map should be passed by reference otherwise we wont be able
    // to track which nodes are visited...
    // ordering should also be passed by reference
    void dfs_helper(T src, map<T, bool> &visited, list<T> &ordering)
    {
        // recursive function that will traverse through the graph
        // cout << src << " ";
        visited[src] = true;

        // go to all neighbours of that node that is not visited
        for (T nbr: m[src])
        {
            if (!visited[nbr])
            {
                dfs_helper(nbr, visited, ordering);
            }
        }

        ordering.push_front(src);
        return;
    }

    // topological sorting
    void topoSortDFS()
    {
        map<T, bool> visited;

        // to store the ordering of our topological sorted elements
        list<T> ordering;

        // marks all the nodes as not visited in the beginning
        for (auto p: m)
        {
            T node = p.first;
            visited[node] = false;
        }

        // calling the DFS helper function for EVERY node
        for (auto p: m)
        {
            T node = p.first;
            if (!visited[node])
            {
                dfs_helper(node, visited, ordering);
            }
        }

        // finally either return the list or print the list
        for (auto node: ordering)
        {
            cout << node << endl;
        }

    }
};

int main()
{
    Graph<string> g;
    g.addElement("Python", "DataPreprocessing");
    g.addElement("Python", "Pytorch");
    g.addElement("Python", "ML");
    g.addElement("DataPreprocessing", "ML");
    g.addElement("Pytorch", "DL");
    g.addElement("ML", "DL");
    g.addElement("DL", "FaceRecognition");
    g.addElement("DataSet", "FaceRecognition");

    g.topoSortDFS();
/*
    OUTPUT SHOULD BE: 

    Python
    Pytorch
    DataSet
    DataPreprocessing
    ML
    DL
    FaceRecognition
*/
}