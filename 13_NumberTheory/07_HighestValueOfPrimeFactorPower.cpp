/*
    https://leetcode.com/problems/factorial-trailing-zeroes/
    This can be solved using the concept below in comments:
    
    --- To compute the max value of a given number from a factorial ---

    Eg. We need to calculate the power of 5 from 10!
        10! =  1 x 2 x 3 x 4 x 5 x 6 x 7 x 8 x 9 x 10
        for the value 5, we have, 5^2, thus the answer is 2

        This may look easy for 10! but even for 100! this turns into a very big problem
        as 100! = 1 x 2 x 3 x 4 x 5 x 6 x 7 x 8 x 9 x 10 ... 95 x 96 x 97 x 98 x 99 x 100

    But we can observe a pattern,
        ->  All numbers upto 25 have ONLY 1 single 5, from 25 we also see two occurrences of 5.
            (like in 25, 50, 75, 100) multiples of 25....
            if the number was greater, like 200, we would have seen 3 powers of 5 as well like in 125..

    So we can devise a method:

    power of 5 in 100: [100/5] + [100/25] + [100/125] + ..... until a term turns into Zero
    which is basically like dividing by 5^i+1 and adding the terms 

    similarly we can also calculate this for other numbers from 1 leading upto 100 (N).
    This greatly reduces the number of computations we will have to do.

    // for the leetcode problem, find out power of both 5 and 2, then return the minimum from them
*/

# include <iostream>
# include <vector>
# include <climits>

using namespace std;

int main ()
{
    int n, k;
    cin >> n >> k;

    // taking a very large value as ANS, ( if the ans is NOT updated in our block, then this will be used )
    int ans = INT_MAX;

    // find out the factors, doing the factorisation of k along with their powers
    // goes till root of k, however leaves a factor at times but that is handled ahead
    // Eg. for 10, loop goes till 3, so it leaves 5. but after dividing with everything, 
    // only 5 is left (k = 5), so if the num !=1, means there is a prime number left
    int occ = 0;
    for (int i = 2; i*i <= k; i ++)
    {
        cout << "INSIDE THE LOOP" << endl;
        if ((k % i) == 0)
        {
            occ = 0;
            while ((k % i) == 0)
            {
                cout << "INSIDE SECOND LOOP" << endl;
                occ ++;
                k = k / i;
            }
            // find out the power of i in n! side by side
            int cnt = 0; // needed cause we need to track the power
            int p = i;
            while (p <= n) // loop to calculate T1, T2, T3 etc explained in comment before program
            {
                cout << "INSIDE THIRD LOOP!" << endl;
                cnt += n / p;
                p = p * i; // p stands for powers of i
            }
            cout << ans << endl;
            ans = min (ans, cnt/occ);
            cout << ans << endl;
        }
        if (k > 1) // this will be a prime number
        {
            // int occ  = 1; // this is not needed as the occurrence would only be one
            int p = k;
            int cnt = 0;

            while (p <= n)
            {
                cnt += n / p;
                p *= k;
            }
            ans = min (ans, cnt);
        }

        // also possible that n! does not contain factorials of k, then the ans should be 0
        if (ans == INT_MAX)
            ans = 0;
    
    }

    cout << ans << endl;

    return 0;
}