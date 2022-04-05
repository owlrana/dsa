// Implementing a Queue for our CUSTOM CLASSES

#include<iostream>
#include<queue>
using namespace std;

class Person 
{
    public:
        int age;
        string name;

        Person()
        {

        }

        Person(string aName, int aAge)
        {
            name = aName;
            age = aAge;
        }
};

// class comparator to compare our custom classes for Queue STL
// Comparator class MUST HAVE functor in it to qualify as a comparator class
class PersonCompare
{
    public:
        bool operator() (Person A, Person B)
        {
            return A.age < B.age; // will give descending order
        }
};

int main()
{
    int n;
    cin >> n;

    // for custom classes, priority Queue requires a custom comparator class
    // just like our sorting function can accept a custom function...
    priority_queue<Person, vector<Person>, PersonCompare > pq;

    for (int i = 0; i < n; i++)
    {
        string name;
        int age;
        cin >> name >> age;
        Person p(name, age);

        pq.push(p);
    }

    int top5 = 5;

    // this shall output the people with most age -- to -- smaller age 
    // descending order
    for (int i = 0; i < top5; i ++)
    {
        Person p = pq.top();
        cout << p.name << " " << p.age << endl;
        pq.pop();
    }

    return 0;
}