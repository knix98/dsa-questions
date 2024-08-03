/*
Gary has two string S and V. Now, Gary wants to know the length shortest subsequence in S, which is not a subsequence in V.
Note: The input data will be such that there will always be a solution.

Constraints:
1 <= |S| <= 1000 (|x| implies the length of the string x)
1 <= |V| <= 1000
Time Limit: 1 second

Sample Input 1:
babab
babba
Sample Output 1:
3
Explanation:
"aab" is the shortest subsequence which is present in S and absent in V.
*/

// Solution approach written in DSA revison notes...
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

int solve(string s, string v)
{
    int rows = s.size() + 1;
    int cols = v.size() + 1;

    vector<vector<int>> dp(rows, vector<int>(cols, 0));

    // this is a helper array which in which,
    // position[i][j] = index where s[i] is first encountered if we start looking for it in string v from index=j
    vector<vector<int>> position(rows - 1, vector<int>(cols - 1));

    // first fill the position array...
    for (int i = rows - 2; i >= 0; i--)
    {
        int currentPosition = -1; // since we haven't found s[i] yet
        for (int j = cols - 2; j >= 0; j--)
        {
            if (s[i] == v[j])
            {
                currentPosition = j;
            }

            position[i][j] = currentPosition;
        }
    }

    // now fill the dp...
    // first filling the last row...
    for (int j = 0; j < cols; j++)
    {
        dp[rows - 1][j] = INT_MAX;
        // since if s.size() == 0, so only 1 subseq present in s which is empty seq("")
        // and empty subseq is always present in v no matter v's size
        // so we put INT_MAX so that this ans is always bigger than the other ans, and hence never becomes the final ans after comparison
    }

    // now filling the last col...
    for (int i = 0; i < rows - 1; i++)
    {
        dp[i][cols - 1] = 1;
        // since v.size() == 0, and s.size() >= 1, then shortest subseq not present in v wud be of length 1
    }

    for (int i = rows - 2; i >= 0; i--)
    {
        for (int j = cols - 2; j >= 0; j--)
        {
            int smallAns = dp[i + 1][j];

            // getting index of s[i] in v
            int k = position[i][j];

            int includedAns;
            if (k == -1) // means s[i] was not found, so s[i] of length 1 is itself the smallest subseq not found in current substr of v
            {
                includedAns = 1;
            }
            else
            {
                int x = dp[i + 1][k + 1];
                if (x == INT_MAX)
                {
                    includedAns = INT_MAX;
                }
                else
                {
                    includedAns = 1 + x;
                }
            }

            dp[i][j] = min(smallAns, includedAns);
        }
    }

    return dp[0][0];
}