/*
https://leetcode.com/problems/interleaving-string/description/
*/

/*
Approach : in s1 = "abc", s2 = "abc", s3 = "aabbcc"
dp[1][2] = whether "bc"(from s1) & "c"(from s2) can form "bcc"(from s3) in interleaving fashion 
*/
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int l1 = s1.size(), l2 = s2.size();
        if(l1 + l2 != s3.size()) return false;
        
        vector<vector<bool>> dp(l1+1, vector<bool>(l2+1, false));
        dp[l1][l2] = true;

        for(int i = l1; i>=0; i--) {
            for(int j = l2; j>=0; j--) {
                if(i < l1 && s1[i] == s3[i+j] && dp[i+1][j]) {
                    dp[i][j] = true;
                    continue;
                }
                if(j < l2 && s2[j] == s3[i+j] && dp[i][j+1]) {
                    dp[i][j] = true;
                }
            }
        }

        return dp[0][0];
    }
};