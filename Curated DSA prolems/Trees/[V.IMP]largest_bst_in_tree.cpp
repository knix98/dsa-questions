/*
https://classroom.codingninjas.com/app/classroom/me/11692/content/204439/offering/2653310/problem/14249?leftPanelTabValue=PROBLEM
*/


// IMP : in this problem, we cant use the top down approach in dfs, because every subtree can be independently a BST,
// but that subtree in combination with root node might not be a BST. So we have to evaluate each subtrees independently
// and hence use the bottom-up approach
struct isBST{
    bool isbst;
    int min, max, n;

    isBST(bool isbst, int min, int max, int n){
        this->isbst = isbst;
        this->min = min;
        this->max = max;
        this->n = n;
    }
};

isBST dfs(TreeNode<int> *node, int &ans){
    if(!node) {
        isBST b = isBST(true, INT_MAX, INT_MIN, 0);
        return b;
    }

    isBST leftAns = dfs(node->left, ans);
    isBST rightAns = dfs(node->right, ans);

    if(leftAns.isbst && rightAns.isbst){
        if(node->data > leftAns.max && node->data < rightAns.min){
            // this whole tree is a bst
            int currMin = min(leftAns.min, node->data);  // we have to do this comparison instead of simply assigning leftAns.min as currMin
                                                        // beacuse in case of leftAns coming from a NULL node, leftAns.min would be INT_MAX, which is
                                                        // obviously not the currMin
            int currMax = max(rightAns.max, node->data);
            int currN = leftAns.n + rightAns.n + 1;
            if(currN > ans) ans = currN; 
            isBST b = isBST(true, currMin, currMax, currN);
            return b;
        }
    }

    isBST b = isBST(false, 0, 0, 0);  // 0 means I am returning garbage, because they are insignificant
    return b;
}

int largestBST(TreeNode<int>* root) 
{
    int ans = 0;
    dfs(root, ans);
    return ans;
}