/*
    Longest substring without Repeating Characters

    https://leetcode.com/problems/longest-substring-without-repeating-characters/

    Eg. in a string:    A B C D E C G H
    The longest substring without repeating chracters would be:
                        A B C D E


    1.  Brute Force
        n^2 possible values for i and j pointer, iterate for each n elements
        Total will take O(n^3) time.

    2.  Sliding Window Approach
        Expand/Shrink sliding window according to our need while traversal
        
    We will need to store the max length thus far
    We will also need to store the frequency with the index of a char last occurred
    (will use hashmap for this freq)
*/


#include<iostream>
#include<cstring>
using namespace std;

int main()
{
    char a[] = "abcdefghijkzyxz";

    int n = strlen(a);
    int current_len = 1;
    int max_len = 1;

    int visited[256];

    for (int i = 0; i < 256; i++)
    {
        visited[i] = -1;
    }

    // first character
    visited[a[0]] = 0;

    // for remaining characters
    for (int i = 1; i < n; i ++)
    {
        int last_occ = visited[a[i]];

        // expansion case
        if (last_occ == -1 or i - current_len > last_occ)
        {
            current_len += 1;
            //max_len = max(current_len, max_len);
        }
        // expansion + contraction
        else
        {
            if (current_len > max_len)
            {
                max_len = current_len;
            }
            current_len = i - last_occ;
        }
        visited[a[i]] = i;
    }
    cout << max_len << endl;

    return 0;
}