// https://www.geeksforgeeks.org/connect-n-ropes-minimum-cost/
// the idea is to combine the smallest ropes to get least consecutive sums

#include<iostream>
#include<queue>
using namespace std;

int join_ropes(vector<int> ropes, int size)
{
    //  we need a MIN heap...
    priority_queue<int, vector<int>, greater<int> > pq(ropes.begin(), ropes.end());
    int cost = 0;

    //  when the size of pq will be 1, we wont be able to add new ropes...
    while (pq.size() > 1)
    {
        int A = pq.top();
        pq.pop();
        int B = pq.top();
        pq.pop();

        int new_rope = A + B;
        cost += new_rope;

        pq.push(new_rope);
    }

    return cost;
}

int main()
{
//  only organising input
    int input[] =  {4, 3, 2, 6};
    int n = sizeof(input)/sizeof(int);

    vector<int> ropes;
    for (int i = 0; i < n; i ++)
    {
        ropes.push_back(input[i]);
    }
//  end of organising input

//  FINDING OUT THE OPTIMAL SOLUTION TO JOIN ROPES IN MINIMUM COST!
    cout << join_ropes(ropes, n) << endl;

    return 0;
}