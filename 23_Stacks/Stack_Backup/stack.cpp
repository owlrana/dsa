// implementing a stack using vector

#include <iostream>
#include<vector>
using namespace std;

class Stack
{
    private:
        vector<int> myvector;

    public:

        void push(int data)
        {
            myvector.push_back(data);
            return;
        }

        bool empty()
        {
            return myvector.size() == 0;
        }

        void pop()
        {
            if (!empty())
                myvector.pop_back();
        }

        int top()
        {
            return myvector[myvector.size()-1];
        }

};

int main()
{
    Stack s;

    for (int i = 0; i <= 5; i ++)
    {
        s.push(i*i);
    }

    // try to print the contents of the stack
    while(!s.empty())
    {
        cout << s.top() << endl;
        s.pop();
    }

    return 0;
}