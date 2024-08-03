/*
https://leetcode.com/problems/subsets-ii/description/
*/


class Solution {
private:
   vector<vector<int>> ans;
   vector<int> curr;
   vector<int> nums;
   int n;

   void helper(int i) {
      if(i >= n) {
         ans.push_back(curr);
         return;
      }

      // case 1 : we will take nums[i] in curr
      // NOTE IMP : always think of recursion in the CN way only : I will handle this small part and trust recursion to do the job for the other part
      curr.push_back(nums[i]);
      helper(i+1);
      curr.pop_back();

      // case 2 : not take nums[i]...so we will not take all elems ahead which are equal to nums[i] to avoid duplicates
      int j = i+1;
      while(j < n && nums[j] == nums[i]) j++;
      helper(j);
   }

public:
   vector<vector<int>> subsetsWithDup(vector<int>& nums) {
      sort(nums.begin(), nums.end());
      ans.clear();
      curr.clear();
      this->nums = nums; // this in c++ is a pointer to the object/instance of the class
      n = nums.size();
      helper(0);
      return ans;
   }
};