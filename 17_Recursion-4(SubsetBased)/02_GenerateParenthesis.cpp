// https://leetcode.com/problems/generate-parentheses/

# include <iostream>
using namespace std;

void generate_brackets(char* out, int n, int idx, int open, int close)
{
    // base case first
    if (idx == (2 * n)) // if the length of the string is done (2*n as n pairs of brackets)
    {
        out[idx] = '\0'; // create a string by adding NULL to the end
        cout << "\"" << out << "\"" << ", "; // output it
        return; // return; get out of the base case
    }

    // recursive case
    /*  2 options - 
            1.  Can we put an opening bracket? 
                Only if the count of opening brackets is less than n
            2.  Can we put a closing bracket?
                Only is the count of closing brackets is less than that of opening brackets 
                (a bracket must be opened first to be closed)
    */
    if (open < n)
    {
        out[idx] = '(';
        generate_brackets(out, n, idx + 1, open + 1, close);
    }

    if (close < open)
    {
        out[idx] = ')';
        generate_brackets(out, n, idx+1, open, close + 1);
    }
    return;
}

int main ()
{
    // generate brackets
    int n;
    cin >> n;

    char out[1000];

    generate_brackets(out, n, 0, 0, 0);

    return 0;
}