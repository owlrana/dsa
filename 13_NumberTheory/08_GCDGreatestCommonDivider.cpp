// HCF is the same as GCD
// this is not the brute force method, in which we keep iterating from 1 to min(a,b) to get common factor
// is similar to this question: https://leetcode.com/problems/x-of-a-kind-in-a-deck-of-cards/

// intuition: https://i.imgur.com/B2DYKlN.png

# include <iostream>
# include <vector>

using namespace std;

int gcd (int a, int b)
{
    return b==0? a : gcd(b, a%b); // this handles base case as well as recursive calls. 
}

int main ()
{
    int n1, n2;
    cin >> n1 >> n2;
    cout << gcd(n1, n2) << endl;

    return 0;
}