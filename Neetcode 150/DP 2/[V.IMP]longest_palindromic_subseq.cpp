/*
https://leetcode.com/problems/longest-palindromic-subsequence/description/
*/


/*
Approach 1 : (my approach) 
Time : O(n^3)
*/
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 1));

        for(int i=n-2; i>=0; i--) {
            for(int j=i+1; j<n; j++) {
                for(int k=i+1; k<=j; k++) {
                    // for every k from i+1 to j we would check if s[i] == s[k],
                    // if yes, then we would try to find the max length subseq which is palindromic too with s[i] and s[k] as their ends
                    if(s[i] == s[k]) {
                        if(i+1 <= k-1) dp[i][j] = max(dp[i][j], dp[i+1][k-1] + 2);
                        else dp[i][j] = max(dp[i][j], 2);
                    }
                }

                // so by now we have gotten dp[i][j] = max length palindromic subseq with s[i] as its starting
                // to make dp[i][j] = max length palindromic subseq for any subseq between i and j
                // we just compare it with dp[i+1][j] = max length palindromic subseq for any subseq between i+1 and j
                dp[i][j] = max(dp[i][j], dp[i+1][j]);
            }
        }

        return dp[0][n-1];
    }
};


/*
Approach 2 : (neetcode) just apply lcs(longest common subsequence) between s and r(reverse of s)
Time : O(n^2)
because lcs would give us the longest common subsequence between s and r, which would obviously be a subseq of s 
which reads the same backwards too(a palindrome)
*/
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        string r = s;
        reverse(s.begin(), s.end());
        int n = s.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

        for(int i=n-1; i>=0; i--) {
            for(int j=n-1; j>=0; j--) {
                if(s[i] == r[j]) {
                    dp[i][j] = 1 + dp[i+1][j+1];
                }
                else {
                    // dp[i][j] = dp[i+1][j+1];
                    // dp[i][j] = max(dp[i][j], dp[i][j+1]);
                    // dp[i][j] = max(dp[i][j], dp[i+1][j]);
                    dp[i][j] = max(dp[i][j+1], dp[i+1][j]);
                }
            }
        }

        return dp[0][0];
    }
};


/*
Approach 3 : (neetcode) center-out approach : we will pick any i and j and if s[i] == s[j],
we will try to find the max length subseq with s[i]s[j] at its center
It is also similar to lcs approach only if you look at the code
Time : O(n^2)
*/
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        int ans = 1;

        for(int i=0; i<n; i++) {
            for(int j=n-1; j>=i; j--) {
                if(s[i] == s[j]) {
                    if(i == j) {
                        if(i > 0) dp[i][j] = 1 + dp[i-1][j+1];
                        else dp[i][j] = 1;
                    }
                    else {
                        if(i > 0) dp[i][j] = 2 + dp[i-1][j+1];
                        else dp[i][j] = 2;
                    }
                }
                else {
                    // the same lcs approach : max([i][j+1], [i-1][j])
                    // since s[i] != s[j], so we try to find longest subseq with s[i]s[j+1] or s[i-1]s[j] as center
                    dp[i][j] = dp[i][j+1];
                    if(i > 0) dp[i][j] = max(dp[i][j], dp[i-1][j]);
                }

                ans = max(ans, dp[i][j]);
            }
        }

        return ans;
    }
};