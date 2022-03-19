/*
    --- TOWER OF HANOI ---
    Link: https://www.geeksforgeeks.org/c-program-for-tower-of-hanoi/
*/

# include <iostream>
using namespace std;

void  move(int n, char src, char helper, char dest)
{
    // base case
    if (n == 0) // can also make 1 as base case
        return; // do nothing

    // recursive case    
    //  1st step to move n-1 disk from source to helper (nth disk remains on the source)
    move(n-1, src, dest, helper); // the destination is helper for it right now
    
    cout << "Shift Disk " << n << " from " << src << " to " << dest << endl; // printout the steps
    
    //  2nd step to move n from source to destination
    move(n-1, helper, src, dest);
}

int main ()
{
    int n;
    cin >> n;

    move(n, 'A', 'B', 'C');

    return 0;
}

// this could have been solved without recursion but it would have been very complex, we would have to use stacks