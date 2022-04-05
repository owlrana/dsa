// Weighted Graph's Shortest path using Dijkstra's Algorithm

// Dijkstra is useful but its EXACT version is not used in sat nav
// due to its shortcomings. It has no idea about direction.
// Single traffic jam can make you go nuts...

// Single Source Shortest Path type of algorithm

// NO NEGATIVE WEIGHTS CAN BE USED

#include<iostream>
#include<map>
#include<unordered_map>
#include<set>
#include<list>
#include<vector>
using namespace std;

template<typename T>
class Graph
{
    unordered_map<T, list<pair <T, int> > > m;;

public:
    void addEdge (T u, T v, int dist, bool bidir = true)
    {
        m[u].push_back(make_pair(v, dist));
        if (bidir)
        {
            m[v].push_back(make_pair(u, dist));
        }
    }

    void printAdj ()
    {
        // lets try to print the adj list
        // iterate over al the key value pairs in the map
        for (auto j: m)
        {
            cout << j.first << " -> ";

            // iterate over the list of the cities
            for (auto l: j.second)
            {
                // l.first will give you the city name
                // l.second will give you the city weight (Distance)
                cout << "(" << l.first << ", " << l.second << ")";
            }
            cout << endl;
        }
    }

    // Logic for Dijkstra's Algorithm
    void dijkstraSSSP (T src)
    {
        // we need to maintain the distance map (which is default as INFINITY for all other than src node)
        unordered_map<T, int> dist;

        // setting all to INFINITY
        for (auto j: m)
        {
            dist[j.first] = INT_MAX;
        }

        // make a set to find out the node with minimum distance
        set< pair<int, T> > s; // set sorts acc to the first parameter by default, so inserting dist first
        
        dist[src] = 0;

        // pushing the source node in with distance of 0
        s.insert(make_pair(0, src));

        while (!s.empty())
        {
            // Find the pair at the front
            auto p = *(s.begin()); // the first element of the set (the minimum distance)

            T node = p.second;

            int nodeDist = p.first; // the distance of this node is finalised so we need to erase this one
            s.erase(s.begin());

            // iterate over the neighbours/children of the current node
            for (auto childPair: m[node])
            {
                // if parents dist + weight is less than the current dist, update it
                if (nodeDist + childPair.second < dist[childPair.first])
                {
                    // in set, updation of a node is not possible so we need to update by deletion/insertion
                    // first searching for the old pair
                    T dest = childPair.first;
                    auto f = s.find(make_pair(dist[dest], dest));
                    
                    // if iterator is not pointing to the end of the node that means its found
                    if ( f != s.end())
                    {
                        s.erase(f);
                    }

                    // insert the new pair now
                    dist[dest] = nodeDist + childPair.second;
                    s.insert(make_pair(dist[dest], dest));
                }
            }
        }

        // lets print dist to all other nodes from the source
        for (auto d: dist)
        {
            cout << d.first << " is located at a distance of " << d.second << endl; 
        }
    }
};

int main()
{

    Graph<int> g;
    g.addEdge(1,2,1);
    g.addEdge(1,3,4);
    g.addEdge(2,3,1);
    g.addEdge(3,4,2);
    g.addEdge(1,4,7);
    g.printAdj();
    cout << endl;
    g.dijkstraSSSP(1);

/*
CORRECT OUTPUT SHOULD BE:

4 -> (3, 2)(1, 7)
3 -> (1, 4)(2, 1)(4, 2)
2 -> (1, 1)(3, 1)
1 -> (2, 1)(3, 4)(4, 7)
1 is located at a distance of 0
2 is located at a distance of 1
3 is located at a distance of 2
4 is located at a distance of 4

*/
    cout << endl << endl;


    Graph<string> india;
    india.addEdge("Amritsar", "Delhi", 1);
    india.addEdge("Amritsar", "Jaipur", 4);
    india.addEdge("Jaipur", "Delhi", 2);
    india.addEdge("Jaipur", "Mumbai", 8);
    india.addEdge("Bhopal", "Agra", 2);
    india.addEdge("Mumbai", "Bhopal", 3);
    india.addEdge("Agra", "Delhi", 1);
    india.printAdj();
    cout << endl;
    india.dijkstraSSSP("Amritsar");

/*
CORRECT OUTPUT SHOULD BE:

Agra -> (Bhopal, 2)(Delhi, 1)
Bhopal -> (Agra, 2)(Mumbai, 3)
Delhi -> (Amritsar, 1)(Jaipur, 2)(Agra, 1)
Mumbai -> (Jaipur, 8)(Bhopal, 3)
Jaipur -> (Amritsar, 4)(Delhi, 2)(Mumbai, 8)
Amritsar -> (Delhi, 1)(Jaipur, 4)

Amritsar is located at a distance of 0
Delhi is located at a distance of 1
Mumbai is located at a distance of 7
Bhopal is located at a distance of 4
Jaipur is located at a distance of 3
Agra is located at a distance of 2

*/

    return 0;
}