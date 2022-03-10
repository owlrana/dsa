// 2 D Array examples

# include <iostream>
using namespace std;

int main() 
{
    int a[5][3] = {0}; // to get all elements as 0, otherwise it will take garbage value
    // can also do a[1000][1000] and then ask user to input row/column

    int val = 0;
    // iterate over the 2D array
    for (int row = 0; row < 5; row++) {
        for (int col = 0; col < 3; col++) {
            val = val + 1;
            a[row][col] = val;     
            cout << a[row][col] << " "; //spaces after each column element
        }
        cout << endl; // next line after each row
    }

    return 0;
}