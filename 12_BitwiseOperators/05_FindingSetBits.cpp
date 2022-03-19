// Program to find the number of set bits in any number


# include <iostream>

using namespace std;

/*
    Time Complexity: O(Logn)
        At max any number will have logn + 1 bits
        So for long long int (with max value 10^18), then log10^18 = 64
        Thus, for a 64 bit number, you need 64 iterations to find out how many set bits are there
*/  
int countBits (long long n)
{
    int count = 0;
    while (n!=0)
    {
        if ((n & 1) == 1)
            count += 1;
        n = (n >> 1);
    }
    return count;
}

/*
    Time Complexity: O(no. of set bits) = O(n)
        Works by finding out if there are any common bits at the same place or not
        Eg. n = 9 ( 0000 1001 )
            n-1=8 ( 0000 1000 )
            AND = ( 0000 1000 ) ... answer = 1
            n-1=7 ( 0000 0111 ) ... answer = 2
            AND = ( 0000 0000 ) STOPS. Answer = 2.

*/
int countBitsFast (long long n)
{
    int ans = 0;
    while (n > 0)
    {
        n = n & (n-1);
        ans += 1;
    }
    return ans;
}

int main ()
{
    long long n = 999999999999999999; // to the abs olute limit
    cout << countBitsFast(n) << endl;
    cout << countBits(n) << endl;

    // can also use the in-built function to count the set bits 
    // does not work for very long numbers
    cout << __builtin_popcount(n) << endl;

    return 0;
}