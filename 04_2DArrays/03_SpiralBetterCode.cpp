#include<everything>
using namespace std;

void spiralPrint (vector< vector<int> > matrix, int row, int col)
{

    int startRow = 0;
    int endRow = row-1;
    int startCol = 0;
    int endCol = col-1;
    int i, j; // helpers

    while ((startRow <= endRow) and (startCol <= endCol))
    {
        // TOP -> left to right
        i = startRow; // FIXED
        j = startCol; // iterate this
        for (; j <= endCol; j ++)
        {
            cout << matrix[i][j] << ", ";
        }
        startRow += 1; // this row has been completed


        // RIGHT -> top to bottom
        i = startRow; // iterate this
        j = endCol; // FIXED
        for (; i <= endRow; i ++)
        {
            cout << matrix[i][j] << ", ";
        }
        endCol -= 1; // this column has been completed


        // in case of ODD numbered matrix, the code under this should NOT run for equality
        // otherwise it will run twice!!!

        
        if ((row%2 == 0) or (startRow < endRow))  // CHECKING ROW to PRINT column
        {
            // BOTTOM -> right to left
            i = endRow; // FIXED
            j = endCol; // iterate this
            for (; j >= startCol; j --)
            {
                cout << matrix[i][j] << ", ";
            }
            endRow -= 1; // this row has been completed
        }

        if ((col%2 == 0) or (startCol < endCol))
        {
            // LEFT -> bottom to top
            i = endRow; // iterate this
            j = startCol; // FIXED
            for (; i >= startRow; i --)
            {
                cout << matrix[i][j] << ", ";
            }
            startCol += 1;
        }

    }

}

int main()
{
    int row, col;
    cout << "Enter the number of rows: ";
    cin >> row;
    cout << "Enter the number of cols: ";
    cin >> col;    

    vector< vector<int> > matrix;

    for (int i = 0; i < row; i ++)
    {
        vector<int> tempColumns;
        for (int j = 0; j < col; j ++)
        {
            int number;
            cin >> number;
            tempColumns.push_back(number);
        }
        matrix.push_back(tempColumns);
    }

    for (int i = 0; i < row; i ++)
    {
        for (int j = 0; j < col; j ++)
        {
            cout << matrix[i][j] << "  ";
        }
        cout << endl;
    }

    cout << endl;
    cout << endl;

    cout << "Calculating spiral print..." <<  endl;

    spiralPrint(matrix, row, col);

    return 0;
}