// To find out the LCM of a number

/*
    There is a relationship between the GCD (HCF), LCM and the product of the numbers:
        GCD(a,b) * LCM(a,b) = a*b
    
*/

# include <iostream>
using namespace std;

int compute_gcd (int a, int b)
{
    return b==0? a : compute_gcd(b, a%b);
}

void compute_lcm (int a, int b)
{
    int gcd = compute_gcd (a, b);
    int lcm = (a * b) / gcd;
    cout << "LCM of " << a << " and " << b << " is: ";
    cout << lcm << endl;
}

int main ()
{
    int a, b;
    cout << "LCM Computer\nEnter number 1: ";
    cin >> a;
    cout << "Enter number 2: ";
    cin >> b;

    compute_lcm(a,b);

    return 0;
}