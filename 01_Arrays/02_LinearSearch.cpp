// LINEAR SEARCH
// traverse the array and find if the element is in there or not
// if the element is not found and we have surpassed the last index, then it is not present

# include <iostream>

using namespace std;

int main()
{

    int n, key;
    // user inputs the size of the array they want 
    cout << "Enter the size of the array you want: ";
    cin >> n;
    cout << endl;

    // assuming that the user inputs the max size (which is 1000, we assume)
    int arr[1000];

    // taking the input from the user, user can also input all values sep by space and it will work
    cout << "Input the elements: ";
    cout << endl;
    for (int i = 0; i < n; i ++) {
        cin >> arr[i]; 
    }

    // now asking the user what is to be searched
    cout << endl;
    cout << "Enter the Element you want to search for: ";
    cin >> key; 
    cout << endl;

    // now searching if the element is in the array or not
    // linear search algorithm
    int i = 0; // defining i outside because need to use this later to check if whole array is searched
    for (i; i < n; i ++) {
        if (key == arr[i]) {
            cout << key << " found at " << i << " index!\n";
            break; // breaking as we don't need to find further occurrences. Found once, thus we stop.
        }
    }

    // after the loop is over and "break;" was not run, the value of i would have reached n
    // so we are checking if the whole array was searched for
    if (i == n) {
        cout << key << " element was not found...";
    }
    
    return 0;
}