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

    // given any source node, print the BFS from there
    void printBFS(T source)
    {
        map<T, bool> visited;
        queue<T> q;

        // push the first element inside and mark it as visited
        q.push(source);
        visited[source] = true;

        // need to do this while the queue is not empty
        while (!q.empty())
        {
            T node = q.front();
            q.pop();

            cout << node << " ";

            for (auto element: m[node])
            {
                if (!visited[element])
                {
                    // push that element inside the queue
                    q.push(element);
                    // now mark it as visited to you dont push it again in future
                    visited[element] = true;
                }
            }
        }
    }

    // find the shortest path in non weighted graph
    void shortestPath(T source)
    {
        map<T, int> dist;
        queue<T> q;

        // all nodes should have infinity distance
        // for all the node_pairs inside our graph m
        for (auto node_pair: m)
        {
            T node = node_pair.first;
            // distance of each node is INT_MAX
            dist[node] = INT_MAX;
        }

        // push the first element inside and mark it as by giving distance
        q.push(source);
        dist[source] = 0;

        // need to do this while the queue is not empty
        while (!q.empty())
        {
            T node = q.front();
            q.pop();

            // no need to print all traversal
            //cout << node << " ";

            for (auto nbr: m[node])
            {
                if (dist[nbr] == INT_MAX)
                {
                    // push that neighbouring element inside the queue
                    q.push(nbr);
                    // also assign it it's correct distance!!
                    dist[nbr] = dist[node] + 1;
                }
            }
        }

        for (auto node_pair: m)
        {
            T node = node_pair.first;
            int d = dist[node];
            cout << "Node " << node << " distance from source: " << d;
            cout << endl;
        }
    }
};

int main()
{
    Graph<int> g;
    g.addElement(1, 2);
    g.addElement(1, 3);
    g.addElement(1, 4);
    g.addElement(1, 5);
    g.addElement(2, 6);
    g.addElement(2, 7);
    g.addElement(3, 8);
    g.addElement(3, 9);
    
    g.shortestPath(1);
    
    return 0;
}