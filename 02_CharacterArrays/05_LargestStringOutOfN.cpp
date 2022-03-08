// Problem to find out the longest string out of N stringss

// Here we need to tackle with following problems
/*
    1. How do we get the input of N strings?
    2. How do we store so many strings?
    3. How do we find out which one is the biggest?

---> We wont store all the strings, we will just store 2 strings: 1. Largest till now & 2. Current String
*/

# include <iostream>
# include <cstring> 

using namespace std;

int main ()
{

    int n;
    cin >> n;
    // when we do cin, it takes '\n' as queue to INPUT and thus this '\n' will be extra input in our func
    cin.get(); // this is required otherwise out cin.getline(a, 1000) in function will take this as input

    int length = 0; // to store the length of current string
    int largestLength = 0; // to store the length of the string
    char largestStr[1000]; // to store the string

    char a[1000]; // largest length of any string
    for (int i = 0; i < n; i ++) {
        cin.getline(a, 1000); // taking input in same variable again and again so not wasting memory
        //cout << a << endl;
        length = strlen(a);
        if (length > largestLength) {
            largestLength = length;
            strcpy(largestStr, a); // comes in the <cstring> header file, it is used to copy one string to another
        }
    }

    cout << largestStr << " has a length of: " << largestLength;


    return 0;
}