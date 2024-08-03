/*
PERMUTATIONS 1 : without duplicates
https://leetcode.com/problems/permutations/description/
*/
class Solution {
public:
   vector<vector<int>> permute(vector<int>& nums) {
      sort(nums.begin(), nums.end());
      int n = nums.size();
      vector<vector<int>> ans;

      int i, j;
      while(1) {
        ans.push_back(nums);
        i = n-1;
        while(i > 0 && nums[i-1] > nums[i]) i--;
        
        if(i == 0) return ans;

        i--;
        j = i+1;
        while(j < n && nums[j] > nums[i]) j++;
        j--;

        swap(nums[i], nums[j]);
        reverse(nums.begin() + i+1, nums.end());
      }

      return ans;
   }
};



/*
PERMUTATIONS 2 : with duplicates
https://leetcode.com/problems/permutations-ii/
*/
class Solution {
public:
   vector<vector<int>> permuteUnique(vector<int>& nums) {
      vector<vector<int>> ans;
      sort(nums.begin(), nums.end());
      
      int n = nums.size();
      int i, j;
      while(1) {
         ans.push_back(nums);
         
         // now generate next lexographically possible permutation 
         i = n-1;
         while(i > 0 && nums[i-1] >= nums[i]) i--;
         if(i == 0) return ans;
         i--;

         j = i+1;
         while(j < n && nums[j] > nums[i]) j++;
         j--;

         swap(nums[i], nums[j]);
         reverse(nums.begin() + i+1, nums.end());
      }

      return ans;
   }
};



// NOTE in cpp STL there is function for getting next permutation
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        ans.push_back(nums);
        while(next_permutation(nums.begin(), nums.end()))
        {
            ans.push_back(nums);
        }
        return ans;
    }
};