/*
    A very popular question.
    Generate all prime numbers within two given numbers (a,b)
    input asks how many test cases wanted:
    for each test case, input a and b:
        1 <= a <= b <= 1000000000 (it is huge)
        also, m-n <= 10^5 ( this is usually not give, so this can be a hint to segmented sieve)

    Well, we cannot work with regular Sieve as with that method we can only create
    a sieve array of size 10^8. So clearly, the constraints exceed our boundations.

    Approach:
    we are going to map our m to n boundary in the index. Means:
    Our Vector "RequestedRange" will have:
        mth index will be located at m-m = 0th index
        nth index will be located at n-m = n-mth index

    Then we will compute a vector of prime numbers "BasePrimes" from Prime Sieve upto root of n (i*i <= n),
    and use that vector to mark multiples of those prime numbers in our RequestedRange vector.
    Thus while traversing, if we find numbers that are not marked, it means it is prime!

*/

# include <iostream>
# include <vector>
using namespace std;

const int N = 100000; // root of 10^9 constraint of the question
vector<int> primes; // do not need the index of these, just need primes to iterate through

int p[N] = {0}; // to mark numbers as prime or not, need the index number too

void sieve()
{
    for (int i = 2; i <=N; i ++)
    {
        if (p[i] == 0)
        {   
            // store i in the primes vector
            primes.push_back(i);
            
            // mark all multiples of i as not prime
            for (int j = i; j <=N; j += i)
            {
                p[j] = 1; // not prime
            }
        }
    }
}

int main ()
{
    sieve(); // build the sieve once for all queries

    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> m >> n; // m is the smaller value

        bool segment [n-m+1];
        for (int i = 0; i < n-m+1; i ++)
            segment[i] = 0;

        // Segmented Sieve Logic here
        // need to find multiple of p that is closest to m
        // can do it by (m/p)*p

        for (auto x: primes)
        {
            // when to stop, as the prime vector is very large and the range given may be very slim
            if (x*x > n)
                break;

            int start = (m/x)*x;

            // correction for if range and prime sieve overlap
            if (x >= m and x<=n)
                start = x*2; // needs to avoid its first occurrence in it

            // mark all multiples of x, in the range start to n as not prime
            for (int i = start; i <= n; i += x)
                segment[i-m] = 1;

        }
        // loop over range m .. n and print the primes
        for (int i = m; i <= n; i ++)
        {
            if (segment[i-m] == 0 and i != 1)
                cout << i << endl;
        }
    }


    return 0;
}