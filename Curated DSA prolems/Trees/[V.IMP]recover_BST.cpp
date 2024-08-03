/*
https://leetcode.com/problems/recover-binary-search-tree/description/
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */




/*
APPROACH : we will use inorder traversal over BST because we know, that should come out to be ascending order
CASE 1 : when distant elements swapped 
        1 2 7 4 5 6 3 8 => in this case 3 and 7 have been swapped. So while doing inorder we find 4 < 7 => so 7 is 1st defect node
        and then later we find 3 < 6 => so 3 is 2nd defective node

CASE 2 : when neighbour elements swapped
        1 2 4 3 5 6 7 8 => in this case 3 and 4 have been swapped. So while doing inorder we find 3 < 4 => so 4 is 1st defect node
        and then later we dont find any other discrepancy in the ascending order. So 2nd defect node = 3 itself
*/
class Solution {
public:
    // this func takes lastNode in inorder as input
    void findDefectNodes(TreeNode* node, TreeNode* &lastNode, TreeNode* &firstDefNode, TreeNode* &secondDefNode){
        if(!node) return;

        findDefectNodes(node->left, lastNode, firstDefNode, secondDefNode);

        if(lastNode){
            if(node->val < lastNode->val) {
                if(!firstDefNode) firstDefNode = lastNode;
                secondDefNode = node;
            }
        }

        lastNode = node;
        findDefectNodes(node->right, lastNode, firstDefNode, secondDefNode);
    }

    void recoverTree(TreeNode* root) {
        TreeNode *firstDefNode = NULL, *secondDefNode = NULL, *lastNode = NULL;  // since lastNode to root is nothing/NULL
        findDefectNodes(root, lastNode, firstDefNode, secondDefNode);
        
        int temp = firstDefNode->val;
        firstDefNode->val = secondDefNode->val;
        secondDefNode->val = temp;
    }
};