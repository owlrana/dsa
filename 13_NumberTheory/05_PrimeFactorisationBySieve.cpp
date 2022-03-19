// Prime Factorisation code by me using Sieve

# include <iostream>
# include <vector>
# include "primeSieve.h" // can import directly, the file is located at:
// C:\Program Files\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\x86_64-w64-mingw32\include

# define ll long long

using namespace std;


int main ()
{
    int n;
    cout << "Enter the number you want to get Prime Factorisation of: ";
    cin >> n;

    vector<ll> factors;
    vector<ll> primes = primeSieve(n);
    // printVector(primes);

    for (auto x: primes)
    {
        if ((n % x) == 0)
        {
            factors.push_back(x);
            while (n % x == 0)
            {
                n = n/x;
            }
        }
    }

    printVector(factors);

    return 0;
}