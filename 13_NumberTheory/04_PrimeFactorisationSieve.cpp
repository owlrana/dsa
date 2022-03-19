/*
    Code by CB
*/

# include <iostream>
# include <vector>
using namespace std;

#define ll long long

vector<int> primeSieve (vector<int> &p)
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
    return p;
}

vector<int> factorize (int m, vector<int> &primes)
{
    vector<int> factors;
    factors.clear(); // empty vector

    int i = 0; //1st prime number is on the zeroeth index of primes array p
    int p = primes[0];

    while (p*p <= m)
    {
        if (m % p == 0)
        {
            factors.push_back(p);
            while(m%p == 0) // reduce the number so that this factor no longer remains
            {
                m = m/p;
            }
        }
        i ++;
        p = primes[i];
    }

    if (m!=1)
        factors.push_back(m); // if the number is still not zero, it means that:
                              // the number is a factor of itself.

    return factors;
}

int main ()
{   
    vector<int> p (1000000, 0);
    vector<int> primes = primeSieve(p);

    int no;
    cin >> no;

    vector<int> factors = factorize(no, primes);
    for (auto f: factors)
    {
        cout << f << " " << endl;
    }
    
    return 0;
}