// printing numbers from and upto N
// Eg. for input 4, print 1 2 3 4 and 4 3 2 1

# include <iostream>
using namespace std;

void dec(int n)
{
    if (n == 0)
        return;
    
    cout << n << " ";
    dec(n-1);
    // using bottom call and printing while going up. Nothing when coming back.
}

void inc(int n)
{
    if (n == 0)
        return;
    
    inc(n-1);
    cout << n << " ";
    // using top call stack going to bottom while the function call is ending.
}

int main ()
{
    int n;
    cin >> n;

    dec(n);
    cout << endl << endl;
    inc(n);
    cout << endl << endl;

    return 0;
}

/*
    ANYTHING BEFORE THE FUNCTION CALL IS A BOTTOM TO TOP APPROACH
    AND IF IT IS AFTER, THEN IT IS TOP TO BOTTOM OF FUNCTION CALL
*/