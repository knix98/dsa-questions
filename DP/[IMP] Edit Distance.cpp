/*
You are given two strings S and T of lengths M and N, respectively. Find the 'Edit Distance' between the strings.
Edit Distance of two strings is the minimum number of steps required to make one string equal to the other.
In order to do so, you can perform the following three operations:
1. Delete a character
2. Replace a character with another one
3. Insert a character
Note :
Strings don't contain spaces in between.

Sample Input 1 :
abc
dc
Sample Output 1 :
2
 Explanation to the Sample Input 1 :
 In 2 operations we can make string T to look like string S.
First, insert character 'a' to string T, which makes it "adc".

And secondly, replace the character 'd' of string T with 'b' from the string S.
This would make string T as "abc" which is also string S.

Hence, the minimum distance.
*/

// SOLUTION : For explanation you can refer CN DP-2 Notes...
#include <algorithm>
#include <climits>

int editDistance(string s1, string s2)
{
    int rows = s1.size() + 1;
    int cols = s2.size() + 1;

    int **dp = new int *[rows];
    for (int i = 0; i < rows; i++)
    {
        dp[i] = new int[cols]{0};
    }

    // filling bottom row...where s1.size() == 0, so simply fill s2.size() in each cell
    for (int j = cols - 1; j >= 0; j--)
    {
        dp[rows - 1][j] = (cols - 1) - j;
    }

    // filling last column...where s2.size() == 0, so simply fill s1.size() in each cell
    for (int i = rows - 1; i >= 0; i--)
    {
        dp[i][cols - 1] = (rows - 1) - i;
    }

    for (int i = rows - 2; i >= 0; i--)
    {
        for (int j = cols - 2; j >= 0; j--)
        {
            if (s1[i] == s2[j])
            {
                // if first char of both words are same, then 1st char is sorted,
                //  so we just need to return the ans for s1.substr(i+1), s2.substr(j+1)
                dp[i][j] = dp[i + 1][j + 1];
                continue;
            }

            int dist = INT_MAX;

            // otherwise the 3 cases -> inserted, deleted, replaced the 1st char in s1
            if (j + 1 < cols && dp[i][j + 1] < dist)
            {
                dist = dp[i][j + 1];
            }
            if (i + 1 < rows && dp[i + 1][j] < dist)
            {
                dist = dp[i + 1][j];
            }
            if (i + 1 < rows && j + 1 < cols && dp[i + 1][j + 1] < dist)
            {
                dist = dp[i + 1][j + 1];
            }

            dp[i][j] = 1 + dist;
        }
    }

    return dp[0][0];
}