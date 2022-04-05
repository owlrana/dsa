// IMPLEMENTATION OF GRAPHS BY ADJACENCY LIST (using doubly linked lists)
// assumes the graph is Bi-Directional

#include<iostream>
#include<list>
using namespace std;

class Graph
{
    int vertices; // the number of vertices
    list<int>* conList; // pointer to point to an array of connections list
    // not initialising list here as we do not know the size yet.

public:

    Graph(int V)
    {
        vertices = V;
        conList = new list<int> [vertices]; // new dynamic array
    }

    void addConnection(int x, int y)
    {
        conList[x].push_back(y);
        conList[y].push_back(x);
    }

    void printGraph()
    {
        // for all of the vertices (Array of conLists)
        for (int i = 0; i < vertices; i ++)
        {
            cout << "Vertex: " << i << " -> ";
            // iterate through the conList while printing the nodes
            for (int conn: conList[i])
            {
                cout << conn << ", ";
            }
            cout << endl;
        }
    }
};

int main()
{
    Graph g(4);

    g.addConnection(0, 1);
    g.addConnection(0, 2);
    g.addConnection(1, 2);
    g.addConnection(2, 3);

    g.printGraph();

    return 0;
}