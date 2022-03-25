/*
    solved for: https://www.spoj.com/problems/ARRAYSUB/
    
    this is similar to https://leetcode.com/problems/sliding-window-maximum/
*/

#include<iostream>
#include<deque>
using namespace std;

int main()
{
    int n;
    int a[100000];
    int k;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cin >> k;

    // We have to process first K elements seperately
    deque<int> Q(k); // deque object 'Q' of int type and of size k
    int i =0;
    for ( ; i < k; i ++)
    {
        while(!Q.empty() && a[i] > a[Q.back()])
        {
            Q.pop_back();
        }
        Q.push_back(i);
    }

    // Process the remaining elements
    for ( ; i < n; i ++)
    {
        cout << a[Q.front()] << " ";

        //1. Remove elements which are not part of the window (Contraction)
        while((!Q.empty()) and (Q.front() <= i-k))
        {
            Q.pop_front();
        }

        // 2. Remove elements which are not useful are are inside the window
        while((!Q.empty()) and (a[i] >= a[Q.back()]))
        {
            Q.pop_back();
        }

        // 3. Add the new elements (Expansion)
        Q.push_back(i);
    }

    cout << a[Q.front()] << endl; // need to print the last element also

    return 0;
}