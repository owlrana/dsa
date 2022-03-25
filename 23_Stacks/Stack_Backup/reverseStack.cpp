// reversing a stack (iterative version)
#include <iostream>
#include<stack>

using namespace std;

void transfer(stack<int> &s2, stack<int> &s1, int elements)
{
    while (elements--) // the number of elements we want to transfer from one to another
    {
        s1.push(s2.top()); // store the top most element of s2 into s1
        s2.pop(); // remove the top element as it is no longer useful
    }
}

void reverseStack (stack<int> &s1)
{
    // helper stack s2
    stack<int> s2;

    int n = s1.size();

    for (int i = 0; i < n; i ++)
    {
        // pick up the top element and store it safely in x
        int x = s1.top();
        s1.pop();

        // now transfer elements that are not in correct place into s2 (n-i-1 elements)
        transfer(s1, s2, n-i-1);

        // put x back into s1
        s1.push(x);

        // transfer all elements of s2 into s1 (same, n-i-1 elements)
        transfer(s2, s1, n-i-1);
    }
}


int main()
{
    stack<int> s1;
    s1.push(5);
    s1.push(4);
    s1.push(3);
    s1.push(2);
    s1.push(1);
    
    reverseStack(s1);

    while (!s1.empty())
    {
        cout << s1.top();
        s1.pop();
    }

    return 0;

}