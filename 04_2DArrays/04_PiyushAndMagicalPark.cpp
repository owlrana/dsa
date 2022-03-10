// Need to traverse the 2D array in rowise manner, traversing each row from left to right
// but also need to take care of a couple of things:

/*
    --> PIYUSH STARTS WITH A STRENGTH 'T'. EACH TIME HE MOVES TO RIGHT HIS STRENGTH IS DEC BY 1, BUT NOT
        WHEN HE MOVES TO THE COLUMN BENEATH. THERE ARE ALSO MORE COMPLEXITIES:
            1. Each time he is met with '.', the strength decreases by 2 in addition to normal traversals
            2. Each time he is met with '*', the strength increases by 5 in addition to dec by norm travs
            3. Each time he is met with '#', he cannot traverse next to right and needs to change columns

        We need to find if he will be able to get out of this 2D Array by maintaining a strength of 'K'
        at all times throughout the array.
        
*/
# include <iostream>
using namespace std;

void magical_park(char a[][100], int m, int n, int k, int s);

int main ()
{
    int m, n, k, s;
    cin >> m >> n >> k >> s;

    char park[100][100];
    // Take input
    for (int i = 0; i < m; i ++) {
        for (int j = 0; j < n; j ++) {
            cin >> park[m][n];
            // take input as 
            /* (unindented so you can easily copy from here)
. . * .
. # . .
* * . .
. # * *
            */
        }
    }

    magical_park(park, m, n, k, s);

    return 0;
}

void magical_park(char a[][100], int m, int n, int k, int s) {

    // means piyush can get out of the park
    bool success = true;

    for (int i = 0; i < m; i ++) {
        for (int j = 0; j < n; j ++) {
            
            char ch = a[i][j]; // this is the character that is met 
            
            if (s < k) { // if the strength at any point is less than threshold, exit
                success = false;
                break;
            }

            if (ch == '*') {
                s += 5;
            } else if (ch == '.') {
                s -= 2;
            } else { // if we encounter a hash
                break;
            }
            // we also lose 1 point each time we move right except for the last column to change rows
            if (j != n-1) {
                s--;
            }
        }
    }

    if (success) {
        cout << "YES!" << endl;
        cout << s << endl;
    } else {
        cout << "No.." << endl;
    }
}