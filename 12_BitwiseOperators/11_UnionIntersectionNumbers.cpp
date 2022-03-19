/*
    --- THEORY BEFORE PROCEED WITH CODE ---
    ----------------------------------------
    
    |A U B| = |A| + |B| - |A∩B|
    
    |A U B U C| = |A| + |B| + |C| - |A∩B| - |B∩C| -|C∩A| + |A∩B∩C|

    |A U B U C U D| = |A| + |B| + |C| + |D| - |A∩B| - |B∩C| -|C∩D| .... + |A∩B∩C| + A∩B∩D| .... -|A∩B∩C∩D|

    General pattern:
    You need to add/subtract all subsets while doing union if:
        1. subset is odd number of elements:    
            ADD THEM
        2. subset is even number of elements:
            SUBTRACT THEM

    ----------------------------------------
    
    -- EXAMPLE FOR THESE TYPE OF PROBLEMS --

    How many numbers < 1000 are divisible by 2, 3, 5 ?

    ->  Generate all the subsets of 2,3,5.
        Subsets (2^n, but we do not want null subset so: (2^n)-1):
            2, 3, 5, 2 3, 3 5, 2 5, 2 3 5.  
        (Can use bitmasking like in previous question to get these subsets)

        Numbers below 1000 divisible by 2 = floor(999)/2 = 499
        Numbers below 1000 divisible by 3 = floor(999)/3 = 333
        Numbers below 1000 divisible by 5 = floor(999)/5 = 199

        Now we need numbers divisible by all 2,3,5
        |2 U 3 U 5| = |2| + |3| + |5| - |2∩3| - |2∩5| - |3∩5| + |2∩3∩5|

        We need to compute from subsets (multiplying individual numbers in subsets):
        divisible by 2 and 3 = (999) / 2*3 = 166
        divisible by 2 and 5 = (999) / 2*5 = 99
        divisible by 3 and 5 = (999) / 3*5 = 66

        divisible by 2,3 & 5 = (999) / 2*3*5 = 33
        
        Now putting values into:
        |2 U 3 U 5| = |2| + |3| + |5| - |2∩3| - |2∩5| - |3∩5| + |2∩3∩5|
        ==> we get 733 answer.

        --- WHAT ARE WE TRYING TO SOLVE THROUGH THIS PROGRAM ---
        Find the number of numbers between 1 and n which are divisible by any of the 
        prime numbers less than 20.

        Similar question, but only half the task: https://leetcode.com/problems/count-primes/

*/

# include <iostream>
# include <vector>

#define ll long long

using namespace std;

int main ()
{
    ll t;
    cin >> t;

    ll primes[] = {2,3,5,7,11,13,17,19};

    while (t--)
    {
        ll n;
        cin >> n;

        ll ans = 0;

        ll subsets = (1<<8) - 1; // 2^n - 1

        // to generate different bits placements
        for (ll i= 1; i <= subsets; i ++)
        {   

            ll denom = 1ll; // means the value 1, in data type of long long
            ll setBits = __builtin_popcount(i); // tells how many bits are set
        
            // j denotes the position of the bits being shift
            for (ll j = 0; j <= 7; j ++)
            {
                if (i & (1<<j))
                    denom = denom*primes[j];
            }
            if (setBits & 1) //if subset is of odd length
                ans += n/denom;
            else    // else the subset is of even length
                ans -= n/denom;
        }
        cout << "ANS: " << ans << endl;
    }

    return 0;
}