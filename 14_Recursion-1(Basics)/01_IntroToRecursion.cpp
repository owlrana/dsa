/*
    -- INTRODUCTION TO RECURSION --

    Recursion in CS is a method where solution to a problem depends on solution to
    smaller instances of the same problem.
    
    Eg. Given an array find out the sum of array
        -   break array into two parts, and then combine for sum
        -   keep repeating until the array size is 1 (known as the base case)
    [EVERYWHERE, OUR MOTIVE IS TO FIND SUM ONLY]

    This is one of the trickiest topics in Programming.    
    Tricky topics which require time, patience and hardwork to visualise what is going on:
        1.  Recursion
        2.  Dynamic Programming
        3.  Graphs
    
    Recursion is very important as it is used in Trees, Lists and many other topics as we'll see.

    -- PARTS OF A RECURSIVE ALGORITHM --
    1.  Base Case
    2.  Recursive Call (to work towards the Base Case)

    Let us understand this using an easy example of Factorials.
    Factorial of N = N!
    N! = N*(N-1)! = N(N-1)(N-2)! and more...
    So here,
        we are just calling the same function on our data
        These are the recursive calls.
        Base case is 1! (as we know the answer to 1! is 1 ALWAYS)
    More formally,
        Base Case: f(1) = 1
        Recursive Case: f(n) = n * f(n-1)
    
    Now we write the code for this factorial function using recursion
    But we need to have faith in recursion. For this leap of faith we have:

    -- EASIEST WAY TO APPROACH A RECURSIVE ALGORITHM --
    "Magical" Recursion Rule : Principal of Mathematical Induction (PMI)
        1.  Figure out the base case.
        2.  Assume sub-problems can be solved by recursion (leap of faith is important).
        3.  Using the sub-problems, write the answer to the current problem.

*/

# include <iostream>
using namespace std;

int fact(int n)
{
    if (n == 1)
    {
        return 1;
    }
    
    return (n * fact(n-1));
}

int main ()
{
    int n;
    cin >> n;

    cout << fact(n) << endl;

    return 0;
}