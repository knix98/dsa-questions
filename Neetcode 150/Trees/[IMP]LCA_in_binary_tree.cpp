/*
https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/description/
*/


// CODE 1
class Solution {
public:
   TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
      if(!root || p == root || q == root) return root;

      // in this approach always calls would be made to both the subtrees, even if both the nodes were found in left-subtree itself, 
      // and hence there was no need to call recursion on right-subtree
      TreeNode *l = lowestCommonAncestor(root->left, p, q);
      TreeNode *r = lowestCommonAncestor(root->right, p, q);

      if(!l || !r) return l ? l : r;   // if one of them is null, return the not null one

      return root;  // if both of them are not null, means p and q were found on either sides of the root, so root is the LCA
   }
};



// CODE 2 : optimising a bit by not calling recursion on right-subtree if both the p and q are found in left-subtree itself
struct smallAns {
   bool pFound;
   bool qFound;
   smallAns() : pFound(false), qFound(false) {}
};
 
class Solution {
private:
   TreeNode *lca, *p, *q;

   smallAns solve(TreeNode* root) {
      smallAns sa;
      if(!root) return sa;

      if(root == p) sa.pFound = true;
      if(root == q) sa.qFound = true;

      smallAns leftAns = solve(root->left);
      if(lca) return sa;
      sa.pFound = sa.pFound || leftAns.pFound;
      sa.qFound = sa.qFound || leftAns.qFound;
      if(sa.pFound && sa.qFound) {
        lca = root; 
        return sa;
      }

      smallAns rightAns = solve(root->right);
      if(lca) return sa;
      sa.pFound = sa.pFound || rightAns.pFound;
      sa.qFound = sa.qFound || rightAns.qFound;
      if(sa.pFound && sa.qFound) {
        lca = root; 
        return sa;
      }

      return sa;
   }
 
public:
   TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
      lca = NULL;
      this->p = p;
      this->q = q;

      solve(root);

      return lca;
   }
};