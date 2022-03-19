// Checking file to see if our custom header file is working or not

# include <iostream>
# include "vector.h" // always use "" when using your own header files of .h extension

using namespace std;

int main ()
{
    Vector shrutiMarks;

    shrutiMarks.push_back(99);
    shrutiMarks.push_back(100);
    shrutiMarks.push_back(98);
    shrutiMarks.push_back(95);
    shrutiMarks.push_back(96);

    shrutiMarks.print();

    return 0;
}