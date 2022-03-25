#include<iostream>
#include<stack>
using namespace std;

bool isValidExp(char* s)
{
    stack<char> stk;

    for (int i = 0; s[i] != '\0'; i++)
    {
        char ch = s[i];

        if (ch == '(')
        {
            stk.push(ch);
        }
        else if (ch == ')')
        {
            if (stk.empty() and stk.top() != '(')
                return false;
            stk.pop();
        }
    }
    return stk.empty(); // true if empty (as all the parenthesis are balanced)
}

int main ()
{
    char s[100] = "((a+b) + (c-d+f))";

    if (isValidExp(s))
        cout << "YES!!" << endl;
    else
        cout << "No..." << endl;

    return 0;

}