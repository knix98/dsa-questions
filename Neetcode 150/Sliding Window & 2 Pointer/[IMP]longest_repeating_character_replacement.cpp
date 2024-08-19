/*
https://leetcode.com/problems/longest-repeating-character-replacement/description/
*/


/*
Time : O(26*n) = O(n)
Space : O(26)
*/
class Solution {
public:
    int characterReplacement(string s, int k) {
        int fq[26] = {0};  // in this we will only store fq of those chars which are uppercase

        int ans = 0, l = 0;
        int ascii, maxFq = 0;
        for(int r = 0; r < s.size(); r++) {
            ascii = s[r] - 'A';
            if(ascii >= 0 && ascii < 26) {
                // means this is a uppercase letter
                fq[ascii]++;
                maxFq = max(maxFq, fq[ascii]);
            }

            while(l <= r && (r-l+1) - maxFq > k) {
                ascii = s[l] - 'A';
                if(ascii >= 0 && ascii < 26) {
                    // means this is a uppercase letter
                    fq[ascii]--;
                    maxFq = 0;
                    for(int i=0; i<26; i++) maxFq = max(maxFq, fq[i]);
                }
                l++;
            }

            if((r-l+1) - maxFq <= k) {
                ans = max(ans, (r-l+1));
            }
        }

        return ans;
    }
};