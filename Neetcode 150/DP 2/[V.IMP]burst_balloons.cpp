/*
https://leetcode.com/problems/burst-balloons/
*/


/*
Time : n^3
Space : n^2 (but dp space can be optimised)
*/
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        for(int subArrLen = 1; subArrLen <= n; subArrLen++) {
            for(int le = 0; le <= n-subArrLen; le++) { // le = left end of the current subarray window
                int re = le + subArrLen - 1; // re = right end of the current subarray window
                int coins, endsMultiplier = 1;
                if(re + 1 < n) {
                    // means nums[re+1] exists around the right of the current subarray window
                    // hence this would need to be multiplied with every last remaining number in the current subarray window
                    endsMultiplier *= nums[re+1];
                }
                if(le - 1 >= 0) {
                    // similarly for the left end also
                    endsMultiplier *= nums[le-1];
                }

                // for the current current subarray window we consider every num inside it as the last remaining num and compute the coins in
                // each of these cases and do max() for the final ans for the current subarray window
                for(int i = le; i<=re; i++) {
                    // nums[i] is the last remaining num in the current subarray window
                    // so in the coins we add nums[i] after multiplying with the subarray-surroundings multiplier calculated before
                    coins = nums[i] * endsMultiplier;

                    // in the end we also need to add the ans for the 2 subarrays in the current subarray window on either side of nums[i]
                    if(i+1 <= re) coins += dp[i+1][re];
                    if(i-1 >= le) coins += dp[le][i-1];

                    dp[le][re] = max(coins, dp[le][re]);
                }
            }
        }

        return dp[0][n-1];
    }
};