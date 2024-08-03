/*
You are given an integer N and a binary 2D array of size N*N. The given binary matrix represents a maze and a rat starts from the top
left cell and has to reach to the bottom right cell of the maze. The rat can move in all the four directions: up, down, left and right.
In the given binary matrix, 0 signifies the cell is a dead end and 1 signifies the cell can be used to move from source to destination cell.
You have to print all the paths, following which rat can move from the top left cell to the bottom right cell of the given binary matrix.

Sample Input 1 :
3
1 0 1
1 0 1
1 1 1
Sample Output 1 :
1 0 0 1 0 0 1 1 1
Explanation :
Only 1 path is possible. The path is shown in the image below.

1 0 0
1 0 0   ==  1 0 0 1 0 0 1 1 1
1 1 1
*/

#include <bits/stdc++.h>
using namespace std;

void ratSolver(vector<vector<int>> &maz, vector<vector<int>> &sol, int i, int j)
{
    // first place the rat at (i,j)
    sol[i][j] = 1;
    int n = maz.size();

    if (i == n - 1 && j == n - 1) // base case: if rat reached the destination in maze, then print the 'sol' maze
    {
        for (int r = 0; r < n; r++)
        {
            for (int c = 0; c < n; c++)
            {
                cout << sol[r][c] << " ";
            }
        }

        cout << endl;
        sol[i][j] = 0; // put 0 back at (i,j) and backtrack
        return;
    }

    // if not base case ... then we will check all the possible paths after (i,j) using recursion
    if (j < n - 1) // checking whether j+1 is within maze or not
    {
        // then check if (i, j+1) is a possible next step for rat or not
        // for this at (i, j+1), 0 should not be present in 'maz' and check whether (i,j+1) already visited or not
        if (maz[i][j + 1] != 0 && sol[i][j + 1] != 1)
        {
            // if (i,j+1) possible then call recursion telling to place the rat next at (i,j+1)
            ratSolver(maz, sol, i, j + 1);
        }
    }

    // similarly do for other possible next steps for rat
    if (j > 0)
    {
        if (maz[i][j - 1] != 0 && sol[i][j - 1] != 1)
        {
            ratSolver(maz, sol, i, j - 1);
        }
    }

    if (i > 0)
    {
        if (maz[i - 1][j] != 0 && sol[i - 1][j] != 1)
        {
            ratSolver(maz, sol, i - 1, j);
        }
    }

    if (i < n - 1)
    {
        if (maz[i + 1][j] != 0 && sol[i + 1][j] != 1)
        {
            ratSolver(maz, sol, i + 1, j);
        }
    }

    // after checking all the possible paths after (i,j+1) we reach here
    sol[i][j] = 0; // put 0 back at (i,j) and backtrack
}

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> maz; // for saving the maze given by the question

    for (int i = 0; i < n; i++)
    {
        vector<int> v;
        int x;
        for (int j = 0; j < n; j++)
        {
            cin >> x;
            v.push_back(x);
        }

        maz.push_back(v);
    }

    vector<vector<int>> sol; // for saving the solution route for rat and then printing it
    for (int i = 0; i < n; i++)
    {
        vector<int> v;
        for (int j = 0; j < n; j++)
        {
            v.push_back(0);
        }

        sol.push_back(v);
    }

    ratSolver(maz, sol, 0, 0); // initially the rat is placed at (0,0)

    return 0;
}
