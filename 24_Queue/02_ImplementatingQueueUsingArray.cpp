/*
    Implementing a fixed size Queue using an Array

    Approach 1:
        keep FRONTpointer on index 0 always, rear keeps changing accordingly
        to do this, if you Pop an item(queue pops from the front) then you need to shift all other elements to left
        this is inefficient.

    Approach 2:
        you put FRONTpointer on index 0 (for now) and then REARpointer at N-1 (for now)
        You try to implement a circular fashion using mod, (if index >= N, index = index % length)
        When an element is popped, front just goes one step ahead.
        If more elements are needed to be inserted, rear can go ahead of length (then insert into 0th or other position if front is not there yet)
        This is more efficient and would not require any shifting.
*/
#include<iostream>
using namespace std;

class Queue
{
    int* arr; // (Need to delete this later on)
    int f, r, cs, ms; // front, rear, current size, max size (Static Data Members)

    public:
        Queue(int ds = 5) // takes value of d from user, if not provided takes 5 default
        {
            arr = new int[ds];
            cs = 0;
            ms = ds;
            f = 0;
            r = ms -1;
        }

        bool full ()
        {
            return cs == ms;
        }

        bool empty()
        {
            return cs == 0;
        }

        void push (int data)
        {
            if (!full())
            {
                r = (r+1) % ms;
                arr[r] = data;
                cs++;
            }
        }
        void pop ()
        {
            if (!empty())
            {
                f = (f+1) % ms;
                cs --;
            }
        }

        int front()
        {
            return arr[f];
        }

        // destructor
        ~Queue ()
        {
            if (arr != NULL)
            {
                delete [] arr; // delete the heap memory
                arr = NULL;
            }
        }
};

int main()
{
    Queue q;

    for (int i = 1; i <= 6; i ++) // 6 should not be inserted in this as size is 5 here
    {
        q.push(i);
    }

    q.pop();
    q.pop();

    q.push(7);

    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;

    return 0;
}