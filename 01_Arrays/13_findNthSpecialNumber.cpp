// finding nth special number
// number is special if it ends with 0, 1, 2, 3, 4, 5

#include<iostream>
using namespace std;

int main()
{
    int n;
    cout << "Find Nth special number (0,1,2,3,4,5 in units place)." << endl;
    cout << "Enter the value of N: ";
    cin >> n;

    int count = 0;
    int i = 0;
    for (; count < n; i ++)
    {
        int unit = i % 10;
        // cout << unit;

        switch (unit)
        {
            case 0:
            case 1: 
            case 2:
            case 3:
            case 4:
            case 5: count += 1;
                    break;

            default: continue;
        }
    }

    cout << i-1;

    return 0;
}