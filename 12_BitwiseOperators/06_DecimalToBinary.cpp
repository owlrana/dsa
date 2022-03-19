// Program to turn decimal numbers into binary

# include <iostream>

using namespace std;

// this function find out values in reverse order, but then multiplies the unit's power
// to get the final correct answer ...
int decimalToBinary (int n)
{
    int ans = 0;
    int power = 1;
    while (n > 0)
    {
        int lastBit = n & 1;
        ans = ans + lastBit*power;
        n = n >> 1;
        power = power * 10;
    }
    return ans;
}

int main ()
{
    int n;
    cin >> n;
    cout << decimalToBinary(n);

    return 0;
}