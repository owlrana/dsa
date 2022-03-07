// C++ also offers some built in techniques to sort containers so each time you dont have to
// build a new function each time you want to sort something
// this can be used in arrays/ vectors etc any container and is much more efficient

// sort(start_position, end_position) 
// start is already included but you ALWAYS NEED TO GIVE THE END till where you want to sort!!

# include <iostream>
# include <algorithm>

// Defining a comparator function. useful to decide YOUR OWN COMPARATOR FUNCTION acc to value, digits, etc
// READ LINE 44
bool compare (int a, int b) {
    // cout << "Comparing " << a << " and " << b << endl; // to see how many times it is called
    return (b > a);
}

using namespace std;

int main ()
{
    int n, key;
    cout << "Enter the size of the array you want: ";
    cin >> n;
    cout << endl;

    int arr[1000];

    cout << "Input the elements: ";
    cout << endl;
    for (int i = 0; i < n; i ++) {
        cin >> arr[i]; 
    }

    // calling the sort() function
    sort(arr, arr+n);

    cout << "Input the elements: ";
    cout << endl;
    for (int i = 0; i < n; i ++) {
        cout << arr[i] << ", "; 
    }

    // to sort in a decreasing order:
    // define a comparator function before main
    // then we send a FUNCTION AS A PARAMTER INTO THE SORT FUNCTION:
    sort(arr, arr+n, compare);

    cout << "Input the elements: ";
    cout << endl;
    for (int i = 0; i < n; i ++) {
        cout << arr[i] << ", "; 
    }

    return 0;
}

// ********** UNDERSTANDING THE WORKING OF COMPARATOR FUNCTION **********
/*

    --> HOW DOES ONE PASS SOME FUNCTION AS A PARAMETER?
        Functions in C can also take other functions as their parameters.
        To create a function def that accepts other funcs as arg you need to send return type, *ptr to func, and the arguments it accepts
        Eg. void myFunction(int a, int b, bool (&compare) (int a, int b)) {
            --body of the function that you created--
            use compare function in your logic to return things and further do other stuf.....

            This is basically how Algorithms header file uses the sort() func and can accept criteria by you
        }
*/