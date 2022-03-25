/*
    In earlier program we created a stack of integers
    But we may want to use other data types for stack data structure, and will have to write the code again...
    C++ helps us by providing the structure for a TEMPLATE which is a general container

*/

#include<iostream>
#include<vector>
using namespace std;

// implementing a stack using vectors
template<typename T>
class stack
{
    private:
        vector<T> v;

    public:
        void push (T data)
        {
            v.push_back(data);
            return;
        }

        bool isEmpty()
        {
            if (v.size() == 0)
                return true;
            return false;
        }

        T pop ()
        {
            if (isEmpty())
                return T(INT_MIN);
            int element = v[v.size()-1];
            v.pop_back();
            return element;
        }

        T top ()
        {
            return v[v.size()-1];
        }

        void print ()
        {
            for (int i = 0; i < v.size(); i ++)
            {
                cout << v[i] << ", ";
            }
            cout << "\b\b  " << endl;
        }
};

int main()
{
    stack<char> one; // object of type stack

    one.push('a');
    one.push('b');
    one.push('c');

    one.print();
    one.pop();
    one.print();

    return 0;
}