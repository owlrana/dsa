// Snakes and Ladder Game
// prints out the shortest distance from a source to destination in board
// distance of infinite (INT_MAX) means that a number is unreachable...

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
        // we need a directional graph here
        m[x].push_back(y);
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
    T shortestPath(T source, T dest)
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

        //  instead of returning distance to each node we just return
        //  the distance of the given destination node from source
        return dist[dest];
    }
};

int main()
{

    // input (TAKING HARDCODED FOR NOW AS LARGE)
    // assuming all boxes have zero jumps
    int board[50] = {0};
    
    // snakes and ladders
    board[2] = 13;
    board[5] = 2;
    board[9] = 18;
    board[18] = 11;
    board[17] = -13;
    board[20] = -14;
    board[24] = -8;
    board[25] = 10;
    board[32] = -2;
    board[34] = -22;

    // add edges to the graph
    Graph<int> g;
    for (int i = 0; i <= 36; i ++)
    {
        for (int dice = 1; dice <= 6; dice ++)
        {
            int j = i + dice;
            j += board[j];

            // as in this case we ONLY have 36 as the end!
            if (j <= 36)
            {
                g.addElement(i,j);
            }
        }
    }
    // our graph does not have an edge from 36. It NEEDS to know 36 is present
    g.addElement(36, 36);

    // printing the shortest path!
    cout << g.shortestPath(0, 36); // output should be 4 for input: 0, 36 

    return 0;
}