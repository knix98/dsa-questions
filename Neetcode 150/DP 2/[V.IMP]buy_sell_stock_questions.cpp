/*
1. DP trick for buy-sell-stock questions : do 1D DP on the prices array with two states : buy state profit and sell state profit
2. In some questions, there might be condition of atmost K transactions, n those a 2D dp would be required with the addition of K as the second dimension\
3. Although do remember that in a simple 1 transaction at a time and infinite transaction question, you can be greedy and just collect
    the profits over all the positive slopes in the visualised graph of the prices array
*/


// VARIETY 1 : atmost k transactions allowed...
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


// VARIETY 2 : infinite transactions allowed but only 1 transaction at a given time
// greedy is applied but th template of DP also works
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        for(int i=1; i<prices.size(); i++) {
            if(prices[i] > prices[i-1]) profit += (prices[i] - prices[i-1]);
        }
        return profit;
    }
};
// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         int n = prices.size();
//         if(n == 0) return 0;

//         int bought_state_profit = prices[n-1];
//         int sold_state_profit = 0;

//         int curr_bsp, curr_ssp;
//         for(int i=n-2; i>=0; i--) {
//             curr_bsp = max(prices[i] + sold_state_profit, bought_state_profit);
//             curr_ssp = max(bought_state_profit - prices[i], sold_state_profit);
//             bought_state_profit = curr_bsp;
//             sold_state_profit = curr_ssp;
//         }

//         return sold_state_profit;
//     }
// };


// VARIETY 3 : bus and sell stocks with cooldown period
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int>(2, 0));
        dp[n-1][0] = 0;  // can buy (or skip buy) state at last price element
        dp[n-1][1] = prices[n-1];  // can sell (or skip sell) state at last price element
        for(int i=n-2; i>=0; i--) {
            // calculating for buy state : lets buy
            dp[i][0] = dp[i+1][1] - prices[i];

            // calculating for buy state : lets skip buy
            dp[i][0] = max(dp[i][0], dp[i+1][0]);

            // calculating for sell state : lets sell
            dp[i][1] = prices[i] + dp[i+2][0];

            // calculating for sell state : lets skip sell
            dp[i][1] = max(dp[i][1], dp[i+1][1]);
        }

        return dp[0][0];
    }
};


// VARIETY 4 : buy-and-sell-stock-with-transaction-fee
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/description/
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int curr_buy_state_profit, curr_sell_state_profit, prev_buy_state_profit = 0, prev_sell_state_profit = 0;
        for(int i=prices.size()-1; i>=0; i--) {
            curr_buy_state_profit = max(prev_buy_state_profit, prev_sell_state_profit - prices[i]); // max(skip curr buy, do curr buy)
            curr_sell_state_profit = max(prev_sell_state_profit, prev_buy_state_profit + prices[i] - fee); // max(skip curr sell, do curr sell)
            prev_buy_state_profit = curr_buy_state_profit;
            prev_sell_state_profit = curr_sell_state_profit;
        }

        return prev_buy_state_profit;
    }
};