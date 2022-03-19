/*
    https://www.geeksforgeeks.org/friends-pairing-problem/

    we select two scenarios for any given N:
        1.  Either he goes in single
            ==> combinations possible = 1 only
        2.  Or then he takes in a date with him
            ==> combinations possible is = 
                can take any of the (n-1) people while the rest of the people (n-2) paired in diff ways
*/

# include <iostream>
using namespace std;

int pairing (int n)
{
    // base case first
    if ((n == 0) or (n == 1)) // there is only one way to arrange if 1 person is picked or NONE is picked
        return 1;
    if (n == 2)   // there will be two arrangements for two people 
        return 2; 

    // recursive calls
    return (pairing(n-1) + ((n-1) * pairing(n-2))); // n-1 number of other people can be paired with this while pairing for 2 people
}

int main ()
{
    int n;
    cout << "Enter the value of n: "; 
    cin >> n;
    cout << pairing(n);

    return 0;
}