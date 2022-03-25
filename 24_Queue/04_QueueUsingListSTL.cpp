#include<iostream>
#include<list>
using namespace std;

class Queue
{
    int cs;
    list<int> l;

    public:
        Queue()
        {
            cs = 0;
        }

        bool isEmpty()
        {
            return cs == 0;
        }

        void push (int data)
        {
            l.push_back(data);
            cs += 1;
        }

        void pop()
        {
            if(!isEmpty())
            {
                cs--;
                l.pop_front();
            }
        }

        int front ()
        {
            return l.front();
        }

        // as we are using a linked list, it won't be full.
        // so we do not need a function that checks if it is full or not
};

int main()
{
    Queue q;

    for (int i = 0; i <= 10; i ++)
    {
        q.push(i);
    }

    while(!q.isEmpty())
    {
        cout << q.front() << ", ";
        q.pop();
    }

    // program prints 0 to 10, which is the correct FIFO order.
    
    return 0;
}