/*
    You are given two 32 bit numbers, N and M, and two bit positions, i and j
    Write a method to set all bits between i and j in N equal to M 
    Eg. N = 10000000000,
        M = 10101
        i = 2, j = 6
        OUTPUT = 10001010100 

*/

# include <iostream>

using namespace std;

int main ()
{
    int n, m, i ,j;
    cout << "Enter the number (n): ";
    cin >> n;
    cout << "Enter the bits you want to replace with: ";
    cin >> m;
    cout << "Enter the 1st index you want to start replacing bits from (i): ";
    cin >> i;
    cout << "Enter the 2nd index you want to replace bits till (j): ";
    cin >> j;

    // clearing section from i to j index of n
    int ones = (~0) << (j+1);
    int temp = (1 << i) - 1;
    int mask = ones | temp;
    int num = n & mask;
    
    int pos_m = m << i;
    int ans = num | pos_m;

    cout << ans;

    return 0;
}