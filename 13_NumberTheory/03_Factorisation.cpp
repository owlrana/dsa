// Program to get factors of a number (or divisors)

# include <iostream>
# include <vector>
# include <algorithm>

using namespace std;

vector<int> findFactors (int n)
{
    vector<int> factors;
    // start from 1 and go to root of n and calculate two factors at a time
    for (int i = 1; i*i <= n; i ++)
    {
        if ((n % i) == 0)
        {
            factors.push_back(i);
            if (i*i != n)
                factors.push_back(n/i); // adding factor only if both are not the same
        }
    }
    //sort(factors.begin(), factors.end());
    return factors;
}

int main ()
{

    int n;
    cout << "Enter number for Prime Factorisation: ";
    cin >> n;

    vector<int> factors;
    factors = findFactors(n);

    for(auto x: factors)
        cout << x << ", ";
    cout << "\b\b " << endl;

    return 0;
}