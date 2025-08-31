// https://leetcode.com/problems/distinct-subsequences/


/*
Approach : dp[i][j] = no. of subsequences of from A (A = substr of s from i to end) which equals B (B = substr of t from j to end)
*/
class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.length(), n = t.length();
        if(m < n) return 0;
        else if(m == n) return s == t;

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (int i = 0; i <= m; i++) {
            dp[i][n] = 1;
        }

        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                // case 1 : we dont take the current s[i]
                dp[i][j] = dp[i + 1][j];

                // case 2 : we take the current s[i] if s[i] == t[j] (t[j] == the first char of the substr of t (from j to n-1) under consideration)
                if (s[i] == t[j]) {
                    dp[i][j] += dp[i + 1][j + 1];
                }
            }
        }

        return dp[0][0];
    }
};