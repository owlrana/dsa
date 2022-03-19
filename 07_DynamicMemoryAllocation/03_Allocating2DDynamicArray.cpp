# include <iostream>
using namespace std;

int main ()
{
    // new int [10][10]; // you cannot initialise 2D Array Dynamically like this, it isnt supported
    // You will have to create multiple arrays and then combine them 
    
    // IN STATIC DECLARATION, 2D ARRAY IS STORED IN ROW-MAJOR FORM:
    // [Row1][][][Row2][][][Row3][][][Row4][][]... next addresses consecutively 

    // But in Heap, each array will be initialised individually so we need to
    // create pointer variables for each row,
    
    // If there are "r" Rows, then there will be r no. of pointers for each new array in heap for 2D
    // So there will be one pointer for each row, and these pointers will be an array in itself
    // which will be pointed by a double pointer

    /*
    
    ---WORKING OF 2D DYNAMIC ARRAY USING POINTERS (requires N pointers for N-Rowed Array)---

    int** ->[int*] [][][][][][][][]...
            [int*] [][][][][][][][]...
            [int*] [][][][][][][][]...
            [int*] [][][][][][][][]...
            .
            .
            .

    */ 

    int** arr;
    int row, col;
    cin >> row >> col;

    // Create and array of row heads
    arr = new int* [row];

    for (int i = 0; i < row; i ++)
    {
        arr[i] = new int [col] {0}; // all columns initialised to zero
    }

    // take input and print elements
    for (int i = 0; i < row; i ++)
        for (int j = 0; j < col; j ++)
            cout << arr[i][j] << " ";
    




    return 0;
}