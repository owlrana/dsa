// to print array in a spiral fashion (like that in hallucinating circles etc)

// this code does NOT work for matrix of row = 2 and col = 3

// CODING BLOCKS IS A PIECE OF SHIT!!!!

# include <iostream>
using namespace std;

void spiralPrint(int a[][100], int m, int n) {

    int startRow = 0;
    int startCol = 0;
    int endRow = m-1;
    int endCol = n-1;

    // print until..
    while (startRow <= endRow and startCol <= endCol) {
        // First Row
        for (int i = startCol; i <= endCol; i++) {
            cout << a[startRow][i] << " ";
        }
        startRow ++;

        // Print right end column
        for (int i = startRow; i <= endRow; i++) {
            cout << a[i][endCol] << " ";
        }
        endCol --;

        // Bottom Row
        if (endRow > startRow) { // only for odd values
            for (int i = endCol; i >= startCol; i --) {
                cout << a[endRow][i] << " ";
            }
            endRow --;
        }

        // start Col
        if (endCol > startCol) { // only for odd values
            for (int i = endRow; i >= startRow; i--) {
                cout << a[i][startCol] << " ";
            }
            startCol ++;
        }
    }
}

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
            int number;
            cin >> number;
            a[row][col] = number;     
            cout << a[row][col] << " ";
        }

        cout << endl;
    }

    spiralPrint(a, m, n);

    return 0;
}