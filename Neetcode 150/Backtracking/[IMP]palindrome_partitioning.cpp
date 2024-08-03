/*
https://leetcode.com/problems/palindrome-partitioning/description/
*/


class Solution {
private:
   string s;
   int n;
   vector<vector<bool>> isPalindrome;
   vector<vector<string>> ans;
   vector<string> curr;

    // pre calculate isPalindrome for all the substrings of the string
   void pre_process() {
      for(int i = 1; i<n; i++) {
         for(int j = i-1; j>=0; j--) {
            if(isPalindrome[i-1][j+1] && s[i] == s[j]) isPalindrome[i][j] = true;
            else isPalindrome[i][j] = false;
         }
      }
   }

   void helper(int i) {
      if(i >= n) {
         ans.push_back(curr);
         return;
      }

      string temp = "";
      for(int j=i; j<n; j++) {
         temp += s[j];
         if(isPalindrome[j][i]) {
            curr.push_back(temp);
            helper(j+1);
            curr.pop_back();
         }
      }
   }

public:
   vector<vector<string>> partition(string s) {
      this->s = s;
      n = s.size();
      isPalindrome = vector<vector<bool>>(n, vector<bool>(n, true));
      ans.clear();
      curr.clear();

      pre_process();
      helper(0);

      return ans;
   }
};