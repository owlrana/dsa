//  Using staircase searching in a SORTED 2D array (row and col wise sorted matrix)
/*  So we have 2 options to search:
        1. Brute force the whole array but is very costly -- O(n^2)
        2. To do binary search on each row and it should be a better approach giving -- O(N.Log(N))

    We exploit the information that the array is sorted throughout the row as well as columns!
    And then we come at a much better approach:

    --> Start from the rightmost corner and check if the element in that place is bigger or smaller than ours:
            1. IF IT IS SMALLER THAN WHAT WE ARE LOOKING FOR:
                    Then go down the column and check again!
            2. IF IT IS BIGGER THAN WHAT WE ARE LOOKING FOR:
                    Then go to the left element and check again!

    In worst case we will traverse 2N elements (First straight to bottom row, then to leftmost element)
    Thus this is the most optimised approach and is called staircase approach.
*/

# include <iostream>
using namespace std;

void staircaseChecker(int a[][100], int row, int col, int num) {

    int ptr_i = 0;
    int ptr_j = col - 1;

    while (ptr_i <= col-1 or ptr_j >= 0 ) {

        if (a[ptr_i][ptr_j] == num) {
            cout << "FOUND! Element was found at: " << ptr_i << ", " << ptr_j << endl;
            return; // ESCAPE SEQUENCE (stop this loop otherwise it will keep running)
        } else if (a[ptr_i][ptr_j] < num) {
            ptr_i ++;
        } else if (a[ptr_i][ptr_j] > num) {
            ptr_j --;
        }   
    }
    cout << "Element was not found :/" << endl;
}

int main ()
{
    int a[100][100];
    int val = 0, num;

    // just checking to create for 4x4 matrix
    for (int i = 0; i < 4; i ++) {
        for (int j = 0; j < 4; j ++) {
            val += 1;
            a[i][j] = val;
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Enter the number that you want to search for in the array: ";
    cin >> num;

    staircaseChecker(a, 4, 4, num);

    return 0;
}