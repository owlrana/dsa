// Making 2D Array of characters (in which each row represents a string, ends with NULL character)

# include <iostream>
using namespace std;

int main ()
{

    char a[][10] = {{'a', 'b', '\0'}, {'d', 'e', 'f', '\0'}}; // this will have 2 rows and 10 columns
    char b[][10] = {"ab", "hello"}; // in this case words are automatically terminated by a NULL
    char c[10][10];
    c[0][1] = 'C';
    c[0][9] = '\0';
    // you can also enter things char by char but make sure you do terminate by NULL or it isn't a string

    cout << a[0] << endl;
    cout << b[1] << endl;
    cout << c[0] << endl;

    return 0;

}