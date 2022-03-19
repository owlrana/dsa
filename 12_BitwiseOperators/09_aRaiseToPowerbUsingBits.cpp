// kind of like https://leetcode.com/problems/powx-n/ 

/*
    So normally if we are given a = 2 and we need to raise it to power b = 5;
    What we would do is:
        loop 5 times [ a * a ]

    but this is not a very efficient approach. Using bits, we have another approach:
    Do as follows:
        1. initialise ans = 1
        2.  find out the bits of the power you are raising to
            Eg. 5 ( 0000 00101 )
        3.  have a number p initialised to a, and
            1.  for each bit it multiplies by itself (p = p*p)
            2.  for each SET bit it multiplies p to ans (ans = ans * p)
        4.  push n right sie by 1 value to get the next digit
        ... while n is not zero ...

    Eg. 
        Num N = a = 2
        Need to do 2^5, so clearly
        p = 5 = ( 0000 0101 )
        ans = 1
        p = a = 2 
            1.  for bit = 1: 
                    ans = p * ans = 2 
                    p = p*p = 4
                    N >> 1
            2.  for bit = 0:
                    p = p * p = 16
                    N >> 1
            3.  for bit = 1:
                    ans = p * ans = 16 * 2 = 32
                    p = p * p = 256
                    N >> 1
            .
            .
            .
            .
            
*/  

# include <iostream>
# include <vector>

using namespace std;

int power_optimised (int a, int n)
{
    int ans = 1;

    while (n > 0)
    {
        int last_bit = (n & 1);
        if (last_bit == 1)
            ans = ans * a;
        a = a*a;
        n = n >> 1;
    }
    return ans;
}

int main ()
{
    int a, n;
    
    cout << "Enter the number that you want to raise: ";
    cin >> a;
    cout << "Enter the Power that you want to raise to:";
    cin >> n;

    cout << power_optimised(a, n) << endl;

    return 0;
}