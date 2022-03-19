// First Occurrence using Recursion (Can also be done using linear search, but this is based on it)

# include <iostream>
using namespace std;

int firstOcc(int *array, int n, int key)
{
    if (n == 0) // means that we have already checked all elements of the array
        return -1;

    if (array[0] == key) // if we found the element in the 0th position (base case)
        return 0;
    
    int i = firstOcc(array+1, n-1, key); // make the recursive call
    if (i == -1) // each function should know if the previous func gave -1, then it also needs to give -1
        return -1;
    
    return i + 1;
}

// a more linear search approach based on recursion
int linearSearch (int *array, int i, int n, int key)
{
    // base case (termination like in a loop)
    if (i == n)
        return -1;

    // check whether the index in this value of i has the key present or not
    if (array[i] == key)
        return i;

    // then call the function again with the new value of i that is next to it
    return linearSearch(array, i+1, n, key);
}

int main ()
{
    int array[] = {1,2,3,7,4,5,6,7,10};
    int key = 7;
    int n = sizeof(array) / sizeof(int);

    cout << firstOcc(array, n, key) << endl;
    cout << linearSearch(array, 0, n, key) << endl;

    return 0;
}