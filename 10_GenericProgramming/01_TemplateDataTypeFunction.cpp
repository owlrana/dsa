// Creating a function that accepts and searches any type of container for a given key

# include <iostream>

using namespace std;

template<class T> // can also say "template <typename T>"
int search(T arr[], int size, T key)
{
    int index = -1;
    for (int i = 0; i < size; i ++)
    {
        if (arr[i] == key)
            return i;
    }
    return index;
}


int main ()
{
    int arr[] = {1,7,3,4,9,0,3,2,5,7,9,1};
    for (int x:arr)
        cout << x << ", ";
    cout << "\b\b " << endl;
    
    int size = sizeof(arr)/sizeof(int);
    cout << "SIZE: " << size << endl;

    int key;
    cout << "Enter the key you want to search for: "; 
    cin >> key;

    if (search(arr,size,key) == -1)
        cout << "Key not found!" << endl;
    else
        cout << "Key found at index: " << search(arr, size, key);

    // THIS WILL ALSO WORK IN THE SAME WAY WITH CHAR SO IT IS SUPER MAST DAWG!

    return 0;
}
