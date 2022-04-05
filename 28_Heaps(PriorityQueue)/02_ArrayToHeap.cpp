// Converting Array into a MAX Heap and MIN heap

#include<iostream>
#include<vector>
using namespace std;

void print(vector<int> input)
{
    for (int i = 0; i < input.size(); i ++)
    {
        cout << input[i] << ", ";
    }
    cout << endl;
}

// converting into a max heap IN PLACE 
// O(N LogN) time
void convertToMAXHeap (vector<int> &input)
{
    for (int i = 2; i < input.size(); i ++)
    {   int idx = i;
        int parent = idx/2;

        while (idx > 1 and input[idx] > input[parent])
        {
            swap(input[idx], input[parent]);
            idx = parent;
            parent = parent/2;
        }
    }
} 

// converting into a min heap IN PLACE
// O(N LogN) time
void convertToMINHeap (vector<int> &input)
{
    for (int i = 0; i < input.size(); i ++)
    {
        int idx = i;
        int parent = idx/2;

        while (idx > 1 and input[idx] < input[parent])
        {
            swap(input[idx], input[parent]);
            idx = parent;
            parent = parent / 2;
        }
    }
}

// !!!!!!!!!!-----------------------------------------!!!!!!!!!!

// OPTIMISED APPROACH (BOTTOM UP APPROACH)
// O(N) time only

// !!!!!!!!!!-----------------------------------------!!!!!!!!!!

// require the help of heapify function for MAX HEAP
void heapify(vector<int> &v, int idx)
{
    int left = idx * 2;
    int right = left + 1;

    int min_idx = idx;
    int last = v.size() - 1;

    if ((left <= last) and (v[left] > v[idx]))
    {
        min_idx = left;
    }

    if ((right <= last) and (v[right] > v[min_idx]))
    {
        min_idx = right;
    }

    if (min_idx != idx)
    {
        swap(v[idx], v[min_idx]);
        heapify(v, min_idx);
    }
}

// OPTIMISED APPROACH FOR CREATING HEAP FROM ARRAY IN O(N)
void optimisedMaxHeap (vector<int> &v)
{
    int n = v.size() - 1;

    // from the last parent node, we NEED to reach 1 (1st node) 
    for (int i = (n/2); i >= 1; i --)
    {
        heapify(v, i);
    }
}

int main()
{
    vector<int> input;
    input.push_back(-1);

    int n;
    cout << "How many elements do you want to store? ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        input.push_back(num);
    }
    cout << endl;

    cout << "MAX HEAP: ";
    convertToMAXHeap(input);
    print(input); cout << endl;

    cout << "MIN HEAP: ";
    convertToMINHeap(input);
    print(input); cout << endl;

    cout << "OPTIMISED MAX HEAP: ";
    cout << endl;
    optimisedMaxHeap(input);
    print(input); cout << endl;

    return 0;
}