// from https://www.techiedelight.com/find-n-digit-binary-strings-without-consecutive-1s/

#include <iostream>
#include <string>
using namespace std;
 
// Function to count all n–digit binary strings without any consecutive 1's
int countStrings(int n, int last_digit)
{
    // base case
    if (n == 0) {
        return 0;
    }
 
    // if only one digit is left
    if (n == 1)
    {
        if (last_digit) {   // if the last digit is 1
            return 1;
        }
        else {              // otherwise, if the last digit is 0
            return 2;
        }
    }
 
    // if the last digit is 0, we can have both 0 and 1 at the current position
    if (last_digit == 0) {
        return countStrings(n - 1, 0) + countStrings(n - 1, 1);
    }
    // if the last digit is 1, we can have only 0 at the current position
    else {
        return countStrings(n - 1, 0);
    }
}
 
int main()
{
    // total number of digits
    int n = 5;
 
    cout << "The total number of " << n << "-digit binary strings without any "
        "consecutive 1's are " << countStrings(n, 0);
 
    return 0;
}