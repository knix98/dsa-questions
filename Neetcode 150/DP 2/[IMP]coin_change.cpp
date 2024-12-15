/*
https://leetcode.com/problems/coin-change-ii/description/

Although the below solution will fail on a last test case but that's leetcode's bullshit, since neetcode's solution is also failing there
*/


/*
dp relation is simple that 
case 1 : pick 1 coin from current index and then call dp on same index : dp[curr][am] = dp[curr][am - coins[i]]
case 2 : dont pick any coin from curr index : dp[prev][am]
*/

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<long long>> dp(2, vector<long long>(amount + 1, 0));
        int curr = 0, prev = 1;
        dp[prev][0] = 1;  // when i == n, means no coins, so only 1 would be there for 0 amount

        for(int i = n-1; i>=0; i--) {
            for(int am = 0; am <= amount; am++) {
                dp[curr][am] = 0;
                if(am - coins[i] >= 0) dp[curr][am] = dp[curr][am - coins[i]];
                dp[curr][am] += dp[prev][am];
            }

            swap(curr, prev);
        }

        return dp[prev][amount];
    }
};