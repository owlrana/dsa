// Working with character arrays

#include <iostream>
using namespace std;

int main()
{
    // char a[100]; // initialising a charcter array which will contain AT MOST 100 characters
    
    char a[5] = {'a', 'b', 'c', 'd', '\0'}; // '\0' is the NULL character and each string MUST be ended by it
    char b[10] = {'a', 'b', 'c', 'd'}; // This can give garbage value if you ask for output!

    // difference of normal array and character array
    int c[] = {1,2,3};
    char d[] = {'1', '2', '3', '\0'};

    cout << c << endl; // this will output the location of the array (mem location)
    cout << d << endl; // this will output the contents of our character array
    // this is because of operator overloading, in case of character array the cout func is overloaded
    // thus this array is printed char by char until you hit NULL character by C++ Developers

    // you need to take int array as a loop but in character array:
    char s[10];
    cin >> s; // takes in a word (when you type word in input buffer, while reading the \n is converted into \0)
    cout << s; // outputs a word

    // thus, the size of the character array is always one amount extra as it needs to contain \0
    char s1[] = {'h', 'e', 'l', 'l', 'o'}; // this may also print any garbage value alongside
    char s2[] = "hello"; // this will show 6 bytes

    cout << s1 << " " << sizeof(s1) << endl;
    cout << s2 << " " << sizeof(s2) << endl;

    //  This is why you should always terminate a character array by Null Character

    return 0;
}