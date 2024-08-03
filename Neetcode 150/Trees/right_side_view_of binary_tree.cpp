/*
https://leetcode.com/problems/binary-tree-right-side-view/
*/


/*
here we cant do an approach like moving only to the right most nodes because some node might be present in left subtree also
for example :     1
                 / \
                2   3
               /    
              4        => ans = 1,3,4
*/
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) { 
        vector<int> ans;
        if(root == NULL) return ans;

        queue<TreeNode*> pending;
        pending.push(root);
        pending.push(NULL);

        while(!pending.empty()){
            ans.push_back(pending.front()->val);
            
            while(pending.front()){
                TreeNode* front = pending.front();
                pending.pop();
                if(front->right) pending.push(front->right);
                if(front->left) pending.push(front->left);
            }
            pending.pop(); // NULL popped 

            if(!pending.empty()) pending.push(NULL);
        }

        return ans;
    }
};