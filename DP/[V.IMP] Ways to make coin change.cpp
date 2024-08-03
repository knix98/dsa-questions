/*
For the given infinite supply of coins of each of denominations, D = {D0, D1, D2, D3, ...... Dn-1}.
You need to figure out the total number of ways W, in which you can make the change for Value V using coins of denominations D.
Return 0 if the change isn't possible.

Constraints :
1 <= n <= 10
1 <= V <= 1000
Time Limit: 1sec

Sample Input 1 :
3
1 2 3
4
Sample Output 1 :
4
Explanation to Sample Input 1 :
Number of ways are - 4 total i.e. (1,1,1,1), (1,1, 2), (1, 3) and (2, 2).

Sample Input 2 :
6
1 2 3 4 5 6
250
Sample Output 2 :
13868903
*/

// Solution explanation written in DSA revison notes...
int countWaysToMakeChange(int denominations[], int numDenominations, int value)
{
    int **dp = new int *[value + 1];
    for (int i = 0; i < value + 1; i++)
    {
        dp[i] = new int[numDenominations]{0};
    }

    for (int i = 1; i < value + 1; i++)
    {
        for (int j = 0; j < numDenominations; j++)
        {
            if (i - denominations[j] > 0)
            {
                int row = i - denominations[j];
                for (int k = j; k < numDenominations; k++)
                {
                    dp[i][j] += dp[row][k];
                }
            }
            else if (i - denominations[j] == 0)
            {
                dp[i][j] = 1;
            }
        }
    }

    int ans = 0;
    for (int j = 0; j < numDenominations; j++)
    {
        ans += dp[value][j];
    }

    return ans;
}