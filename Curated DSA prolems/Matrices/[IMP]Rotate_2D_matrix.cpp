/*
Rotate the given 2D matrix by 90 degrees in the given direction (clockwise or anticlockwise).
*/

#include <bits/stdc++.h>
using namespace std;

void transpose(vector<vector<int>> &mat)
{
    int n = mat.size();
    cout << n << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            swap(mat[i][j], mat[j][i]);
        }
    }
}

void reverseRows(vector<vector<int>> &mat)
{
    for (int i = 0, j = mat.size() - 1; i < j; i++, j--)
    {
        for (int k = 0; k < mat.size(); k++)
        {
            swap(mat[i][k], mat[j][k]);
        }

        // could also do this instead...

        // vector<int> temp = mat[i];
        // mat[i] = mat[j];
        // mat[j] = temp;
    }
}

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> mat(n);
    for (int i = 0; i < n; i++)
    {
        vector<int> v(n);
        for (int j = 0; j < n; j++)
        {
            cin >> v[j];
        }
        mat[i] = v;
    }

    char direction;
    cin >> direction;

    if (direction == 'c')
    {
        reverseRows(mat);
        transpose(mat);
    }
    else if (direction == 'a')
    {
        transpose(mat);
        reverseRows(mat);
    }

    cout << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}