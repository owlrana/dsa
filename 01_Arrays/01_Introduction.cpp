// to show the concept of arrays, how to initialise them, avoiding garbage values etc

# include <iostream>

using namespace std;

int main()
{
    // to just initialise an array without any value.
    // This kind of array will have garbage values in it.
    int arr[10];

    // you can also use a variable to initialise the size of the array
    int n = 10;
    int array[n];

    // to avoid garbage values, you need to initialise the array as:
    int arr2[10] = {0}; // this puts the first element as 0, and rest as zero too

    int arr3[10] = {5, 5}; // this initialises the first two elements as 5 and rest 0

    // to find the length of an array, you need to find total size then divide by the size of type
    int length = sizeof(arr3)/sizeof(int);
    
    // values can be updated after the array is created
    arr[9] = 10;

    // to see all contents of the array/ or maybe ask for inputs into the array you can use loops
    for (int i = 0; i < length; i ++) {
        cout << array[i] << ", ";
    }

    return 0;
}