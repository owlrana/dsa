// Bubble Sort (The highest elements keep going to the end by pairwise comparisons)

/*
    You need to do n-1 passes:
        In each pass you need to swap to elements
*/

# include <iostream>
using namespace std;

void bubbleSort(int a[], int n)
{
    // base case
    // if an array contains only a single element, then it is a sorted array
    if (n == 1)
        return;

    // recursive case
    for (int j = 0; j < n-1; j ++)
    {
        if (a[j] > a[j+1])
        {
            swap(a[j], a[j+1]);
        }
    }
    // sort the first n-1 elements after largest elements have moved to end
    bubbleSort(a, n-1); // outer loop is the one where it is already sorted
}

// removing the inner j loop as well... for a better, fuller understating of recursion
void recursiveBubbleSort(int a[], int j, int n) // j will run the inside loop
{
    // base case
    // if an array contains only a single element, then it is a sorted array
    if (n == 1)
        return;
    // base case for J as well (need two corner cases, think like loops...)
    if (j == n-1) // this means that one pass for swaps has been completed, need to re-init j to 0
    {
        recursiveBubbleSort(a, 0, n-1); // this time one less pass for outer passes
    }

    // recursive case
    if (a[j] > a[j+1])
        swap(a[j], a[j+1]);
    
    recursiveBubbleSort(a, j+1, n); // this is like the inner loop, as we need to swap using j++
    return ;
}

int main ()
{
    int a1[] = {5,4,3,1,2};
    int a2[] = {5,4,3,1,2};
    int n = 5;

    // bubble sort (half recursive)
    bubbleSort(a1, n);

    for (auto x: a1)
        cout << x << ", ";
    cout << endl;

    // fully recursive
    bubbleSort(a2, n);

    for (auto x: a2)
        cout << x << ", ";
    cout << endl;

    return 0;
}