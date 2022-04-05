// IMPLEMENTING A PHONEBOOK USING UNORDERED_MAP AND VECTORS

#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

int main()
{
    unordered_map<string,vector<string> > phonebook;
    
    
    phonebook["Rahul"].push_back("8447917232");
    phonebook["Shruti"].push_back("1234567890");
    phonebook["Mummy"].push_back("8802644872");
    phonebook["Dad"].push_back("965882818");
    phonebook["Dad"].push_back("925757411");
    phonebook["Mummy"].push_back("9643568942");
    
    // iterating over all contacts and phone numbers
    for (auto p: phonebook)
    {
        cout << "Name " << p.first << "-> ";
        for (string s: p.second)
        {
            cout << s << ", ";
        }
        cout << endl;
    }


    return 0;
}