/*
https://leetcode.com/problems/combination-sum/description/
*/

// COMBINATION SUN 1
/*
first approach coded by me : At a particular recursion step i, basically first take as much v[i] as possible and then call recursion on i+1
and then dont take any v[i] and call recursion on i+1
But in this approach spach is getting wasted in every time passing a new check array for each recursion step
Hence the second solution pasted below is space optimised also
*/ 
/*
Time : O(2^target)
Space : O(target)
because worst case : candidates = {1}
*/
class Solution {
private:
   vector<vector<int>> ans;
   int target;

   void helper(vector<int>& v, int i, vector<int> check, int checkSum) {
      if(i == v.size()) {
         if(checkSum == target) ans.push_back(check);
         return;
      }

      while(checkSum <= target) {
         helper(v, i+1, check, checkSum);
         check.push_back(v[i]);
         checkSum += v[i];
      }
   }

public:
   vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
      ans.clear();
      this->target = target;
      helper(candidates, 0, {}, 0);
      return ans;
   }
};



// space optimised solution 
class Solution {
private:
   vector<vector<int>> ans;
   vector<int> check; 
   int checkSum;
   int target;

   void helper(vector<int>& v, int i) {
      if(checkSum == target) {  // since target and v[i] would all be +ve according to question, so if we find target midway path, then return
         ans.push_back(check);
         return;
      }
      else if(checkSum > target || i == v.size()) return;

      // we do a similar thing in dp also => f(target(t), i) = f(t - v[i], i) + f(t, i+1);
      check.push_back(v[i]);
      checkSum += v[i];
      helper(v, i);
      check.pop_back();
      checkSum -= v[i];

      helper(v, i+1);
   }

public:
   vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
      // we dont need to sort the candidates vector initially, because if you do a dry run and build the check array while recursion,
      // you will find out that every time the path taken and hence the check built at the end of the path is different

      ans = vector<vector<int>>(0);
      check = vector<int>(0);
      checkSum = 0;
      this->target = target;
      helper(candidates, 0);
      return ans;
   }
};






// COMBINATION SUM 2
// https://leetcode.com/problems/combination-sum-ii/description/

class Solution {
private:
   vector<vector<int>> ans;
   vector<int> curr;
   vector<int> nums;
   int target;
   int currSum;
   int n;

   void helper(int i) {
      if(currSum == target) {
         ans.push_back(curr);
         return;
      }
      else if(currSum > target || i >= n) return;

      // case 1 : we will take nums[i] in curr
      // NOTE IMP : always think of recursion in the CN way only : I will handle this small part and trust recursion to do the job for the other part
      curr.push_back(nums[i]);
      currSum += nums[i];
      helper(i+1);
      currSum -= nums[i];
      curr.pop_back();

      // case 2 : not take nums[i]...so we will not take all elems ahead which are equal to nums[i] to avoid duplicates
      int j = i+1;
      while(j < n && nums[j] == nums[i]) j++;
      helper(j);
   }

public:
   vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
      sort(candidates.begin(), candidates.end());
      ans.clear();
      curr.clear();
      nums = candidates;
      this->target = target;
      currSum = 0;
      n = candidates.size();

      helper(0);

      return ans;
   }
};