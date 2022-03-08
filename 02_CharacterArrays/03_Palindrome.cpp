# include <iostream>
# include <cstring>

using namespace std;

bool isPalindrome(char a[]) {

    int i = 0;
    int j = strlen(a) - 1;

    while (i < j) {
        if (a[i] == a[j]) {
                i ++;
                j --;
        } else {
            return false;
        }
    }
    return true;
}


int main ()
{
    string rana;
    char checker[1000];
    cin.getline(checker, 1000);

    cout << isPalindrome(checker) << endl;
    
    return 0;
}