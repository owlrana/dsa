# include <iostream>
#include<string>
using namespace std;

// We are writing a function that reads everything except a new line
    // cin does not read new lines or spaces
    // cin.get() reads a single character
    // put a loop to read characters till you get a new line 
    // we are passing a delimiter for the user to choose what is considered to be a breaking pt. for input
void readLine(char a[], int maxLen, char delimiter) {

    int i = 0;
    char ch = cin.get();
    while (ch!= delimiter) {
        a[i] = ch;
        i ++;
        if (i == maxLen-1) { // last space of array should be reserved for Null Character
            break;
        }
        ch = cin.get(); // ask again to check if the user has entered a line
    }

    // once out of the loop
    a[i] = '\0'; // to terminate the char array with the null character in the end
    return;

}

int main ()
{
    char a[1000];
    char delimiter = '\n';
    readLine(a, 1000, delimiter);
    cout << a << endl;

    // But this is an already built in method provided by C++
    // it is caleld getline()

    cin.getline(a, 1000, '$');
    // can also run as cin.getline(a, 1000); // the third one is new line by default
    cout << a << endl;

    char whitespace;
    cin >> whitespace;
    
    // can also use strings
    string myString;
    getline(cin, myString);
    cout << myString;


    return 0;
}