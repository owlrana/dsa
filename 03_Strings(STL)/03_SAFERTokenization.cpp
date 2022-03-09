// always try to use this version of tokenizer (ie. inside a function) for CHAR ARRAY STRINGS
// using tokenizer in main will result in segmentation faults due to read only memory nature of char

#include<iostream>
using namespace std;

void tokenize(char* line)
{
    char* cmd = strtok(line," ");

    while (cmd != NULL)
    {
        printf ("%s\n",cmd);
        cmd = strtok(NULL, " ");
    } 
}

int main(void)
{
    char buff[80];
    strcpy (buff, "this is a test");
    tokenize(buff);

    return 0;
}