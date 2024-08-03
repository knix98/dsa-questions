/*
Problem Statement: The longest common subsequence (LCS) is defined as the
longest subsequence that is common to all the given sequences, provided that the
elements of the subsequence are not required to occupy consecutive positions
within the original sequences.

Note: Subsequence is a part of the string which can be made by omitting none or
some of the characters from that string while maintaining the order of the
characters.
If s1 and s2 are two given strings then z is the common subsequence of s1 and s2, if
z is a subsequence of both of them.

Example 1:
s1 = “abcdef”
s2 = “xyczef”
Here, the longest common subsequence is “cef”; hence the answer is 3 (the length
of LCS).

*/

// FOr APPROACH of solution: read CN Notes of DP-2
#include <bits/stdc++.h>
using namespace std;

int lcs(string a, string b)
{
    int rows = a.size() + 1;
    int cols = b.size() + 1;

    int **dp = new int *[rows];
    for (int i = 0; i < rows; i++)
    {
        dp[i] = new int[cols]{0};
    }

    // dp[i][j] signifies lcs of 2 strings -> 1. a.substr(i), 2. b.substr(j)
    for (int i = rows - 1; i >= 0; i--)
    {
        for (int j = cols - 1; j >= 0; j--)
        {
            int lcs = 0;

            if (j + 1 < cols && dp[i][j + 1] > lcs)
            {
                lcs = dp[i][j + 1];
            }
            if (i + 1 < rows && dp[i + 1][j] > lcs)
            {
                lcs = dp[i + 1][j];
            }
            if (i + 1 < rows && j + 1 < cols)
            {
                int check = dp[i + 1][j + 1];
                if (a[i] == b[j])
                {
                    check = 1 + dp[i + 1][j + 1];
                }

                if (check > lcs)
                {
                    lcs = check;
                }
            }

            dp[i][j] = lcs;
        }
    }

    return dp[0][0];
}

int main()
{
    cout << lcs("ahkoolp", "cohfop");
}