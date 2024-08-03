/*
Basically here we can group anagrams only if we sort each words then only we can match anagrams.
But better time efficient way would be to use a frequency table for generating hashes of each word instead of sorting in following manner:
"aate" => hash = "2a1e1t"
"atae" => hash = "2a1e1t"
*/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;

        string hash;
        for(string s : strs){
            hash = "";
            vector<int> fq(26, 0);
            for(char c : s) fq[(int)c - (int)'a']++;
            for(int i=0; i<26; i++) {
                if(fq[i]){
                    hash += (char)(fq[i] + (int)'0');
                    hash += (char)(i + (int)'a');
                }
            }

            mp[hash].push_back(s);
        }

        vector<vector<string>> ans;
        for(auto i : mp){
            vector<string> v;
            for(string s : i.second) v.push_back(s);
            ans.push_back(v);
        }

        return ans;
    }
};