#include<iostream>
#include<vector>
using namespace std;

// implementing a stack using vectors
class stack
{
    private:
        vector<int> v;

    public:
        void push (int num)
        {
            v.push_back(num);
            return;
        }

        bool isEmpty()
        {
            if (v.size() == 0)
                return true;
            return false;
        }

        int pop ()
        {
            if (isEmpty())
                return INT_MIN;
            int element = v[v.size()-1];
            v.pop_back();
            return element;
        }

        int top ()
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
    stack one; // object of type stack

    one.push(1);
    one.push(2);
    one.push(3);

    one.print();
    one.pop();
    one.print();

    return 0;
}