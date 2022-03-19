// Concept can be used to solve this problem:
// https://leetcode.com/problems/palindromic-substrings/

/*
    The idea is to create different combinations of bits to generate new strings...
    Eg.
        string = "abc"
        abc.size() = 3
        so for 3, we create a number such that it's bits are = 1000
        that will be our upper limit to stop loop, and combinations will be as follows:
            - 0001
            - 0010
            - 0011
            - 0100
            - 0101
            - 0110
            - 0111
        We wont be including 1000, that is just the loop boundary
        We will also map the bits created above with the string positions as follows
            - 0001  :   a
            - 0010  :   b
            - 0011  :   ab
            - 0100  :   c
            - 0101  :   ac
            - 0110  :   bc
            - 0111  :   abc
        In which all the set bits indicate that THAT PARTICULAR index in string should be included
        
        We can also use string and vectors to store all such strings for later, for more manipulations
*/

# include <iostream>
# include <vector>

using namespace std;

void filterChars (int n, string a)
{
    int j = 0;

    while (n > 0)
    {
        int last_bit = (n & 1);
        if (last_bit)
            cout << a[j];
        j += 1;
        n = n >> 1;
    }
    cout << endl;
}

void printSubsets( string a)
{
    int n = a.size();
    for (int i = 0; i < (1 << n); i ++)
        filterChars(i, a);
}

int main ()
{
    string str = "abc";
    printSubsets(str);
    return 0;
}