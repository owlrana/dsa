// REplace "Pi" with "3.14"
// Eg. lkjdlkfjPikjdfjknPi lkfkjdklfjPi = lkjdlkfj3.14kjdfjkn3.14 lkfkjdklfj3.14
// need to do it IN PLACE without any extra string/ assume there is enough space for shifting

# include <iostream>
using namespace std;

void replacePi(char array[], int i)
{
    // base case first
    if (array[i] == '\0' or array[i + 1] == '\0') // if you just read the last character of array (NULL)
        return;

    // look for pi in current location
    if ((array[i] == 'P' and array[i+1] == 'i') or (array[i] == 'p' and array[i+1] == 'i'))
    {
        // shifting followed by replacement of pi with 3.14
        int j = i + 2;

        // take j to the end of the array so we can start shifting from right to left
        while (array[j] != '\0')
            j ++;

        // shifting now
        while ( j >= i + 2)
        {
            array[j+2] = array[j];
            j --; 
        }

        // replacement + recursive call of remaining part
        array[i] = '3';
        array[i+1] = '.';
        array[i+2] = '1';
        array[i+3] = '4';
    
        // recursive call on the remaining part
        replacePi(array, i + 4); // i +4 because the remaining string would start from that
    
    }
    else
    {
        // otherwise, just go to the next position
        replacePi(array, i + 1);
    }
}

int main ()
{
    char array[1000];
    cin >> array;
    replacePi(array, 0);
    cout << array;

    return 0;
}