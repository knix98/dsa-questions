/*
https://leetcode.com/problems/subtree-of-another-tree/description/
*/


/*
    Given the roots of 2 binary trees, return true if a tree has a subtree of the other tree

    Check at each node of the root tree if it's the same as the subRoot tree (structure + values)

    Time: O(m x n)
    Space: O(m)
*/
class Solution {
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (root == NULL) {
            return false;
        }
        if (isSame(root, subRoot)) {
            return true;
        }
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
private:
    bool isSame(TreeNode* root, TreeNode* subRoot) {
        if (root == NULL && subRoot == NULL) {
            return true;
        }
        if (root == NULL || subRoot == NULL) {
            return false;
        }
        if (root->val != subRoot->val) {
            return false;
        }
        return isSame(root->left, subRoot->left) && isSame(root->right, subRoot->right);
    }
};