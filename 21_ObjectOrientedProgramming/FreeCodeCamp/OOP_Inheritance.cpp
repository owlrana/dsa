// mainly codes in this directory, theory can be found in my notebook!

// Example of Inheritance

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
protected:
    string name = "Rahul Rana";

private:
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

class Developer :  Employee
{
    string EmployeeName = name; // works, as name is in protected modifier, so child inherits this
    // int EmployeeAge = age; // cannot do this as age is in private modifier, so cannot do this

    // cout << age; // cant do this as the Employee class had age in protected access modifier
    // shift the name into protected to understand the difference.

    // this class' object cannot acces askForRaise or any other public methods...
    // to access public methods for inheritance, you need to *Inherit Publicly*
    // like this:
    // class Developer : public Employee {....}
    // doing this makes sure that all things are publicly inherited (not private or protected ones)
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