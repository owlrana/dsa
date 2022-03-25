#include<iostream>
#include<stack>
using namespace std;

int main ()
{

    stack<int> s;

    for (int i = 0; i <= 5; i ++)
    {
        s.push(i); // takes O(1) time
    }

    // loop
    while (!s.empty()) // internal functino to check if a stack is empty or not
    {
        cout << s.top() << ", "; // takes O(1) time
        s.pop(); // takes O(1) time
    }

    return 0;
}