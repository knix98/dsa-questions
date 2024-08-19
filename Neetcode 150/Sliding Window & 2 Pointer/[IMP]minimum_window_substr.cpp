/*
https://leetcode.com/problems/minimum-window-substring/description/
*/


/*
Given 2 strings s & t, return min window substring
of s such that all chars in t are included in window
Ex. s = "ADOBECODEBANC" t = "ABC" -> "BANC"

Sliding window + fq table {ascii -> count}
Move r until valid, move l to find smaller

Time : O(m+n)
Space : O(1)
*/
class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> fq(256, INT_MAX);  // we will only count the fq of chars that are in string t, others fq we dont need to store so store INT_MAX in them
                                        // since during code fq of some of the relevant char might go -ve also
        int ans = INT_MAX;  // minWindow length
        int ansl, ansr;   // minWindow left and right pointers

        int total_distinct = 0;   // total distinct chars in t
        for(char c : t) {
            if(fq[c] == INT_MAX) {
                fq[c] = 0;
                total_distinct++;
            } 
            fq[c]++;
        }

        int l=0;
        for(int r=0; r < s.size(); r++) {
            if(fq[s[r]] != INT_MAX) {
                fq[s[r]]--;
                if(fq[s[r]] == 0) total_distinct--;  // decrement total_distinct only when all the count of a relevant char has been incorporated in the current window
            }   

            while(total_distinct == 0 && l <= r) {
                if(r-l+1 < ans) {  // if total_distinct == 0 in current window then this is a valid window
                    ans = r-l+1;
                    ansl = l;
                    ansr = r;
                }
                if(fq[s[l]] != INT_MAX) {
                    fq[s[l]]++;
                    if(fq[s[l]] == 1) total_distinct++;   // only when fq on some relevant char becomes 1 again then increment total_distinct
                }
                l++;
            }
        }

        return ans == INT_MAX ? "" : s.substr(ansl, ansr - ansl + 1);
    }
};