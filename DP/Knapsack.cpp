/*
A thief is robbing a store and can carry a maximal weight of W into his knapsack.
There are N items and ith item weighs wi and is of value vi.
Considering the constraints of maximum weight that knapsack can carry,
you have to find and return the maximum value that thief can generate by stealing items.

Note
Space complexity should be O(W).
*/

// For understanding solution...can look into CN DP-2 notes
int knapsack(int *weight, int *value, int n, int maxWeight)
{
    int rows = maxWeight + 1;
    int cols = n + 1;

    int **dp = new int *[rows];
    for (int i = 0; i < rows; i++)
    {
        dp[i] = new int[cols]{0};
    }

    // first row and last column are already filled with zeroes...so we start with the other cells
    for (int i = 1; i < rows; i++)
    {
        for (int j = cols - 2; j >= 0; j--)
        {
            int maxValue = 0;

            if (dp[i][j + 1] > maxValue)
            {
                maxValue = dp[i][j + 1];
            }
            if (i - weight[j] >= 0)
            {
                int check = dp[i - weight[j]][j + 1] + value[j];
                if (check > maxValue)
                {
                    maxValue = check;
                }
            }

            dp[i][j] = maxValue;
        }
    }

    int ans = dp[maxWeight][0];
    for (int i = 0; i < rows; i++)
    {
        delete[] dp[i];
    }
    delete[] dp;
    return ans;
}

// space optimised DP Solution....(using only 2 rows)
int knapsack(int *weight, int *value, int n, int maxWeight)
{
    int arr[2][maxWeight + 1];
    int curr, prev;
    for (int i = n; i >= 0; i--)
    {
        for (int w = 0; w < maxWeight + 1; w++)
        {
            curr = i % 2;       // curr = row currently being filled(either 0 or 1)
                                // curr signifies the start index i from which the elements are considered
            prev = (i + 1) % 2; // prev = row being used to fill the curr row
                                // prev signifies the i+1 start index of elements for which we saved the results in previous iteration of outer loop
            if (i == n || w == 0)
            {
                arr[curr][w] = 0;
                continue;
            }

            if (weight[i] <= w)
            {
                arr[curr][w] = max(arr[prev][w - weight[i]] + value[i], arr[prev][w]);
            }
            else
            {
                arr[curr][w] = arr[prev][w];
            }
        }
    }

    return arr[curr][maxWeight];
}
