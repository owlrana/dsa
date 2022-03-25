// mainly codes in this directory, theory can be found in my notebook!

// Example of Polymorphism

#include<iostream>
using namespace std;

class Employee
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
        Employee ()
        {

        }

        Employee (string aName, string aCompany, int aAge, int aSalary)
        {
            name = aName;
            company = aCompany;
            age = aAge;
            salary = aSalary;
        }

        virtual void askForRaise () // derived classes' own specific definitions will be accessed
        // if used through a pointer of main base class
        {
            cout << "YOU JUST GOT A RAISE!" << endl;
        }
        

};

class Developer :  public Employee
{
    public:
        Developer ()
        {

        }

        string EmployeeName = name; // works, as name is in protected modifier, so child inherits this
        // int EmployeeAge = age; // cannot do this as age is in private modifier, so cannot do this

        // cout << age; // cant do this as the Employee class had age in protected access modifier
        // shift the name into protected to understand the difference.

        // this class' object cannot acces askForRaise or any other public methods...
        // to access public methods for inheritance, you need to *Inherit Publicly*
        // like this:
        // class Developer : public Employee {....}
        // doing this makes sure that all things are publicly inherited (not private or protected ones)

        void askForRaise ()
        {
            cout << "Developer is asking for a raise" << endl;
        }

};

class Teacher : public Employee
{
    public:
        Teacher ()
        {

        }

        void askForRaise () 
        {
            cout << "the teacher is asking for raise..." << endl;
        }
};

int main()
{
    Developer rana;
    Teacher mongi;
    
    Employee* emp_ptr = &rana;

    emp_ptr->askForRaise();
    
    emp_ptr = &mongi;
    emp_ptr->askForRaise();

    // so this is how a single pointer of MAIN/BASE/SUPER class employee can be used to access
    // the member functions of the derived class objects

    return 0;
}