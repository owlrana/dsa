// multiplying using recursive algorithm

# include <iostream>
using namespace std;

int multiplication(int a, int b)
{
    cout << "Value of A is: " << a << ", Value of B is: " << b << endl;
    
    if (b == 1)
        return a;

    return a + multiplication(a, b-1);
}

int main ()
{
    int a, b;
    cout << "Enter the first number: ";
    cin >> a;
    cout << "Enter the second number: ";
    cin >> b;

    cout << multiplication(a,b) << endl;

    return 0;
}