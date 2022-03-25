/*
    Reverse a stack using another stack (ORIGINAL STACK SHOULD HAVE REVERSED ELEMENTS).
    Problem would have been easier if we could use an array. But USE ANOTHER STACK!!

    1.  USING 2 MORE STACKS
        Send all elements of original stack into temp1 stack (order is reversed now)
        Send elements of temp1 stack into temp2 stack (order is original now)
        Send elements of temp2 into original stack (order is reversed now)

    2.  USING ONLY ONE MORE STACK
        Store the topmost element in a variable X
            Send remaining elements (n-1 elements) of OriginalStack into TempStack
            Put X in OriginalStack
            Put all elements from TempStack into OriginalStack
        Now do the same, but this time transfer 1 element less from OriginalStack (as it is in place)
        Repeat.

        (in the ith step, we remove N - 1 - i elements)

*/

#include<iostream>
#include<stack>
using namespace std;

// as we had to do transfers quite a few times, we created this helper function
void transfer(stack<int> &s1, stack<int> &s2, int n)
{
    // need to transfer n number of elements
    for (int i = 0; i < n; i ++)
    {
        s2.push(s1.top());
        s1.pop();
    }
}

void reverseStack (stack<int> &s1)
{
    // helper stack
    stack<int> s2;

    int n = s1.size();

    for(int i = 0; i < n; i ++)
    {
        // pick the element at top and insert it at the bottom
        int x = s1.top();
        s1.pop();

        // transfer the remaining n-1-i elements from stack s1 into s2
        transfer(s1, s2, n-i-1);

        //insert the element x in s1
        s1.push(x);

        // transfer n-1-i elements from s2 into s1
        transfer(s2, s1, n-i-1);
    }
}

int main ()
{

    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);

    reverseStack(s);

    while(!s.empty())
    {
        cout << s.top() << ", ";
        s.pop();
    }
    cout << "\b\b  " << endl;

    return 0;

}
