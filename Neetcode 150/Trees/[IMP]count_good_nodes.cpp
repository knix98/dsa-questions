/*
https://leetcode.com/problems/count-good-nodes-in-binary-tree/description/
*/


// like we did in the min-stack problem...we were storing min-value-till-now in the stack
// similarly we will preserve max-value-till-now in the recursion calls (recursion calls are similar to stack behaviour)
class Solution {
private:
   int ans;
   
   void solve(TreeNode* root, int maxTillNow) {
      if(!root) return;

      if(root->val >= maxTillNow) {
         ans++;
         maxTillNow = root->val;
      }

      solve(root->left, maxTillNow);
      solve(root->right, maxTillNow);
   }

public:
   int goodNodes(TreeNode* root) {
      ans = 0;
      solve(root, INT_MIN);
      return ans;
   }
};