// 2 D Array examples

# include <iostream>
using namespace std;

int main() 
{
    int a[100][100] = {0};
    int n, m;
    int val = -1;

    cout << "Enter the number of columns that you want: ";
    cin >> n; 
    cout << "Enter the number of rows that you want: ";
    cin >> m;
    
    // initialise the array according to index
    for (int row = 0; row < m; row++) {
        for (int col = 0; col < n; col++) {
            val = val + 1;
            a[row][col] = val;     
            cout << a[row][col] << " ";
        }

        cout << endl;
    }

    cout << endl << endl << endl;

    // accessing values in a wavy fashion
    for (int col = 0; col < n; col++) { // this time columns are looped outside and rows change faster inside

        if (col % 2 == 0) {
            // Even Column: Top Down Prints
            for (int row = 0; row < m; row++) {
                cout << a[row][col] << " ";
            }
        } else {
            // Odd Column: Bottom Up Prints
            for (int row = m-1; row >= 0; row--) {
                cout << a[row][col] << " ";
            }
        }

        cout << endl;
    }

    return 0;
}