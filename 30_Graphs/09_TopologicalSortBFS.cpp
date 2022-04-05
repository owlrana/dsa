// Topological Sort (Dependencies etc.) using BFS 

#include<iostream>
#include<list>
#include<queue>
#include<map>
using namespace std;

template<class T>
class Graph
{
    list <int> *l;
    int V;

public:
    Graph(int V)
    {
        this->V = V;
        l = new list <int> [V];
    }

    void addEdge(int x, int y)
    {
        // push directed graph
        l[x].push_back(y);
    }

    void topologicalSort()
    {
        // indegree
        int *indegree = new int [V];
        for (int i = 0; i < V; i++)
        {
            indegree[i] = 0;
        }

        // update indegree by traversing edges from x -> y
        // indegree[y] ++

        for (int i = 0; i < V; i ++)
        {
            for (auto y: l[i])
            {
                indegree[y] += 1; // the edge to which we are going being inc
            }
        }

        // apply BFS,
        queue<int> q;
        // 1. find nodes with 0 indegree
        for (int i = 0; i < V; i ++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }

        // start removing elements from the queue
        while (!q.empty())
        {
            int node = q.front();

            cout << node << " ";

            q.pop();

            // iterate over the nbrs of that node and reduce their indegree
            for (auto nbr: l[node])
            {
                indegree[nbr] -= 1;
                if (indegree[nbr] == 0)
                {
                    q.push(nbr);
                }
            }
        }
    }
};

int main()
{
    Graph<int> g(6);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(2, 5);
    g.addEdge(3, 5);
    g.addEdge(4, 5);

    g.topologicalSort();
    // output should be: 0 1 4 2 3 5

    return 0;
}