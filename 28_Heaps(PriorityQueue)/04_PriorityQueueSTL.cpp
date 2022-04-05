// Implementation of a Queue using STL library

#include<iostream>
#include<queue>
using namespace std;

int main()
{
    // creating a queue object (MAX HEAP by DEFAULT)
    priority_queue<int> pMax;

    // can instead have MIN HEAP like this (MIN HEAP)
    priority_queue<int, vector<int>, greater<int> > pMin;

    // adding elements into the queue
    for (int i = 0; i < 10; i ++)
    {
        pMax.push(i);
        pMin.push(i);
    }

    // removing elements from the queue
    for (int i = 0; i < 10; i ++)
    {
        cout << pMin.top() << " ";
        pMin.pop(); 
    }

    cout << endl;
    
    for (int i = 0; i < 10; i ++)
    {
        cout << pMax.top() << " ";
        pMax.pop(); 
    }
    
    return 0;
}