/*
Given a BST and an integer k. Find and return the path from the node with data k and root 
(if a node with data k is present in given BST) in a list. Return empty list otherwise.
Note: Assume that BST contains all unique elements.

Sample Input 1:
8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
2
Sample Output 1:
2 5 8
*/

#include <iostream>
#include<vector>
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

vector<int>* getPath(BinaryTreeNode<int> *root , int data) {
	// Write your code here
    if(root == NULL){
        return NULL;
    }
    
    if(root->data == data){
        vector<int>* output = new vector<int>();
        output->push_back(root->data);
        return output;
    }
    
    vector<int>* output;
    if(data > root->data){
        output = getPath(root->right, data);
    }
    else{
        output = getPath(root->left, data);
    }
    
    if(output != NULL){
        output->push_back(root->data);
        return output;
    }
    else{
        return NULL;
    }
}