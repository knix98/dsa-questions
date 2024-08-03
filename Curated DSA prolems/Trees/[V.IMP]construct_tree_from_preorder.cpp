/*
https://classroom.codingninjas.com/app/classroom/me/11692/content/204438/offering/2653309/problem/14192?leftPanelTabValue=PROBLEM
*/




/*************************************************************
 
    Following is the Binary Tree node structure

    class BinaryTreeNode 
    {
    public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/

// intuition : preorder travel is same as the order in which nodes are visited in dfs traversal. So we will apply dfs.

// this func would get i which signifies the current node which needs to be created and then create the subtrees within it and 
// return the created root. Also this func should make sure that, upon return, i has been already updated to the next node that needs to
// be created
BinaryTreeNode<int>* dfs(int &i, vector<int> &pre, vector<int> &isLeaf){
    if(i >= pre.size()) return NULL;

    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(pre[i]);  // first make the current root node

    if(isLeaf[i]) {
        i++;  // update the global index over pre array
        return root;
    }

    // if current node is !isLeaf[i], then according to question this node should have both the leaf and right subtrees
    root->left = dfs(++i, pre, isLeaf);  // update the i and pass it to left subtree
    root->right = dfs(i, pre, isLeaf);  // after left's dfs, i would have been already updated, so just pass it to right dfs

    return root;  // after right's dfs, i would have been already updated, so no need to do anything to i
}

BinaryTreeNode<int> *constructTree(vector<int> &pre, vector<int> &isLeaf) {
    int i = 0;  // first we need to create first node
    return dfs(i, pre, isLeaf);
}