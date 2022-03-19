// Calculates the number of divisors using a prime number table

# include <iostream>
# include <vector>
# include "primeSieve.h"
# define ll long long
using namespace std;

int no_of_divisors(int m, vector<ll> &primes)
{
    int i = 0;
    int p = primes[0];
    int ans = 1;
    
    while (p*p <= m)
    {
        if ((m % p) == 0)
        {
            int cnt = 0;
            
            while ((m % p) == 0)
            {
                cnt ++;
                m = m / p;
            }
            ans = ans * (cnt + 1);
        }
        i ++;
        p = primes[i];
    }

    if (m!= 1)
        ans = ans * 2;
    return ans;
}

int main ()
{
    ll n;
    cin >> n;
    vector<ll> primes = primeSieve(n);

    int divs = no_of_divisors(n, primes);
    cout << divs << " Divisors!" << endl;

    return 0;
}