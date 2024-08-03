/*
https://classroom.codingninjas.com/app/classroom/me/11692/content/204438/offering/2653309/problem/14173?leftPanelTabValue=PROBLEM
*/


// NOTE : this code might not pass in CN platform , but this is correct code
vector<vector<int>> diagonal(TreeNode<int>* root){
    queue<TreeNode<int>*> curr, next;  // "curr" would contain nodes in current diagonal level and in "next" we would keep on pushing
    curr.push(root);                   // nodes for the next diagonal level

    vector<vector<int>> ans;
    vector<int> levelNodes;   // will contain nodes in curr diagonal level
    while(!curr.empty()){
        TreeNode<int>* front = curr.front();
        curr.pop();

        levelNodes.push_back(front->data);

        if(front->left) next.push(front->left);

        if(front->right) curr.push(front->right);

        if(curr.empty()){
            // this curr level is finished
            ans.push_back(levelNodes);
            levelNodes.clear();  // clear it for next diagonal iteration

            // curr = next;
            // next.clear();
            while(!next.empty()){   // populate curr with next nodes
                curr.push(next.front());
                next.pop();
            }
        }
    }

    return ans;
}