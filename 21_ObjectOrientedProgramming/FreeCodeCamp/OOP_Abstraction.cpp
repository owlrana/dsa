// mainly codes in this directory, theory can be found in my notebook!

// Example of ABSTRACTION

#include<iostream>
using namespace std;

class AbstractEmployee
{
public:
    void askForRaise ()
    {
        cout << "cant ask for a raise..." << endl;
    }
};

class Employee: public AbstractEmployee
{
private:
    string name = "Rahul Rana";
    string company = "Cognizant";
    int age = 21;
    int salary = 675000;
public:
    void setAge (int aAge)
    {
        if (aAge >= 18)
        {
            age = aAge;
        }
        else
        {
            cout << "INVALID AGE PROVIDED!" << endl;
        }

        return;
    }

    int getAge ()
    {
        return age;
    }
/*
    Employee (string aName)
    {
        name = aName;
    }
    
    Employee (string aName, string aCompany)
    {
        name = aName;
        company = aCompany;
    }

    Employee (string aName, string aCompany, int aAge)
    {
        name = aName;
        company = aCompany;
        age = aAge;
    }
*/  
    Employee (string aName, string aCompany, int aAge, int aSalary)
    {
        name = aName;
        company = aCompany;
        age = aAge;
        salary = aSalary;
    }

    void askForRaise ()
    {
        cout << "YOU JUST GOT A RAISE!" << endl;
    }
    

};

int main()
{
    Employee rahul("Rahul Rana", "Cognizant", 22, 675000);

    cout << rahul.getAge();
    rahul.setAge(int(20));
    cout << rahul.getAge();
    rahul.askForRaise();

    return 0;
}