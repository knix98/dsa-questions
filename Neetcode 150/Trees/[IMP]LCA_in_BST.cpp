/*
https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/description/
*/


class Solution {
public:
   TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    //   if(!root) return NULL;  
    // this base case is not needed to be handelled because, when we are calling 
    // recursion on a subtree, we are 100% sure that both the nodes would be definitely found in that
    // subtree (because of BST)

      if(p->val < root->val && q->val < root->val) return lowestCommonAncestor(root->left, p, q);
      else if(p->val > root->val && q->val > root->val) return lowestCommonAncestor(root->right, p, q);
      else return root;
   }
};