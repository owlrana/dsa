// ONLY WORKS IN A SORTED ARRAY! The approach below solves this problem in Linear Time O(n)

// ***** Given a sorted array, find pair of elements that sum to K (given) *****
/*
        ->  One pointer goes to the start. One pointer goes till the end. Add both the pointer values:
            1. If the sum is less than what you were expecting, move left pointer + 1
            2. If the sum is less than what you were expecting, move right pointer - 1
            3. If found, move left to + 1 and move right - 1, and keep finding other possible pairs
*/

# include <iostream>
using namespace std;

int main() 
{
    int arr[] =  {1,3,5,7,10,11,12,13}; //initialising the array to avoid input
    int sum = 16; //whatever the user needs

    int i = 0;
    int j = sizeof(arr)/sizeof(int)-1;

    while(i<j) {
        int current_sum = arr[i] + arr[j];
        if (current_sum > sum) {
            j--;
        } else if (current_sum < sum) {
            i++;           
        } else {
            cout << arr[i] << " and " << arr[j] << endl;
            i++;
            j--;
        }
    }

    return 0;
}