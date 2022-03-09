/*

String class is a part of C++ STL (Standard Template Library)

This provides as an alternate to character array.
String class is like a "container" and not a data structure.

*/
# include <iostream>
# include <cstring>
using namespace std;

int main ()
{   
    // six ways to initialise a string using C++'s STL String Class
    string s0; 
    string s1("Hello!");
    string s2 = "Hellowwwww!";
    string s3(s2); // s3 will be copied from s2
    string s4 = s3; // this also copies the contents of s3 to s4
    char a[] = {'a', 'b', 'c', 'd', '\0'};
    string s5(a);

    // to check if a string is empty or not
    if (s0.empty()) {
        cout << "THIS IS EMPTIESZZZ" << endl;
    }

    // Append
    s0.append("Hellow brother");
    cout <<s0<<endl;

    s2 += " yo baby i just appended the hell out of this string!";
    cout << s2 << endl;

    // Remove or erase the contents of the string
    cout << s0.length() << endl;
    s0.clear();
    cout << s0.length() << endl;

    // Compare two strings
    s0 = "Apple";
    s1 = "Mango";
    cout << s0.compare(s1) << endl; // returns an integer ==0 equal, > 0 or < 0
    // lexicographical order (Eg. if s0 is small it returns a negative number).
    
    if(s0 < s1)
        cout << "s0 < s1"; // the less than operators are also overloaded for the strings
    else
        cout << "s1 < s0";
    
    // Access ith character of the string
    cout << s1[0] << endl;

    // Find substrings
    string s = "I want to have Apple Juice"; // suppose you want to find "Apple"
    int idx = s.find("apple"); // returns - 1 if not found
    cout << idx << endl;

    // Remove a word from the string
    string word = "Apple";
    idx = s.find("Apple");
    int len = word.length();
    s.erase(idx, len+1); // + 1 is done to remove that extra space before the next word
    cout << s << endl;

    //Iterate over all the characters in the string
    for (int i = 0; i < s1.length(); i ++) {
        cout << s[i] << ": ";
    }
    cout << endl;

    // Iterators ("auto" automatically detects the data type and assigns it to the variable)
    for (auto it = s.begin(); it != s.end(); it ++) {
        cout << (*it) << endl;
    }

    // s.begin() returns an iterator of its type, you can also write "string::iterator" instead of auto here

    // For Each Loop (Supported in C++11 onwards)
    for (auto c:s1) { // for every c in s1, do this (automatically breaks into parts like python does)
        cout << c << ".";
    }

    // here auto returns a "char" type for c, and iterates over s1

    return 0;
}

// can check out documentation for more information on more functions or time complexities