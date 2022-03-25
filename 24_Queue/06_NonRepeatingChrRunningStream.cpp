/*
    Similar to this:
    https://leetcode.com/problems/first-unique-character-in-a-string/
*/

#include<iostream>
#include<queue>
using namespace std;

int main()
{
    queue<char> q;
    int freq[27] = {0}; // our frequency table

    // input of running stream until a "." is inserted
    char ch;
    cin >> ch;

    while (ch != '.')
    {
        // insert into queue and insert into the frequency table right away
        q.push(ch);
        freq[ch - 'a'] ++;

        // look at front and check if it is repeating or not
        while(!q.empty())
        {
            int idx = q.front() - 'a';
            if (freq[idx] > 1)
            {
                q.pop();
            }
            else
            {
                cout << q.front() << endl;
                break;
            }
        }

        // if you come out of this while loop and queue is empty
        if (q.empty())
        {
            cout << "-1" << endl;
        }

        cin >> ch;
    }
/*

INPUT->
    aabccbc.

OUTPUT->
    a
    -1
    b
    b
    b
    -1
    -1

*/


}