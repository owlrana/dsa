// program for Counting Sort

#include<iostream>
#include<climits>
using namespace std;

void CountingSort(int* array, int size)
{
    // finding out the largest number in the array (assuming all elements are > 0)
    int largest = -1;
    for (int i = 0; i < size; i ++)
    {
        largest = max(largest, array[i]);
    }

    // create a new frequency array
    int *freq = new int[largest + 1] (); // create dynamic array and initialise its elements as zero

    for (int i = 0; i < size; i ++)
    {
        freq[array[i]]++;
    }

    // put the elements back into array a by reading the freqeuncy array
    int j = 0;
    for (int i = 0; i <= largest; i ++)
    {
        while (freq[i] > 0) // for elements with frequency more than 1
        {
            array[j] = i;
            freq[i] --;
            j ++;
        }
    }
}

// print the contents of an array
void print(int array[], int size)
{
    for (int i = 0; i < size; i ++)
    {
        cout << array[i] << ", ";
    }
    cout << endl;
}

int main()
{
    int array[50];
    int n;
    cin >> n;

    for (int i = 0; i < n; i ++)
    {
        cin >> array[i];
    }

    CountingSort(array, n);
    print(array, n);

    return 0;
}