/*
https://classroom.codingninjas.com/app/classroom/me/11692/content/204438/offering/2653309/problem/14215?leftPanelTabValue=PROBLEM
*/



void bfs(TreeNode<int> *root, vector<int> &ans) {
    queue<pair<TreeNode<int>*, int>> pending;  //  we will not push root in this, as root node is not required in ans vector
    if(root->left) pending.push({root->left, -1});
    if(root->right) pending.push({root->right, 1});

    while(!pending.empty()){
        TreeNode<int> *front = pending.front().first;
        int deviation = pending.front().second;
        pending.pop();

        if(deviation == 0) ans.push_back(front->data);
        if(front->left) pending.push({front->left, deviation-1});
        if(front->right) pending.push({front->right, deviation+1});
    }
}

vector<int> verticallyBelowNodes(TreeNode<int> *root) {
    vector<int> ans;
    bfs(root, ans);
    if(ans.size() == 0) ans.push_back(-1);
    return ans;
}