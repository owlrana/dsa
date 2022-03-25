// weighted graphs implementation using linked lists

#include<iostream>
#include<list>
#include<utility>
using namespace std;

int main()
{
    list<pair<int,int> >* l;
    int n;
    cin >> n;

    l = new list<pair<int, int> > [n]; // list containing pars of int, int 

    int e;
    cin >> e; // number of edges

    for (int i = 0; i < e; i++)
    {
        int x, y, weight;
        l[x].push_back(make_pair(y,weight));
        l[y].push_back(make_pair(x,weight));
    }

    // print the linked lists
    for (int i = 0; i < n; i ++)
    {
        cout << "Linked List " << i << "-> "; 
        // print every linked list
        // each pair xp in linkedlist[i]
        for (auto p: l[i])
        {
            cout << "(" << xp.first << ", " << xp.second << ")";
        }
        cout << endl;
    }

    return 0;

}