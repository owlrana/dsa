/* 
    1.  Normal algorithm is to find the number of factors, if they come out to be 2, the num is prime.
        This is the Brute Force way. Complexity is around O(n^2).

    2.  A Slightly better way would be to iterate from 2 to square root of n, if any divisor is found
        then the number is not prime and if nothing is found then it means that the num is prime!
        This significantly decreases the complexity but yet, this is just not enough 
        as the complexity is still O(n*root(n))

    Now we introduce a much better way, all thanks to:

    3.  The Prime Sieve Theory
        Suppose you are given a range eg. 1 to 30 to find prime numbers:

        1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30
        So, 
            1. You mark 1 and Multiples of 2s as Not prime
                N N   N   N   N   N     N     N     N     N     N     N     N     N     N     N
                1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30
            2. Then you check if a number is marked or not, 
                1.  if it is marked, SKIP IT
                2.  if it is NOT marked, it means that we could not find a num smaller than that as divisor
                    So, you need to mark it as Prime (Y), and mark all its multiples as Not Prime (N)
                    N N Y N   N   N N N     N     N  N  N     N     N  N  N     N     N  N  N     N
                    1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30
            3. Repeat this for next ones.
                
                For 5: Marked as prime, marking multiples as not prime...
                N N Y N Y N   N N N     N     N  N  N     N     N  N  N     N  N  N  N  N     N
                1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30

                For 7: Marked as prime, marking multiples as not prime
                N N Y N Y N Y N N N     N     N  N  N     N     N  N  N     N  N  N  N  N     N
                1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30

                For 11: Marked as prime, marking multiples as not prime
                N N Y N Y N Y N N N  Y  N     N  N  N     N     N  N  N     N  N  N  N  N     N
                1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30

                For 13: Marked as prime, marking multiples as not prime
                N N Y N Y N Y N N N  Y  N  Y  N  N  N     N     N  N  N     N  N  N  N  N     N
                1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30

                For 17: Marked as prime, marking multiples as not prime
                N N Y N Y N Y N N N  Y  N  Y  N  N  N  Y  N     N  N  N     N  N  N  N  N     N
                1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30

                .
                .
                .
                Similarly we do the rest of them:
                N N Y N Y N Y N N N  Y  N  Y  N  N  N  Y  N  Y  N  N  N  Y  N  N  N  N  N  Y  N
                1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30

    4.  Optimised Prime Sieve.
        As we observed, as we go along the array, we do not need to find and check multiples of
        previous elements we already removed multiples for
        For eg. for 5, we already marked 2*5 and 3*5 and 4 is already a multiple of 2, so 2*2*5 is clear
                Thus, we only need to start by finding from num*num instead of num*1, num*2, num*3,,,
        So, when at 5, we mark it as prime, then directly look at 5*5 = 25 if it is marked or not.
        This also saves time by saving on iterations.

    5.  Optimised Optimised Prime Sieve.
        In this, not only we start multiples from num*num, but we also skip ALL even numbers.
        So basically:

        Multiples of 2 are not even considered, thus saving even more computations
        N   Y   Y   Y   N    Y     Y     N     Y     Y     N     Y     N     N     Y   
        1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30

        Complexity: N/2 + N/3 + N/5 + N/7 + N/11 ....... (N/ PRIME NUMBERS)...
        Not proving here, but it is computed as O(N LogLogN) which is approximately Linear!!

*/

// Prime Sieve Program

# include <iostream>
# include <vector>

#define ll long long

using namespace std;

void prime_sieve (vector<int> &p)
{
    // first marks all odd numbers as prime, because they can be potential primes (ignoring 2 multiples)
    for(int i = 3; i <= p.size(); i += 2)
        p[i] = 1;

    // Sieve - Assign them as prime and remove the multiples of those odd numbers as we find them
    for (ll i = 3; i <= p.size(); i += 2)
    {
        // if the current number is NOT marked, it is prime
        if (p[i] == 1)
        {
            // mark all multiples of i as not prime
            for (ll j = i*i; j <= p.size(); j = j+i)
                p[j] = 0;
        }
    }

    //special case
    p[2] = 1;
    p[1] = p[0] = 0;

}

int main ()
{
    int n;
    cin >> n;

    vector<int> p (n, 0);
    prime_sieve(p); // this function fills the indices with 0s and 1s, 1s = PRIME NUM

    // lets print prime upto the rane n
    for (int i = 0; i <=n; i ++)
    {
        if (p[i] == 1)
            cout << i << " ";
    }

    return 0;
}