/*
Given an NxM matrix that contains only 0s and 1s, find out the size of the maximum square sub-matrix with all 0s.
You need to return the size of the square matrix with all 0s.

Constraints :
0 <= N <= 10^4
0 <= M <= 10^4
Time Limit: 1 sec

Sample Input 1:
3 3
1 1 0
1 1 1
1 1 1
Sample Output 1:
1

Sample Input 2:
4 4
0 0 0 0
0 0 0 0
0 0 0 0
0 0 0 0
Sample Output 2:
4
*/

#include <vector>
#include <algorithm>
using namespace std;

int findMaxSquareWithAllZeros(int **arr, int n, int m)
{
    int ans = 0; // for now the max square size is 0
    vector<vector<int>> dp(n, vector<int>(m));

    // dp[i][j] = length of maximum square matrix with all 0s whose bottom left vertex is at arr[i][j]

    // first fill the first row...
    for (int j = 0; j < m; j++)
    {
        dp[0][j] = arr[0][j] == 0 ? 1 : 0;
    }

    // now fill the first col...
    for (int i = 0; i < n; i++)
    {
        dp[i][0] = arr[i][0] == 0 ? 1 : 0;
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            if (arr[i][j] == 1)
            {
                dp[i][j] = 0;
            }
            else
            {
                dp[i][j] = min({dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]}) + 1;
            }

            ans = dp[i][j] > ans ? dp[i][j] : ans;
        }
    }

    return ans;
}