# include <iostream>
# include <vector>
using namespace std;

vector<int> myVector; // to store all indices as well

void allOcc (int array[], int size, int index, int key)
{
    if (size == 0)
        return;

    if (array[0] == key)
    {   
        myVector.push_back(index);
        cout << index << ", " << endl;
    }
    allOcc(array+1, size-1, index+1, key);
}

int main ()
{
    int array[] = {1,2,3,4,5,6,7,7,7,7,7,8,9,10};
    int size = sizeof(array) / sizeof(int);
    int index = 0;
    int key = 7;

    // prints all occurrencies
    allOcc(array, size, index, key);

    for (auto x: myVector)
        cout << x << "th index, ";
    cout << endl;

    return 0;
}