/*
https://leetcode.com/problems/coin-change/description/

Although the below solution will fail on a last test case but that's leetcode's bullshit, since neetcode's solution is also failing there
*/


/*
dp relation is simple that 
case 1 : pick 1 coin from current index and then call dp on same index : dp[curr][am] = dp[curr][am - coins[i]]
case 2 : dont pick any coin from curr index : dp[prev][am]
*/


/*
Time : O(n*t)
Space : O(t)
where n = length of coins array, t = amount
*/
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;
        for (int i = 1; i <= amount; i++) {
            for (int j = 0; j < coins.size(); j++) {
                if (coins[j] <= i) {
                    // since dp[i] would already be containing the value of previous iteration
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1);
                }
            }
        }
        return dp[amount] > amount ? -1 : dp[amount];
    }
};