/*
You are given N, and for a given N x N chessboard, find a way to place N queens such that
no queen can attack any other queen on the chess board.
A queen can be killed when it lies in the same row, or same column, or the same diagonal of any of the other queens.
You have to print all such configurations.
Note: Don't print anything if there isn't any valid configuration.

Sample Input 1:
4
Sample Output 1 :
0 1 0 0 0 0 0 1 1 0 0 0 0 0 1 0
0 0 1 0 1 0 0 0 0 0 0 1 0 1 0 0
Explanation:
The first and second configuration are shown in the image below.
Here, 1 denotes the placement of a queen and 0 denotes an empty cell.
Please note that in both the configurations, no pair of queens can kill each other.

0 1 0 0     0 0 1 0
0 0 0 1     1 0 0 0
1 0 0 0     0 0 0 1
0 0 1 0     0 1 0 0
*/

#include <bits/stdc++.h>
using namespace std;

// helper function: will check whether queen can be placed at the given coordinate without getting killed
// and we only need to check the positions above the current position, because no queen placed below the current position
//  n=size of board
bool qPossible(int row, int col, int n, int **board)
{
    // checking the column above current posn
    for (int i = row - 1; i >= 0; i--)
    {
        if (board[i][col] == 1)
        {
            return false;
        }
    }

    // checking north-east direction
    for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
    {
        if (board[i][j] == 1)
        {
            return false;
        }
    }

    // checking north-west direction
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j] == 1)
        {
            return false;
        }
    }

    return true;
}

// this main solver will take in the board, size of board and a row number to check the correct position of queen in this row
//  n=size of board, row=row number
void nqueen(int n, int row, int **board)
{
    if (row == n)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << board[i][j] << " ";
            }
        }

        cout << endl;
        return;
    }

    for (int i = 0; i < n; i++)
    {
        if (qPossible(row, i, n, board))
        {
            board[row][i] = 1;
            nqueen(n, row + 1, board);
            board[row][i] = 0;
        }
    }
}

int main()
{
    int n;
    cin >> n;
    int **board = new int *[n];
    for (int i = 0; i < n; i++)
    {
        board[i] = new int[n]{0};
    }

    nqueen(n, 0, board);

    for (int i = 0; i < n; i++)
    {
        delete[] board[i];
    }

    delete[] board;
    // write your code here
    return 0;
}