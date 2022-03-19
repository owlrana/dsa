// program to turn character into int values recursively
// for this, we do not need to go into the call stack's depth first, we can compute as we go along

# include <iostream>
# include <cstring>
using namespace std;

int stringToInt (char num[], int len, int unit)
{
    // base case first
    if (len == 0)
        return 0;

    // recursive call
    int digit = (int(num[len-1]) - 48) * unit;
    int number = digit + stringToInt(num, len-1, unit*10);

    return number;
}

int main ()
{
    char num[] = "12344";
    int len = strlen(num);

    int value = stringToInt(num, len, 1);
    cout << value + 1 << endl;

    return 0;
}