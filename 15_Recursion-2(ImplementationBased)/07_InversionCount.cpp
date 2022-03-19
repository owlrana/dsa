/*
    -- INVERSION COUNT PROBLEM -- 

    Suppose we have an array: 
        array = {1,5,2,6,3,0}
        In the Inversion Count problem, we need to find pairs such that they satisfy these two conditions:
            1.  a[i] > a[j]     (value should be larger)
            2.  i < j           (index should be smaller)

    We can do this in a brute force manner: 
        using two loops
            1.  Loop 1 for each i = 0 (slow pass)
            2.  Loop 2 for each j which is > 1 and < length (fast pass)

    The other approach is through Divide and Conquer.

    -->
        Divide the array into subarrays and find out the no. of pairs in them
        Then sort the arrays, and like a merge sort compare the cross inversions

*/

# include <iostream>
using namespace std;

int merge(int array[], int start, int end)
{
    int mid = (start + end) / 2;
    
    int i = start;
    int j = (mid + 1);
    int k = start;

    int temp[10000];

    int count = 0; // to count cross inversions

    // mermging
    while (i <= mid and j <= end)
    {
        if (array[i] <= array[j])
        {
            temp[k] = array[i];
            k += 1;
            i += 1;
        }
        else
        {
            temp[k] = array[j];
            k += 1;
            j += 1;

            // also, we need to increment the count by the no. of items remaining in the left array
            // as all elements to right must be greater than it so they would also fit our criteria
            
            count += mid -i + 1; // add the elements between them, PLUS the current element as well
        }
    }

    // fill the array if some elements are left in one of the arrays
    while (i <= mid)
        temp[k++] = array[i++];

    while (j <= end)
        temp[k++] = array[j++];

    for (int x = start; x <= end; x ++)
        array[x] = temp[x];

    return count;
}

int inversion_count(int array[], int start, int end)
{
    // base case
    if (start >= end)
        return 0;

    // merge sort
    int mid = (start + end) / 2;
    int x = inversion_count(array, start, mid);
    int y = inversion_count(array, mid+1, end);

    int z = merge(array, start, end); // this function tells the number of cross inversions
    
    // Arrays divided by the mid sections would already be sorted. We also find which inter-array
    // elements are present in them to make pairs that fit our criteria of question

    return x + y + z;
}

int main ()
{
    int array[] = {1,5,2,6,3,0};
    int size = sizeof(array)/sizeof(int);

    cout<< inversion_count(array, 0 , size-1) << endl; 

    return 0;
}