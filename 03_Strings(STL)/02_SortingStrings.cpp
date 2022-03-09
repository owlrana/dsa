// Given a list of strings, you need to sort them

# include <iostream>
# include <algorithm>
# include <string>
using namespace std;

//out own comparator function, check line 31
bool compare(string a, string b) {
    // suppose we want to return on basis of lengths
    if (a.length() == b.length()) { // if both have same length, use lexi sorting
        return a < b;
    }
    return a.length() < b.length();
}

int main() 
{

    int n;
    cin >> n;
    cin.get(); // to consume any extra enter ('\n') after cin>>

    string s[100]; // created an array of strings

    // taking input of n strings
    for (int i=0; i < n; i ++) {
        getline(cin, s[i]); //cin.getline() does not work for strings, you need to make a call to getline here
    }

    sort(s, s+n, compare); // starts sorting from s to s+n (lexicographically, if comparator not given!)
    // this takes 3 arguments: sort(startAddress, endAddress, comparator)

    // check for output
    for (int i=0; i < n ; i++) {
        cout << s[i] << endl;
    }

    return 0;
}