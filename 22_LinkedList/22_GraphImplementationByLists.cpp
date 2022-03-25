/*

    You can implement a Grpah data structure using linked list.

    IMPORTANT!!!
    This representation of a Graph Data Structure using Linked Lists is called adjancency list.

*/

# include<iostream>
# include<list>

using namespace std;

int main()
{
    // list of create a graph data structure
    list<pair<int,int>> * l;

    // accepting the number of linked lists we want
    int n;

    cin >> n;

    l = new list <pair<int,int>> [n]; // l is a pointer to the array of linked list objects

    // accepting the number of edges we want
    int e;
    cin >> e;
    for (int i = 0; i < e; i++)
    {
        int x,y,wt;
        cin >> x >> y >> wt; // x is connected to y with a weight of wt

        l[x].push_back(make_pair(y,wt));

        // if it is a bi-directional edge (can go from both points to each other)
        // then you should also do
        l[y].push_back(make_pair(x,wt));
    }

    // print the linked lists
    for (int i =0 ; i < n ; i++)
    {
        // finding out which linked list it is
        cout << "Linked List " << i << "-->";
        // print every linked list
        for (auto xP: l[i]) // xP is the pair variable
        {
            cout << "(" << xP.first << ", " << xP.second << ")";
        }
    }

/*

INPUT:

3 3
0 1 4
0 2 3
1 2 4

*/

}