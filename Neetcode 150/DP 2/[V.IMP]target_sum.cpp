/*
https://leetcode.com/problems/target-sum/
*/


/*
Approach 1 : easier approach (neetcode approach)
for each index i store all the sums possible with nums from i to end and the number of ways to make these sums in a map
and then when you move to i-1 index you can use map of i to make map for the curr i-1
since the sum values can have range between [-(sum of all nums), (sum of all nums)], Time : O(n*(sum of all nums))
*/
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int, int> prevDp;  // <sum value, number of ways to make this sum>
        prevDp[0] = 1; // base case : only zero sum can be formed in 1 way by empty set

        for(int i=n-1; i>=0; i--) {
            unordered_map<int, int> currDp;
            for(auto &p : prevDp) {
                currDp[p.first - nums[i]] += p.second;
                currDp[p.first + nums[i]] += p.second;
            }

            prevDp = currDp;
        }

        return prevDp[target];
    }
};


/*
Approach 2 : my approach pure dp
we will do simple target-sum 2D dp. But since here nums can be -ve also, the y axis would range from -(sum of all nums) to +(sum of all nums)
so to adjust these -ve y indices, we would need to shift all indices in y by (sum of all nums) value
*/
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int maxSum = 0; // maxSum will be our shifting factor for y axis indices
        for(int i : nums) maxSum += abs(i);

        if(abs(target) > maxSum) return 0;

        int dpSize = 2*maxSum;
        vector<vector<int>> dp(2, vector<int>(dpSize + 1, 0));
        int prev = 1, curr = 0;
        dp[prev][maxSum] = 1; // base case : empty set can only make 0 sum in 1 way

        for(int i=nums.size()-1; i>=0; i--) {
            for(int j=0; j<=dpSize; j++) {
                dp[curr][j] = 0;
                int actualTarget = j - maxSum;

                // case 1 -> -nums[i]
                int targetToFindInPrev = actualTarget + nums[i];
                int actualTargetIndexInPrev = targetToFindInPrev + maxSum; // index shifting
                // the below if condition is necessary because sometimes actualTargetIndexInPrev value can go beyond the range which we dont need to consider
                // by "dont need to consider" I mean those out-of-range values are impossible to be made with nums, so we take 0 possible ways for these values
                if(actualTargetIndexInPrev <= dpSize && actualTargetIndexInPrev >= 0) dp[curr][j] += dp[prev][actualTargetIndexInPrev];

                // case 2 -> +nums[i]
                targetToFindInPrev = actualTarget - nums[i];
                actualTargetIndexInPrev = targetToFindInPrev + maxSum; // index shifting
                // the below if condition is necessary because sometimes actualTargetIndexInPrev value can go beyond the range which we dont need to consider
                if(actualTargetIndexInPrev <= dpSize && actualTargetIndexInPrev >= 0) dp[curr][j] += dp[prev][actualTargetIndexInPrev];
            }

            curr = !curr;
            prev = !prev;
        }

        return dp[prev][target + maxSum];
    }
};