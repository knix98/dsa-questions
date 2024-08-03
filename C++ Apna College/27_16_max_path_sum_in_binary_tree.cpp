int maxSumThruRoot(TreeNode* root, int &ans) {
    if(root == NULL) return INT_MIN;

    int leftAns = maxSumThruRoot(root->left, ans);
    int rightAns = maxSumThruRoot(root->right, ans);

    int rootData = root->val;
    int a = rootData + leftAns;
    int b = rootData + rightAns;
    int c = rootData;
    int d = rootData + rightAns + leftAns;

    int returnAns = max({a, b, c});
    int treeAns = max(returnAns, d);

    ans = treeAns > ans ? treeAns : ans;

    return returnAns;
}

int maxPathSum(TreeNode* root) {
    int ans = INT_MIN;
    maxSumThruRoot(root, ans);
    return ans;
}