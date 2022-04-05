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
    
    g.printBFS(0);
    // should print 0 1 3 2 4 5
    
    return 0;
}