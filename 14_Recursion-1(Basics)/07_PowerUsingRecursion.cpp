// raise a number to a specific power using recursion

# include <iostream>
using namespace std;

int raiseToPower(int num, int power)
{
    if (power == 1)
        return num;
    
    return num * raiseToPower(num, power-1);
}

int main ()
{
    int num, power;
    cout << "Enter the number: ";
    cin >> num;
    cout << "Enter the power to raise: ";
    cin >> power;

    cout << raiseToPower(num,power) << endl;

    return 0;
}