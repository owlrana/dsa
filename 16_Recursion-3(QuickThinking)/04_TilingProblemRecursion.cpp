/*
    ---PLACE THE TILES ---
    Given a wall of size 4 x N, and tiles of size (1,4) and (4,1)
    In how many ways you can build the wall?

    This question:
    https://www.geeksforgeeks.org/count-number-of-ways-to-fill-a-n-x-4-grid-using-1-x-4-tiles/

    Similar to:
    https://leetcode.com/problems/tiling-a-rectangle-with-the-fewest-squares/
*/

# include <iostream>
using namespace std;
int doTiling(int N)
{
    // base case
    if (N <= 3)
        return 1;
    else
    if (N == 4)
        return 2;

    return doTiling(N-1) + doTiling(N-4);
}

int main ()
{
    int N;
    cout << "ENTER THE VALUE:" << endl;
    cout << "The size of the wall is : 4 x ";
    cin >> N;

    cout << "Number of ways is: " << doTiling(N) << endl;

    return 0;
}