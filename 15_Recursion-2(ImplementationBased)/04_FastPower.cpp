// How to calculate the power of a number using recursion (naive + optimised "fast" method)

/*
    in faster approach, we try to make advantage of the fact that:
        a^n = a^((n/2)^2) ---- if n is EVEN
        a^n = a * a^((n/2)^2) ---- if n is ODD

*/

# include <iostream>
using namespace std;

int power (int a, int n) // has a call stack of N depth (O(n) Time Complexity)
{
    // base case first
    if (n == 0)
        return 1;
    
    return a * power(a, n - 1);
}

int fast_power(int a, int n)
{
    // base case first
    if (n == 0)
        return 1;
    
    // recursive case
    // int even_power = fast_power(a, n / 2) * fast_power(a, n / 2); // VERY VERY INEFFICIENT AS 2 REC
    
    // this recursive case is much more efficient
    int even_power = fast_power(a, n / 2); // calculate a^(n/2)
    even_power *= even_power;

    if (n & 1) // if the number is odd...
        return even_power * a;
    // otherwise we do not need to multply another extra term, just return smaller answer
    return even_power;
}

int main ()
{
    int a, b;
    cin >> a >> b;

    cout << power(a, b) << endl;
    cout << fast_power(a, b) << endl;

    return 0;
}