// Header file for Vector, can be incoporated by your programs
# include <iostream>
using namespace std;

class Vector
{
    // private
    int cs; //curr size
    int ms; //max size
    int* arr;

    public:
        
        // class constructor
        Vector()
        {
            cs = 0;
            ms = 1;
            arr = new int[ms];
        }

        // needs to dynamically change size to accomodate new elements
        void push_back(int d)
        {
            // if the array is full
            if (cs == ms)
            {
                int* oldArr = arr;
                arr = new int[ms*2];
                ms = ms*2;
            
                for (int i = 0; i < cs; i ++)
                    arr[i] = oldArr[i];
            
                delete [] oldArr;
            }

            arr[cs] = d;
            cs += 1;
        }

        // deletes element but does not change the maximum size
        void pop_back()
        {
            cs -= 1;
        }

        int front() const
        {
            return arr[0];
        }

        int back() const
        {
            return arr[cs-1];
        }

        bool empty() const
        {
            return cs == 0;
        }

        int capacity() const
        {
            return ms;
        }

        int size () const
        {
            return cs;
        }

        int operator[] (const int i)
        {
            return arr[i];
        }

        void print() const
        {   
            cout << "(";
            for (int i = 0; i < cs; i ++)
                {
                    cout << arr[i] << ", ";
                }
                cout << "\b\b)" << endl;
        }
};

/*
    --- HEADER FILES SHOULD NOT INCLUDE INT MAIN() FUNCTION ---

int main()
{
    cout << endl << "AM I RUNNING THE HEADER FILE'S MAIN FUNCTION??!!" << endl;
}

*/