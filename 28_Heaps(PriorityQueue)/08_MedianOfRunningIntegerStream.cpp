// Very popular interview question

// https://www.geeksforgeeks.org/median-of-stream-of-running-integers-using-stl/
// for the input 0 0 1 1 3 4 5 median should be 1.
// for the input 0 0 1 1 3 4 5 8 9 median should be 3.

#include<iostream>
#include<queue>
using namespace std;

int main()
{
    // 2 heaps for left part (max) and right part (min)
    priority_queue<int> leftHeap;
    priority_queue<int, vector<int>, greater<int> > rightHeap;

    // input of 1st number (data)
    int d;
    cin >> d;
    leftHeap.push(d);

    // median initialisation
    float med = d;
    cout << "Median: " << med << endl; // handling first median rightaway

    cin >> d;    
    // taking input unless input is -1
    while (d != -1)
    {
        // logic for median calculation

        // IF LEFT HEAP SIZE GREATER THAN RIGHT HEAP (odd number of elements)
        if (leftHeap.size() > rightHeap.size())
        {
            if (d < med)
            {
                rightHeap.push(leftHeap.top());
                leftHeap.pop();
                leftHeap.push(d);
            }
            else
            {
                rightHeap.push(d);
            }

            // even number of total elements, median will be avg 
            med = (leftHeap.top() + rightHeap.top()) / 2.0;
                
        }
        else if (leftHeap.size() == rightHeap.size()) // BALANCED HEAPS
        {
            if (d < med)
            {
                leftHeap.push(d);
                med = leftHeap.top();
            }
            else
            {
                rightHeap.push(d);
                med = rightHeap.top();
            }
            
        }
        else // RIGHT HEAP SIZE GREATER THAN LEFT HEAP (odd number of elements)
        {
            if (d > med)
            {
                leftHeap.push(rightHeap.top());
                rightHeap.pop();
                rightHeap.push(d);
            }
            else
            {
                leftHeap.push(d);
            }

            med = (leftHeap.top() + rightHeap.top()) / 2.0;
        }

        // printing median uptil now
        cout << "Median: " << med << endl;
        cin >> d;
    }

    return 0;
}