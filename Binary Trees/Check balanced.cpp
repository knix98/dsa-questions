/*
Given a binary tree, check if it is balanced. Return true if given binary tree is balanced, false otherwise.
Balanced Binary Tree:
A empty binary tree or binary tree with zero nodes is always balanced. For a non empty binary tree to be balanced, 
following conditions must be met:
1. The left and right subtrees must be balanced.
2. |hL - hR| <= 1, where hL is the height or depth of left subtree and hR is the height or depth of right subtree.    
*/

#include <iostream>
#include <queue>
using namespace std;

template <typename T>
class BinaryTreeNode{
    public:
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data)
        {
            this->data = data;
            left = NULL;
            right = NULL;
        }

        ~BinaryTreeNode()
        {
            delete left; 
            delete right;
        }
};

//SOLUTION..............................................................................................................

//helper function will return a pair in which first wud be whether tree is balanced?
//second wud be the height of tree
pair<bool, int> helper(BinaryTreeNode<int> *root){
    if(root == NULL){
        pair<bool, int> p(true, 0);
        return p;
    }
    
    pair<bool, int> left = helper(root->left);
    pair<bool, int> right = helper(root->right);
    
    pair<bool, int> ans;
    if(!left.first || !right.first || abs(left.second - right.second) > 1){
        ans.first = false;
    }
    else{
        ans.first = true;
    }
    
    ans.second = 1 + max(left.second, right.second);
    
    return ans;
}

bool isBalanced(BinaryTreeNode<int> *root) {
	return helper(root).first;
}