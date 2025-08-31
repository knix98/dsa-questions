/*
https://leetcode.com/problems/partition-equal-subset-sum/description/
*/

/*
have to do a 2D DP in which we calculate for each index i whether we can make sums{0...target} using elements from index i to end only
Time : O(n * target)
Space : O(target)
where target = (sum of all elems) / 2 

so from this solution code we can see that, in problems where it looks like we need to build all the subsequences and compare them, which will lead to
2^n time, we can utilise 2D DP instead (if possible in problems of subsequences) which will reduce time to around n^2

NOTE : a tougher variation of this problem : "partition to k equal sum subsets" is saved in Backtracking chapter codes of neetcode 150
*/
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int total = 0;
        for(int i : nums) total += i;

        if(total % 2) return false;
        total /= 2;

        vector<vector<bool>> dp(2, vector<bool>(total+1, false));
        int curr = 0, prev = 1;
        dp[prev][0] = true;

        for(int i=n-1; i>=0; i--) {
            for(int j=0; j<=total; j++) {
                dp[curr][j] = false;
                
                // case 1 : skipping curr elem
                if(dp[prev][j]) dp[curr][j] = true;
                else {
                    // case 2 : take curr elem if possible
                    if(j - nums[i] >= 0) {
                        dp[curr][j] = dp[prev][j-nums[i]];
                    }
                }

                if(j == total && dp[curr][j]) return true;
            }

            swap(curr, prev);
        }

        return false;
    }
};