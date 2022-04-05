// IMPLEMENTING GRAPHS OF CUSTOM CLASS INPUTS BY ADJACENCY LIST (using Hashmaps)

#include<iostream>
#include<unordered_map>
#include<list>
using namespace std;

class Graph
{
    unordered_map< string, list< pair<string, int> > > m;

public:

    void addConnection (string from, string to, int weight, bool bidir)
    {
        m[from].push_back(make_pair(to, weight));
        // also check if the node's connected to both sides (bidirectional)
        if (bidir)
        {
            m[to].push_back(make_pair(from, weight));
        }
    }

    void printGraph ()
    {
        // traverse through the unordered_map of lists
        for (auto item: m)
        {
            // noq, this item is a pair of map, containing string and list
            // item.first is of the STRING type
            cout << "Country: " << item.first << " -> ";

            // item.second is of the LIST type
            // we need to traverse all nodes in this list to get all vertices
            for (auto node: item.second)
            {
                // node.first is of the STRING type
                // node.second is of the INT type
                cout << "(" << node.first << " - " << node.second << ")" << ", ";
            }
            cout << endl;
        }
    }
};

int main()
{
    Graph g;

    g.addConnection("A", "B", 20, true);
    g.addConnection("A", "C", 10, true);
    g.addConnection("A", "D", 50, false);
    g.addConnection("B", "D", 40, true);
    g.addConnection("C", "D", 30, true);
    
    g.printGraph();
    
    return 0;
}