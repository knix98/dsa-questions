/*
Given a binary search tree, you have to replace each node's data with the sum of all nodes which are greater or equal than it. 
You need to include the current node's data also.
That is, if in given BST there is a node with data 5, you need to replace it with sum of its data (i.e. 5) and 
all nodes whose data is greater than or equal to 5.
Note: You don't need to return or print, just change the data of each node.
*/

#include <iostream>
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

//Since we have to replace every node with sum of greater nodes, it makes sense to go in reverse inorder fashion
//that is, right->root->left
//In this beautiful approach, we will use recursion and assume that our function rightfully replaces every node of the tree
//with sum of greater nodes and also the function returns us the sum of all the nodes in it. 
//The function wud require 2 arguments - 1.the root of tree on which it needs to work, 2.the extra sum which needs
//to be added to all the nodes in that tree, because this extra sum is the sum of all the nodes which are greater than
//all the nodes in the given tree(basically extra contains the sum of all the nodes which are present in the upper right side of the tree)
int replaceWithLargerNodesSumHelper(BinaryTreeNode<int> *root, int extra){
    if(root == NULL){
        return 0;
    }
    
    int rightSum = replaceWithLargerNodesSumHelper(root->right, extra);//first get the right sum(which contains all nodes greater than the root)
    int oldData = root->data;
    root->data = rightSum + oldData + extra;//now root->data contains the sum of all the nodes which are greater than the root's left subtree nodes
    int leftSum = replaceWithLargerNodesSumHelper(root->left, root->data);//so send root->data as extra for left subtree
    return oldData + leftSum + rightSum;
}

void replaceWithLargerNodesSum(BinaryTreeNode<int> *root) {
    // Write your code here
    int ans = replaceWithLargerNodesSumHelper(root, 0); //extra for root will be zero(because no nodes in root's upper right side)
}