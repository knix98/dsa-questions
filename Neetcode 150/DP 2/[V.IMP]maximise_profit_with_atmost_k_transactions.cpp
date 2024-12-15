/*
best transaction strategy to maximize the profit of the company if he can make a maximum of ‘K’ possible transactions.

Note: A valid transaction involves buying a stock and then selling it. You can’t engage in multiple transactions simultaneously, 
i.e. you must sell the stock before rebuying it.

For Example
Input: N = 6 , PRICES = [3, 2, 6, 5, 0, 3] and K = 2.
Output: 7

Explanation : The optimal way to get maximum profit is to buy the stock on day 2(price = 2) and sell it on day 3(price = 6) and 
rebuy it on day 5(price = 0) and sell it on day 6(price = 3). The maximum profit will be (6 - 2) + (3 - 0) = 7.
*/

/*
NOTE : the below template can be applied to other questions also which for example allows atmost 2 transactions
*/
int maximumProfit(vector<int> &prices, int n, int k)
{
    vector<vector<vector<int>>> dp(2, vector<vector<int>>(k+1, vector<int>(2, 0)));

    int curr = 0, prev = 1;
    for(int i=n-1; i>=0; i--) {
        for(int j=1; j<=k; j++) {
            // case 1 : we are in buy state (3rd index of dp == 0)
            // case 1a : buy curr
            dp[curr][j][0] = dp[prev][j][1] - prices[i];

            // case 1b : skip curr
            dp[curr][j][0] = max(dp[curr][j][0], dp[prev][j][0]);

            // case 2 : we are in sell state (3rd index of dp == 1)
            // case 2a : sell curr
            dp[curr][j][1] = dp[prev][j-1][0] + prices[i];

            // case 2b : skip curr
            dp[curr][j][1] = max(dp[curr][j][1], dp[prev][j][1]);
        }

        swap(curr, prev);
    }

    return dp[prev][k][0];
}