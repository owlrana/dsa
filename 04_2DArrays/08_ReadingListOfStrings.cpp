# include <iostream>
using namespace std;

int main ()
{
    // Read a list of strings and we will store them in a 2D Character Array
    int n;
    cin >> n;

    cin.get(); // to consume the \n character followed after n

    char a[100][1000];

    // taking the inputs row by row
    for (int i = 0; i < n; i ++) {
        cin.getline(a[i], 1000);
    }

    cout << endl;

    // Printing out all the strings
    for (int i = 0; i < n; i ++) {
        cout << a[i] << endl;
    }

    return 0;
}