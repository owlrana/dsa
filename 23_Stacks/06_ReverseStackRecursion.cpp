/*
    Recursively reverse a stack.
    This implements the use of "call stack" in recursion.

    When we create a stack data structure, we are creating an "explicit stack".
    The stack that recursion uses is an "implicit stack".
*/

#include<iostream>
#include<stack>
using namespace std;

// helper function to help us insert at the bottom of the stack
void insertAtBottom(stack<int> &s, int x)
{
    // x element needs to be inserted in the bottom

    // base case
    // if the stack is empty
    if (s.empty())
    {
        s.push(x);
        return;
    }   

    // else
    // recursion
    int data = s.top();
    s.pop();
    insertAtBottom(s, x);
    s.push(data);
}

// recursively reversing the stack
void reverseStack(stack<int> &s)
{
    // base case
    if (s.empty()) // if the stack is empty just return
        return; 

    // otherwise
    // pop out the top element and insert it at the bottom of reversed smaller stack
    int x = s.top();
    s.pop();

    // recursively reverse the smaller stack
    reverseStack(s);

    // insert at the bottom of the reversed stack
    insertAtBottom(s, x);
}


int main ()
{

    stack<int> s;
    s.push(1);
    s.push(3);
    s.push(4);
    s.push(4);

    reverseStack(s);
    while(!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }

    return 0;
}