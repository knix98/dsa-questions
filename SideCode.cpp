#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string, bool> mp;
        for(string s : wordDict) mp[s] = true;

        vector<bool> dp(s.size() + 1, false);
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