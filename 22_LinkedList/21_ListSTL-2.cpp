/*  
    Some more functions in the list
*/

#include<iostream>
#include<list>
using namespace std;

int main()
{
    list<int> l; 

    list<int> l1 {1,2,3,10, 8, 5};

    list<string> l2 {"apple", "guava", "mango", "banana"};
    l2.push_back("pineapple");

    l2.sort();

    l2.reverse();

    cout << l2.front() << endl;

    l2.pop_front();

    cout << l2.back() << endl;

    l2.pop_back();

    l2.push_front("owl");

    l2.push_back("rana");

    for (auto it=l2.begin(); it!=l2.end(); it++)
    {
        cout << *(it) << "-->";
    }
    cout << endl;
    cout << endl;
    cout << endl;

    // SOME MORE FUNCTIONS IN THE LIST
    l2.push_back("orange");
    l2.push_back("lemon");
    l2.push_back("guava");
    l2.push_back("guava");


    for(auto s: l2)
    {
        cout << s << "-->";
    }
    cout << endl;

    // remove a fruit by value (CAREFUL, REMOVES ALL THE INSTANCES OF THAT VALUE!!!!)
    string f;
    cin >> f;

    l2.remove(f);

    for (auto s: l2)
    {
        cout << s << "-->";
    }
    cout << endl;

    // erase one or more elements from the list
    // assign the iterator "it" to the beginning value
    auto it = l2.begin();
    // then iterate "it" N number of times (N = Nth element position, first element starting from 0)
    for (int i = 0; i < 3; i ++)
    {
        it ++;
    }

    l2.erase(it);

    for (auto s: l2)
    {
        cout << s << "-->";
    }
    cout << endl;


    // insert elements between the list
    it = l2.begin();
    it ++; // iterate the number of times at which you want to insert the element, first go to that place
    it ++;

    l2.insert(it, "Fruit Juice");

    for (auto s: l2)
    {
        cout << s << "-->";
    }
    cout << endl;

    cout << endl;
    return 0;
}