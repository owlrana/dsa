// to find out the last occurrence of a number in array using recursion

// this could have been solved using the previous method, just applying it RIGHT to LEFT
// but instead, to have a better and a more thorough understanding of recursion
// we go from LEFT to RIGHT and try to find out the LAST occurrence of the element

# include <iostream>
using namespace std;

// this time we cannot return the moment our element is found, this time we need to
// go to the absolute depth of the array to find out if our element exists or not!!
int lastOcc(int *array, int n, int key)
{
    // base case first
    if (n == 0)
        return -1;

    int i = lastOcc(array+1, n-1, key);

    // only check if the one's so far have already been failed at finding the element as we want RIGHTEST
    if (i == -1)
    {
        // now check if this array's first element has our element or not
        if (array[0] == key)
        {    
            return 0;
        }
        else
        {
            return -1;
        }
    }
    
    
    return i + 1;
}

int main ()
{
    int array[] = {1,2,3,4,5,6,10,7,7,7};
    int key = 7;
    int n = sizeof(array) / sizeof(int);

    cout << lastOcc(array, n, key) << endl;

    return 0;
}