/*
https://leetcode.com/problems/word-break/description/
*/

/*
If size of wordDict = n, length og words in wordDict = m, length of s = l
Time = O(n) + O(l^2) , if we do not consider the work done to calculate the key for a particular string when finding/inserting in a map
Time = O(mn) + O(l^3) , if we consider the work done to calculate the key for a particular string when finding/inserting in a map
Space = O(n + l) , since keys (string) are not stored in the map, but only the values (bool) are stored
*/
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string, bool> mp;
        for(string s : wordDict) mp[s] = true;

        vector<bool> dp(s.size() + 1, false);  // dp[i] = true means ans for substring from i to end is true
        dp[s.size()] = true;  // for empty string case, ans = true

        string check = "";
        for(int i = s.size() - 1; i>=0; i--) {
            for(int j = i; j<s.size(); j++) {
                check += s[j];
                if(mp.count(check) && dp[j+1]) {
                    dp[i] = true;
                    break;
                } 
            }

            check = "";
        }

        return dp[0];
    }
};