// In this we arae given a 2D array and we need to rotate it by 90 degrees anticlockwise
// We can do this rotation easily by making another array and then filling it left-right rowise
// by traversing our original array row-wise from right to left, but it will cost us a whole new array

// So, we will have to do this rotation in place now to save memory. Our approach is as follows:

/*
    Suppose the array is -->                     And we need to turn this into -->
                                1  2  3  4                                          4 8 12 16
                                5  6  7  8                                          3 7 11 15
                                9  10 11 12                                         2 6 10 14
                                13 14 15 16                                         1 5 9  13
    
    1. We will first reverse the order of each row in the array, so it becomes -->
                                4  3  2  1
                                8  7  6  5
                                12 11 10 9
                                16 15 14 13

    2. Then, we need to find the transpose of the matrix 
       (swap the matrix along its diagonal [diag. that goes from left top corner to right bottom corner])
        basically: a[i][j] <--> a[j][i] 

        After doing this, the matrix becomes -->
                                4 8 12 16
                                3 7 11 15
                                2 6 10 14
                                1 5 9  13
        
    That is what was required!

    (We will do it once without STL, and then once with the STL library's use)
*/

# include <iostream>
# include <algorithm>
using namespace std;

void rotate(int a[][100], int n); // without using stl
void rotate_stl(int a[][100], int n); // using stl, header file is <algorithm>

int main ()
{
    int a [100][100];
    int n;
    cin >> n;

    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < n; j ++) {
            cin >> a[i][j];
        }
    }

    rotate(a, n);
    // check
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < n; j ++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl << endl;

    rotate_stl(a, n);
    // check
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < n; j ++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

void rotate(int a[][100], int n) {

    // first reverse each row
    for (int row = 0; row < n; row ++) {
        int start_col = 0;
        int end_col = n-1;
        while (start_col < end_col) {
            swap(a[row][start_col], a[row][end_col]);
            start_col ++;
            end_col --;
        }
    }

    // now we need to find the transpose
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < n; j ++) {
            // we need to do the only for one triangle (half) otherwise we will get the same array lol
            if (i < j) {
                swap(a[i][j], a[j][i]);
            }
        }
    }
}

// Now doing this while using in-built STL
void rotate_stl(int a[][100], int n) {

    // first reverse each row using STL reverse(start_container, end_container) method
    for (int i = 0; i < n; i ++) {
    
        reverse(a[i], a[i]+n);
        // here a[i] is the row pointer
        // row pointer means that it is pointing to the starting of the row
    
    }

    // now we need to find the transpose
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < n; j ++) {
            // we need to do the only for one triangle (half) otherwise we will get the same array lol
            if (i < j) {
                swap(a[i][j], a[j][i]);
            }
        }
    }
}