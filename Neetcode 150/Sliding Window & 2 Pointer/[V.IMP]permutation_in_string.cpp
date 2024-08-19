/*
https://leetcode.com/problems/permutation-in-string/description/
*/


class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int fq[26] = {0};
        for(int ascii : s1) fq[ascii - 97]++;
        int total = s1.size();  // total chars that need to be found in s2 continuous

        int l=0;
        for(int r=0; r < s2.size(); r++) {
            while(fq[s2[r] - 'a'] == 0 && l < r) {
                fq[s2[l] - 'a']++;
                total++;
                l++;
            }

            if(fq[s2[r] - 'a'] > 0) {
                // so we want this char in our window
                fq[s2[r] - 'a']--;
                total--;
                if(total == 0) {
                    // means we found all chars of s1 in the current window
                    return true;
                }
            }
            else {
                // so we dont want this char in our window. so at this moment l and r would be coinciding and we need to move both of them forward
                // so just move l forward
                l++;
            }
        }

        return false;
    } 
};