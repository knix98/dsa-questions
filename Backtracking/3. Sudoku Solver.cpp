/*
Coding Ninjas has provided you a 9*9 sudoku board. The board contains non zero and zero values. Non zero values lie in the range: [1, 9].
Cells with zero value indicate that the particular cell is empty and can be replaced by non zero values.
You need to find out whether the sudoku board can be solved. If the sudoku board can be solved, then print true, otherwise print false.

Sample Input 1:
9 0 0 0 2 0 7 5 0
6 0 0 0 5 0 0 4 0
0 2 0 4 0 0 0 1 0
2 0 8 0 0 0 0 0 0
0 7 0 5 0 9 0 6 0
0 0 0 0 0 0 4 0 1
0 1 0 0 0 5 0 8 0
0 9 0 0 7 0 0 0 4
0 8 2 0 4 0 0 0 6

Sample Output 1:
true
*/

// SOLUTION APPROACH:
// at any blank position check for all the numbers [1,9] whether a particular number fits here
// for a number check its validity at this blank by 3 parameters -> validity in 1.Row, 2.Column, 3.Box
// if a number fits then call recursion for further sudoku...if recursion returns false, then change the number and repeat the process
// otherwise return true and backtrack
// and if no number fits in this blank then return false and backtrack

#include <bits/stdc++.h>
using namespace std;

int sudoku[9][9];

void print()
{
    cout << endl;
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cout << sudoku[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

bool check(int num, int x, int y)
{
    // checking inside the box
    int r, c;
    if (x > 5)
    {
        r = 6;
    }
    else if (x > 2)
    {
        r = 3;
    }
    else
    {
        r = 0;
    }
    if (y > 5)
    {
        c = 6;
    }
    else if (y > 2)
    {
        c = 3;
    }
    else
    {
        c = 0;
    }

    for (int i = 1; i <= 3; i++)
    {
        for (int j = 1; j <= 3; j++)
        {
            if (sudoku[r][c] == num)
            {
                return false;
            }
            c++;
        }
        r++;
        c = c - 3;
    }

    // checking in row & column
    for (int i = 0; i <= 8; i++)
    {
        if (sudoku[x][i] == num || sudoku[i][y] == num)
        {
            return false;
        }
    }

    return true;
}

bool solver(int x, int y)
{
    if (x > 8)
    {
        print();
        return true;
    }
    else if (x == 8 && y == 8 && sudoku[x][y] != 0)
    {
        print();
        return true;
    }
    while (sudoku[x][y] != 0)
    {
        if (y < 8)
        {
            y++;
        }
        else if (x < 8)
        {
            x++;
            y = 0;
        }
        else
        { // x==8 && y==8
            print();
            return true;
        }
    }

    for (int i = 1; i <= 9; i++)
    {
        if (check(i, x, y))
        {
            sudoku[x][y] = i;
            if (solver(x, y))
            {
                return true;
            }
        }
    }

    sudoku[x][y] = 0;
    return false;
}

int main()
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cin >> sudoku[i][j];
        }
    }
    if (solver(0, 0))
    {
        cout << "true";
    }
    else
    {
        cout << "false";
    }
    return 0;
}