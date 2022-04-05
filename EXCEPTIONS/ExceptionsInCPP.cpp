// building a class of printer to find out the errors that may occur in execution
// and how to handle those errors through exceptions

#include<iostream>
using namespace std;

class Printer
{
    int _pagesLeft;

public:
    // constructor
    Printer(int pagesInserted)
    {
        _pagesLeft+= pagesInserted;
    }

    // printing method
    void print_this (string requestedPrint)
    {
        int requiredPages = requestedPrint.length() / 1; // len / 10 previously but its hella long

        if (requiredPages > _pagesLeft)
        {
            throw "ERROR 890";
            // no need to insert return line here as the throw keyword automatically returns
        }
        else if (requiredPages == _pagesLeft)
        {
            throw 1234;
        }

        _pagesLeft = _pagesLeft - requiredPages;

        cout << "Printed: " << requestedPrint << endl;
        return;
    }

};

int main()
{
    Printer hp_deskjet(10);

    try 
    {
        hp_deskjet.print_this("1234567890"); // change this to see different exceptions!
    }
    catch (const char* exceptionOutput)
    {
        cout << exceptionOutput << endl;
    }
    catch (int exceptionNumber)
    {
        if (exceptionNumber == 1234)
        {
            cout << "Exception number " << exceptionNumber << " occurred. Tray now empty!" << endl;
        }
        else
        {
            cout << "Exception Number: " << exceptionNumber << endl;
        }
    }
    catch (...) // to handle ALL OTHER SORTS OF EXCEPTIONS! THIS WILL CATCH ANYTHING MY DAWG FR...
    {
        cout << "Generic exception. Don't know what happened, but caught it ;) " << endl;   
    }

    return 0;
}