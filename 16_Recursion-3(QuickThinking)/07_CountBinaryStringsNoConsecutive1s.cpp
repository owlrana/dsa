/*
    --- COUNT BINARY STRINGS ---
    Count binary strings of length of N, which have no consecutive ones.
    Eg. N is given as 2, so we need strings of length = 2 that have no consecutive 1s in them
        ALL STRINGS OF LENGTH 2 ==>
                                    00 - Valid - 
                                    01 - Valid - 
                                    10 - Valid -
                                    11  INVALID 

    Similar to:
    https://leetcode.com/problems/non-negative-integers-without-consecutive-ones/
*/

# include <iostream>
using namespace std;

int validStrings(int length)
{
    // base case first
    if (length == 0)
        return 0;
    if (length == 1)
        return 2;
    if (length == 2)
        return 3;

    // recursive call
    return (validStrings(length-1) + validStrings(length-2));
}

int main ()
{
    int length = 17;
    cout << validStrings(length) << endl;

    return 0;
}