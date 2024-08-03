/*
Given a sorted integer array A of size n, which contains all unique elements. You need to construct a 
balanced BST from this input array. Return the root of constructed BST.
Note: If array size is even, take first mid as root.
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

BinaryTreeNode<int>* constructTree(int *input, int si, int ei){
    if(si > ei){
        return NULL;
    }
    
    int rootindex = (si+ei)/2;
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(input[rootindex]);
    root->left = constructTree(input, si, rootindex-1);
    root->right = constructTree(input, rootindex+1, ei);
    return root;
}


BinaryTreeNode<int>* constructTree(int *input, int n) {
	// Write your code here
    return constructTree(input, 0, n-1);
}