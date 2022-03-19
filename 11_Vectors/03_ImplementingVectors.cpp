// Trying to see how the vector class words under the hood

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
            for (int i = 0; i < cs; i ++)
                {
                    cout << arr[i] << ", ";
                }
                cout << "\b\b " << endl;
        }
};

int main ()
{
    Vector v;

    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    v.push_back(6);
    v.push_back(7);
    v.push_back(8);
    v.push_back(9);
    v.push_back(10);

    v.print();

    return 0;
}