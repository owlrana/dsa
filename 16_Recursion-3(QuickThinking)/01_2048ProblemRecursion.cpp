/*
    -- PRINT NUMBER IN WORDS --
    We are given a number. We need to print it's digits.
    Eg. 
        2048
        two zero four eight

    we do this by recursion here.
        for input 2048, we do a recursive call on (204) and then we print for 8
            for input 204, we do rec call on (20) and print 4 later
                for input 20, rec call on (2) and print 0 later
                    final call for 2, print it
*/

# include <iostream>
using namespace std;

// 2 D character array that stores the digits in words
char words[][10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

void printDigits(int number)
{
    // base case first
    if (number == 0)
        return;

    int digit = number%10;
    printDigits(number/10); // not changing number, instead sending a new copy that is /10
    // needed the left most digit first, thats why we print AFTER the call (when at the top of call stack)
    cout << words[digit] << " ";
}

int main ()
{
    int number = 1998;

    printDigits(number);
    cout << endl;

    return 0;
}

