// to find the nth term of a fibonacci series

# include <iostream>
using namespace std;

int fibonacci(int n)
{
    // 1. first always figure out the base case
    if (n == 0 or n == 1)
        return n;
    
    // 2. then create recursive case
    // return fibonacci(n-1) + fibonacci(n-2); // can also do this in a single line
    int term1 = fibonacci(n-1);
    int term2 = fibonacci(n-2);
    return term1 + term2;
}

int main ()
{
    int n;
    cin >> n;

    cout << fibonacci (n) << endl;

    return 0;
}