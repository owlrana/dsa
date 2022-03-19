/*
    --- SUBSEQUENCE / SUBSET GENERATION (does not necessarily have to be contiguous) ---
    Important concept for MANY problems

    Eg. Given a string containing n characters find out all the subsets of that string.
        INPUT --> "abc"
        OUTPUT --> "", "a", "b", "c", "ab", "ac", "bc", "abc" (total 8)  

    How it clicks (The Recursive Approach):
    https://i.imgur.com/C13twhz.png

    This technique solves:
    https://leetcode.com/problems/distinct-subsequences/

*/
# include <iostream>
# include <cstring>
using namespace std;

void subsequence(char* in, char* out, int i, int j)
{
    // base case
    if (in[i] == '\0')
    {
        out[j] = '\0';
        cout << out << endl;
        return;
    }

    // recursive case
    // include the current character
    out[j] = in[i]; // copy this chracter to output 
    
    // make a recursive call on rest
    subsequence(in, out, i + 1, j + 1);

    // another recursive call but exclude the current character (j will not be j+1 this time)
    subsequence(in, out, i + 1, j); // in this j will not move (will overwrite the character)
}

int main ()
{
    char input[] = "ABC";
    char output [1000]; // size taken 1000 just because it is common to have strings upto that length

    subsequence(input, output, 0, 0);
    return 0;
}