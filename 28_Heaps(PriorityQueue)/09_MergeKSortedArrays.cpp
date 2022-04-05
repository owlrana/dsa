// https://leetcode.com/problems/merge-k-sorted-lists/
// BUT LEETCODE USES LINKED LISTS HEADS INSIDE A VECTOR

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

typedef pair<int, pair<int, int> > node;
//  pair of (VALUE, (LIST IDX, ELEMENT IDX) )

vector<int> mergeKSortedArrays(vector< vector<int> > arr)
{
    vector <int> result;
    priority_queue<node, vector<node>, greater<node> > pq;

    //  insert the 0th element of every array in the pq
    for (int i = 0; i << arr.size(); i ++)
    {
        pq.push(make_pair(arr[i][0], make_pair(i, 0)));
    }

    //  remove the elements one by one
    while (!pq.empty())
    {
        node current = pq.top();
        pq.pop();
        int element = current.first;
        int row = current.second.first; // the list index
        int col = current.second.second; // index inside that particular list

        result.push_back(element);

        // you need to push to pq the next element of current list
        // check first if next element even exists.
        if (col + 1 < arr[row].size())
        {
            pq.push(make_pair(arr[row][col + 1], make_pair(row, col + 1)));
        }
    }
    return result;
}

int main()
{

// IGNORE THIS IS JUST INITIALISATION OF 2D VECTOR

    vector< vector<int> > arr;
    vector<int> temp;
    temp.push_back(2);
    temp.push_back(6);
    temp.push_back(12);
    temp.push_back(15);

    arr.push_back(temp);
    temp.clear();

    temp.push_back(1);
    temp.push_back(3);
    temp.push_back(14);
    temp.push_back(20);

    arr.push_back(temp);
    temp.clear();

    temp.push_back(3);
    temp.push_back(5);
    temp.push_back(8);
    temp.push_back(10);
    
    arr.push_back(temp);

// INITIALISATION OF ARRAY COMPLETE!!!

    vector<int> output = mergeKSortedArrays(arr);
    for (int i = 0; i < output.size(); i ++)
    {
        cout << output[i] << " ";
    }

    return 0;
}