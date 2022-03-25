/*  
    "List" is a doubly linked list in c++ STL
*/

#include<iostream>
#include<list>
using namespace std;

int main()
{
    list<int> l; // creating a list class object

    // init
    list<int> l1 {1,2,3,10, 8, 5};

    // different DataType than int can also be used
    list<string> l2 {"apple", "guava", "mango", "banana"};
    l2.push_back("pineapple");

    // sort function available inside the list class
    l2.sort();

    // reverse the order
    l2.reverse();

    // ONLY to SEE the FRONT element
    cout << l2.front() << endl;

    // remove the front element
    l2.pop_front();

    // ONLY to SEE the LAST element
    cout << l2.back() << endl;

    // remove the last element
    l2.pop_back();

    // add something to the front of the list
    l2.push_front("owl");

    // add something to the end of the list
    l2.push_back("rana");

    // you can also iterate over the list using iterators
    for (auto it=l2.begin(); it!=l2.end(); it++)
    {
        cout << *(it) << "-->";
    }
    cout << endl;

    // iterate over the list and print the data
    for (string s: l2)
    {
        cout << s << "-->";
    }

    cout << endl;
    return 0;
}