//  https://leetcode.com/problems/subarray-sums-divisible-by-k/
//  also similar to https://leetcode.com/problems/check-if-array-pairs-are-divisible-by-k/

// TIME LIMIT EXCEEDED ERROR!! COULD NOT USE BRUTE FORCE!!!
//  We need to find a better approach than brute force, as the number of elements can be very large
//  and we cannot afford to create all subarrays

/*
    We use:
                        ----- THE PIGEON HOLE PRINCIPLE -----
    Pigeon Hole Prinicple: If you have 'n' number of holes and 'n+1' number of pigeons,
    and you want to allocate pigeons to these holes, AT LEAST ONE HOLE WILL HAVE 2 PIGEONS.

    So for our question, 
        We have the numbers: 
            1  3  2  6  4

        1.  we will have to create an array of cumulative sum
            0  1  4  6  12  16
            where, b - a represents the sum between indices b and a

        2.  Now, we need a substring such that the mod of this sum comes out as zero.
            So, mathematically we need to find: 
                (b - a) % n = 0;
                which can also be written as:
                    (b % n) - (a % n) = 0
                or  (b % n) = (a % n)
            which just means, that the mod of an index in this array we created, should be equal

        3.  Now taking the mod for above array, we get the third array of mods of cumulative sum:
            0  1  4  1  2  1
            (here all the value will be between 0 and 5 [not including 5 as 5%5 = 0])
            Thus, all we need to do is check which 2 or more places have the same value,
            then select that as a substring and map it to the first array.
        

        4.  Now we make a dictionary/map of these values and store their freq acc to num 
            (will only be 0 to N for a number N, eg in case of 5 we only have 0, 1, 2, 3 and 4)
            Now all we need to do is make combinations of the freq that are >= 2;
            just iterate through them and keep doing:
                ans += fC2 (wherever frequency is more than or equal to 2)

*/

# include <iostream>
# include <cstring> // for memset
using namespace std;
# define ll long long
ll a[1000005], pre[1000005]; //pre is the frequency array, we are skipping creating a prefix sum (csums)


int main ()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        memset(pre, 0, sizeof(pre));

        pre[0] =1;

        // read the input
        ll sum = 0;
        for (ll i = 0; i < n; i ++)
        {
            // building cumulative sum and then frequency array directly
            cin >> a[i];
            sum += a[i];
            sum %= n;
            sum = (sum + n) % n;
            pre[sum]++; // increase the frequency of this particular sum
        }

        ll ans = 0;
        for (ll i = 0; i < n; i ++)
        {
            ll m = pre[i];
            ans += (m) * (m-1) / 2; // creating combinations
        }
        cout << ans << endl;
    }

    return 0;
}