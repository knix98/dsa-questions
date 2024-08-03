/*
For a given preorder and inorder traversal of a Binary Tree of type integer stored in an array/list, 
create the binary tree using the given two arrays/lists. You just need to construct the tree and return the root.
Note:
Assume that the Binary Tree contains only unique elements. 
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
            delete left; // even if left or right is NULL, delete NULL wud not give an error
            delete right;
        }
};

BinaryTreeNode<int>* buildTree(int *preorder, int preLength, int *inorder, int inLength) {
    //preLength == inLength always
	if(preLength == 0){ //base case
        return NULL;
    }
    
    //first construct root node in heap memory
    //construct in heap memory because the tree should be present even after the program ends
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(preorder[0]);
    
    //find root->data in inorder
    int leftNodes = 0;
    while(inorder[leftNodes] != preorder[0]){ //after this loop, leftNodes wud contain the number of nodes in the left tree
        leftNodes++;
    }
    
    root->left = buildTree(preorder+1, leftNodes, inorder, leftNodes);
    root->right = buildTree(preorder+1+leftNodes, preLength-leftNodes-1, inorder+1+leftNodes, inLength-1-leftNodes);
    
    return root;
}