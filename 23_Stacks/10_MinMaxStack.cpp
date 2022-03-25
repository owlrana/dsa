/*  
    Similar to https://leetcode.com/problems/min-stack/

    To keep track of minimum and maximum elements in a stack while pushing & popping,
    We cannot just have two variables.
    These variables will have to change once pop or push operations are done.
    so here is our solution:
        To keep this track, we have a total of 3 stacks in our stack class.
        ->  1. STACK, 2. MINIMUM STACK, 3. MAXIMUM STACK

    These need to be updated with each pop, push operation done in original stack.
    
    1.  For pushing:
            push object in original stack
            check if object is smaller than object on top of min stack, if it is, then push it otherwise push the top element once more
            check if object is larger than object on top of max stack, if it is, then push it otherwise push the top element once more

        For Popping
            Pop element out of all the three stacks. That's it.

    This will help us take care of our Min and Max tracks inside the stack.
*/

#include<iostream>
#include<stack>
#include<vector>
using namespace std;

class MinMaxStack
{
    vector<int> stack;
    vector<int> min_stack;
    vector<int> max_stack;

    public:
        void push (int data)
        {
            int current_min = data;
            int current_max = data;

            if (min_stack.size())
            {
                current_min = min(min_stack[min_stack.size() - 1], data);
                current_max = max(max_stack[max_stack.size() - 1], data);
            }

            min_stack.push_back(current_min);
            max_stack.push_back(current_max);

            stack.push_back(data);
        }

        int get_min()
        {
            return min_stack[min_stack.size() - 1];
        }

        int get_max()
        {
            return max_stack[max_stack.size() - 1];
        }

        int top()
        {
            return stack[stack.size() - 1];
        }

        bool isEmpty()
        {
            return stack.size() == 0;
        }

        void pop()
        {
            min_stack.pop_back();
            max_stack.pop_back();
            stack.pop_back();

        }

};

int main()
{
    MinMaxStack s;

    s.push(1);
    s.push(5);
    s.push(3);
    s.push(8);

    cout << s.get_max() << endl;
    s.pop();
    cout << s.get_min() << endl;
    cout << s.get_max() << endl;

    s.pop();
    s.pop();
    cout << s.top() << endl;
    cout << s.get_max() << endl;

    return 0;
}