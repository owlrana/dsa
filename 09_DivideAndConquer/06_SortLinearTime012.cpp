// this is for the problem: https://leetcode.com/problems/sort-colors/

// implementation of algorithm that sorts three different numbers in an array in linear time

# include <iostream>
# include <vector>
using namespace std;

int main ()
{
    vector<int> arr {0,1,2,1,1,0,0,2,0,1,1,2,0};
    int size = arr.size();

    for (int x:arr)
        cout << x << ", ";

    cout << "\b\b " << endl;

    int low = 0;
    int medium = 0;
    int high = size-1;

    while(medium <= high)
    {
        if (arr[medium] == 0)
        {
            swap(arr[medium], arr[low]);
            medium++;
            low++;
        }
        else if (arr[medium] == 1)
        {
            medium++;
        }
        else if (arr[medium] == 2)
        {
            swap(arr[high], arr[medium]);
            high --;
        }
    }

    for (int x:arr)
        cout << x << ", ";

    cout << "\b " << endl;

    return 0;
}

/*
    Can also make a loop to count the number of 0s and 2s,
        initialise the array of original size, all elements as 1
        then loop to add 0s to start of array
        then loop to add 2s from the end of the array
*/