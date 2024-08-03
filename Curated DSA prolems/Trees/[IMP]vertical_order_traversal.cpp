/*
https://classroom.codingninjas.com/app/classroom/me/11692/content/204438/offering/2653309/problem/14193?leftPanelTabValue=PROBLEM
*/



// this func would do bfs and store all the node's deviations w.r.t root, whose deviation is 0
vector<int> verticalOrderTraversal(TreeNode<int> *root)
{
    int minRange = 0, maxRange = 0;  // minm and maxm deviation values amongst all nodes

    queue<pair<TreeNode<int>*, int>> bfs1;   // <node-pointer, node-deviation>
    queue<pair<TreeNode<int>*, int>> bfs2;   // bfs2 needed after another traversal in future, after we have determined the min/maxRange values in 1st traversal
                                            // and we cant push again in bfs1 only, as it will cause nodes to repeat in bfs order
    bfs1.push({root, 0});

    while(!bfs1.empty()){
        TreeNode<int> *front = bfs1.front().first;
        int frontLevel = bfs1.front().second;
        bfs1.pop();

        if(frontLevel < minRange) minRange = frontLevel;
        if(frontLevel > maxRange) maxRange = frontLevel;

        if(front->left != NULL) bfs1.push({front->left, frontLevel-1});
        if(front->right != NULL) bfs1.push({front->right, frontLevel+1});

        bfs2.push({front, frontLevel});
    }

    vector<vector<int>> order(maxRange - minRange + 1);  // will store the nodes present at each deviation value in this
    while(!bfs2.empty()){
        TreeNode<int> *front = bfs2.front().first;
        int frontLevel = bfs2.front().second;
        bfs2.pop();

        order[frontLevel - minRange].push_back(front->data);  // since minRange can be -ve, so we need to shift the deviation values
    }

    vector<int> ans;
    for(auto v : order){
        for(int i : v) ans.push_back(i);
    }

    return ans;
}