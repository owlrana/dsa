// colouring algorithm for Flood Fill

/*
    Flood Fill is a simple variant of BFS/DFS that can be used to label(colour) the 
    various connected components present in a graph
    It is generally performed on implicit graphs ( nothing but 2D Matrices)

    Starting from a particular cell we call 'DFS' on the neighbouring cells to colour
    them. Neighbours can be '4'(up, down, left, right) or '8' if we include diagonals also.

    INPUT:
    
15 30
..............................
.............#####............
.............#...#............
......########...#######......
.....###.....##..#.....###....
...##..........##.......###...
..##......................##..
..##......................##..
..###....................##...
...###..................##....
.....###...............##.....
.......###............##......
.........##############.......
..............................
..............................

*/

//

#include<iostream>
#include<list>
#include<queue>
#include<map>
#include<stdlib.h>
#include<chrono>
#include<thread>
using namespace std;
int R, C;

// helper function to print our matrix
void printMat(string input[][50])
{
    // VISUAL BLOCK ONLY------------------------------------
    for (int i = 0; i < 1000000; i++){
        for (int i = 0; i < 30; i++){
            //for (int i = 0; i < 1000000; i ++) {}
        }
    }
    system("clear"); //visual help ONLY
    //------------------------------------------------------

    for (int i = 0; i < R; i ++)
    {
        for (int j = 0; j < C; j ++)
        {
            cout << input[i][j];
        }
        cout << endl;
    }
}

// W, N, E, S
// these will define our locations for 4 directions of increments
// just making our work easier
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

// ch is the character to be replaced
// colour is the character to be added
void floodFill(string mat[][50], int i, int j, string ch, string color)
{
    // Base Case - Matrix Bounds
    if (i < 0 || j < 0 || i >= R || j>= C)
    {
        return;
    }

    // Boundary Condition - Figure's Boundary
    if (mat[i][j] != ch)
    {
        return;
    }

    // Recursive Call
    // using 4 neighbour approach
    mat[i][j] = color; // painted the current cell
    printMat(mat);

    for (int k = 0; k < 4; k ++)
    {
        floodFill(mat, i + dx[k], j + dy[k], ch, color);
    }
}

int main()
{
    string red = "\033[1;31mX\033[0m";
    string black = "\033[1;30m \033[0m";
    string green = "\033[1;32mX\033[0m";

    cin >> R >> C;
    string input[15][50];

    for (int i = 0; i < R; i ++)
    {
        for (int j = 0; j < C; j ++)
        {
            char character;
            cin >> character;
            input[i][j] = character;
        }
    }

    printMat(input);

    floodFill(input, 0, 0, ".", black);
    // calling colour drop at cell 8, 13
    floodFill(input, 8, 13, ".", red);
    // called floodfill on input array; at 8,13 position; replacing '.' by 'r'
    floodFill(input, 2, 14, ".", green);

    //printMat(input);

}