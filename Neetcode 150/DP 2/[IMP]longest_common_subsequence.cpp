/*
https://leetcode.com/problems/longest-common-subsequence/description/
*/


/*
Time complexity: O(m∗n)
Space complexity: O(min(m,n))
*/
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        if(text1.size() < text2.size()) return longestCommonSubsequence(text2, text1);
        int m = text1.size();
        int n = text2.size();

        vector<vector<int>> dp(2, vector<int>(n+1, 0));

        int curr = 0, prev = 1;
        for(int i=m-1; i>=0; i--) {
            for(int j=n-1; j>=0; j--) {
                dp[curr][j] = max(dp[curr][j+1], dp[prev][j]);
                if(text1[i] == text2[j]) dp[curr][j] = max(dp[curr][j], 1 + dp[prev][j+1]);
            }
            swap(prev, curr);
        }

        return dp[prev][0];
    }
};