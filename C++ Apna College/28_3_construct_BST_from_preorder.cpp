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

TreeNode* bstFromPreorder(vector<int>& preorder) {
    vector<vector<int>> range;
    vector<TreeNode*> nodes(preorder.size());

    TreeNode* root = new TreeNode(preorder[0]);
    vector<int> rootRange{ INT_MIN, preorder[0], preorder[0], INT_MAX };
    range.push_back(rootRange);
    nodes[0] = root;

    for(int i=1; i<preorder.size(); i++){
        int cur = preorder[i];
        int j = i-1;
        while(j >= 0){
            if(cur > range[j][2] && cur < range[j][3]){
                TreeNode* node = new TreeNode(cur);
                vector<int> nodeRange{ range[j][2], cur, cur, range[j][3] };
                range.push_back(nodeRange);
                nodes[i] = node;

                nodes[j]->right = node;
                break;
            }
            else if(cur > range[j][0] && cur < range[j][1]){
                TreeNode* node = new TreeNode(cur);
                vector<int> nodeRange{ range[j][0], cur, cur, range[j][1] };
                range.push_back(nodeRange);
                nodes[i] = node;

                nodes[j]->left = node;
                break;
            }

            j--;
        }
    }     

    return root; 
}