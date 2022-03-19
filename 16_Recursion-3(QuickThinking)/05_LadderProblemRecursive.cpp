/*
    Need to reach the top of the ladder. Find out the number of ways in which you can do this.
    https://leetcode.com/problems/climbing-stairs/

    Ans:
        Assume that to reach the top position with jumps given as 1,2 and 3,
        we can only reach the top position by:
            1.  jump of 3 from N-3 ladder
            2.  jump of 2 from N-2 ladder
            3.  jump of 1 from N-1 ladder
        and we calculate for them recursively, so to reach the above three ladders we also do the same.
*/

# include <iostream>
using namespace std;

int f(int n, int k)
{
    if (n == 0)
        return 1;
    if ( n < 0)
        return 0;

    // making calls on f(n-1), f(n-2), f(n-3) and adding them
    int ans = 0;
    for (int i = 1; i <= k; i ++)
        ans += f(n-i, k);

    return ans;
}

int main ()
{
    int n, k;
    cin >> n >> k;

    cout << f(n,k);
    
    return 0;
}