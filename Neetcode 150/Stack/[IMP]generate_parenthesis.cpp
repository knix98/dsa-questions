/*
https://leetcode.com/problems/generate-parentheses/description/
*/


/*
its actually a backtracking problem
Intuition : consider when we enter a '(' the sum becomes +1 and sum becomes -1 when a ')' enters
this way in recursion code we can check that the sum should not go -ve at any point of time
and at the end base case : that all the left and right brackets have been used up and sum == 0
IMPORTANT : in the end in the base case we are not worried about checking whether the generated check string is unique or not
because it will always be unique for sure because,
every step of recursion we can think of as handelling 1 position of the 2n length string (n is the input given in question)
and hence its not possible that the recursion would put the same brackets again at the same place
*/
class Solution {
private:
   vector<string> ans;
   int l, r, sum;  // l = r = the number of left and right brackets available with us (not pushed into the check string)
   string check;

   void helper() {
      if(sum < 0) return;
      else if(!l && !r) {
         if(!sum) ans.push_back(check);
         return;
      }

      if(l) {
         check.push_back('(');
         l--, sum++;
         helper();
         check.pop_back();
         l++, sum--;
      }
      if(r) {
         check.push_back(')');
         r--, sum--;
         helper();
         check.pop_back();
         r++, sum++;
      }
   }

public:
   vector<string> generateParenthesis(int n) {
      l = r = n;
      sum = 0;
      check = "";
      ans.clear();

      helper();

      return ans;
   }
};