#include<iostream>
#include<string>
using namespace std;

int main()
{
    char myString[100] = "ccccccccccccccoooooodinnnnnngggggg";

    int j = 0; // previous
    int i = 1; // current 

    for (; i < strlen(myString); i ++)
    {
        if (myString[i] != myString[j])
        {
            myString[j+1] = myString[i];
            j += 1;
        }
    }
    myString[j+1] = '\0';

    cout << myString;

    return 0;
}