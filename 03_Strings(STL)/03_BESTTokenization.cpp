// strings can be tokenized using getline function easily

#include<iostream>
#include<string>
#include<vector>
#include<sstream> // INCLUDE THIS FILE
using namespace std;

int main()
{
    string mystr;
    getline(cin, mystr); // DO NOT USE cin, use getline to get whitespaces!!
    stringstream ss(mystr); // CONVERT YOUR STRING INTO SSTREAM OBJECT

    vector<string> tokens;
    string tempString; // WE WILL BE USING THIS STRING TO STORE SUBSTRINGS

    while (getline(ss, tempString, ' '))
    {
        tokens.push_back(tempString); // word is stored in tempString, which we put into tokens
    }

    // output check
    for (int i = 0; i < tokens.size(); i ++)
    {
        cout << tokens[i] << ", ";
    }
    cout << endl;

    return 0;
}