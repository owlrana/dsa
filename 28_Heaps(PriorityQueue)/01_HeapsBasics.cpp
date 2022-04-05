// implementation of heap and insertion function
// using vector for this implementation of heap

#include<iostream>
#include<vector>
using namespace std;

class Heap {

    vector<int> v;
    string heapType;

    // This should give TRUE accordingly using logic for min max heap both
    bool compare (int child, int parent)
    {
        if (heapType == "min")
        {
            return child < parent;
        }
        else
            return child > parent;
    }

    // this will correct the array into min/max heap accordingly after every deletion
    void heapify(int idx)
    {
        // store the indices of left and right subtree for idx
        int left = 2 * idx;
        int right = left + 1;

        // initialising last index and minimum index to be swapped with later on
        int last = v.size() - 1;
        int min_idx = idx;

        // finding out the min index to swap later
        if (left <= last && compare(v[left], v[min_idx]))
        {
            min_idx = left;
        }
        if (right <= last && compare(v[right], v[min_idx]))
        {
            min_idx = right;
        }

        // if idx is the same as before (not changed) that means our recursive call should be over
        if (idx != min_idx)
        {
            swap(v[idx], v[min_idx]);
            heapify(min_idx); // call for the current index
        }
    }

public:
    void print ()
    {
        for (int i = 0; i < v.size(); i ++)
        {
            cout << v[i] << ", ";
        }
        cout << endl;
    }

    Heap (string aHeapType, int default_size = 10)
    {
        v.reserve(default_size);
        v.push_back(-1); // during initialization, blocking the 0th index (as Heap's index starts from 1)
        heapType = aHeapType;
    }

    // adding elements into the heap
    void push(int d)
    {
        v.push_back(d);
        int idx = v.size() - 1;
        int parent = idx / 2;

        // trying to put this number at its right position by swapping continuously with its parent
        while (idx > 1 and compare(v[idx], v[parent]))
        {
            swap(v[idx], v[parent]);
            idx = parent;
            parent = parent / 2;
        }
    }

    // get function to return the TOP MOST element of the heap
    int top()
    {
        return v[1];
    }

    // removing the top most element from the heap
    void pop ()
    {
        int last = v.size() - 1; 
        swap(v[1], v[last]); // swap 1st element with the last one
        v.pop_back(); // remove the last element from our vector
        heapify(1); // start heapifying the heap from first index
    }

    bool empty()
    {
        return v.size() == 1;
    }
};

// MAIN FUNCTION 
int main()
{
    Heap h("max"); // can also do "min" heap
    int size = 10;
    cin >> size;

    for (int i = 0; i < size; i ++)
    {
        int num;
        cin >> num;
        h.push(num);

        cout << "Top is: " << h.top() << endl;
    }

    while (!h.empty())
    {
        cout << h.top() << " ";
        h.pop();
    }

    return 0;
}