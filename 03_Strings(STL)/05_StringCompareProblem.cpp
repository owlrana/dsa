// in this problem you need to accept a no. of strings and then tokenise and create columns, then 
// compare the key of column given by the user according to the user's specification (lexic or numeric)
// user can also choose to reverse the answer by providing "true" as input; otherwise "false"

/*
    USER INPUTS - >>
                        3
                        93 022
                        82 022
                        77 13
                        2 false numeric
                        // 2 is the index you need to compare (022, 022, 13)
                        // no need to reverse your answer as user inputer false
                        // numeric is the type of comparison the user wants

    We will need 3 main things for this"
    1. Tokenization - convert the inputs into columns of data
    2. convert keys into numeric values 
    3. Sorting (compare them according to what the user inputted)
        in the end we can just reverse the answer if user input "true"

*/

# include <iostream>
# include <cstring>
# include <algorithm>

using namespace std;

string extractStringAtKey(string str, int key) {

    //strtok
    char *s = strtok((char *) str.c_str(), " "); // strtok() only accepts char* type, which we had to typecast
    while (key > 1) {
        s = strtok(NULL, " "); // this is how we extract next token
        key--;
    }

    return (string) s; // return the string by typecasting again 

}

int convertToInt(string s) {
    int ans = 0;
    int p = 1;
    for (int i = s.length()-1; i >= 0; i--) {
        ans += ((s[i] - '0')*p);
    }
}

bool numericCompare(pair<string, string> s1, pair<string, string> s2) {
    // first need to exctract key and turn it into the numerical value
    string key1, key2;
    key1 = s1.second;
    key2 = s2.second;

    return convertToInt(key1) < convertToInt(key2);
}

bool lexicoCompare(pair<string, string> s1, pair<string, string> s2) {
    // first need to exctract key and turn it into the numerical value
    string key1, key2;
    key1 = s1.second;
    key2 = s2.second;

    return key1 < key2; // by default strings can be lexico compared
}

int main()
{
    int n;
    cin >> n;
    cin.get(); // consume the next line (whitespace, \n)

    // store strings in a string array
    string a[100];
    for (int i = 0; i < n; i++) {
        getline(cin, a[i]); // cant use cin as it wont take in whitespaces and cin.getline() doesnt work in strings datatype
    }

    // reading inputs
    int key;
    string reversal, ordering;

    // taking input for key, reveral and ordering
    cin >> key >> reversal >> ordering;

    // pairing values for STRING and the KEY VALUE in strPair array
    pair <string, string> strPair[100]; // both first and second element is of string type

    for (int i = 0; i < n; i++) {
        strPair[i].first = a[i];
        strPair[i].second = extractStringAtKey(a[i], key);
    }

    // Now we need to sort
    if (ordering == "numeric") {
        sort(strPair, strPair+n, numericCompare);
    }
    else {
        sort(strPair, strPair+n, lexicoCompare);
    }

    if (reversal == "true") {
        for (int i = 0; i < n/2; i++) {
            swap(strPair[i], strPair[n - i - 1]);
        }
    }

    // print the output
    for (int i = 0; i < n; i ++) {
        cout << strPair[i].first << endl;
    }

    return 0;
}