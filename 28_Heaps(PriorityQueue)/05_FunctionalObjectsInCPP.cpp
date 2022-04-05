// Functional objects in C++
// FUNCTORS!!!

#include<iostream>
using namespace std;

class functor
{
    public:
        void operator() ()
        {
            cout << "This is a functional Object, called Functor!!!" << endl;
        }

        void operator() (string name)
        {
            cout << name << " just used a functor, damn!" << endl;
        }
};

int main()
{
    functor f;

    f();
    f("Rahul Rana");

    return 0;
}