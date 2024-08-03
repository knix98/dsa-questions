/*
Given a binary search tree and data of two nodes, find 'LCA' (Lowest Common Ancestor) of the given two nodes in the BST.
LCA of two nodes A and B is the lowest or deepest node which has both A and B as its descendants. 

Note:
1. If out of 2 nodes only one node is present, return that node. 
2. If both are not present, return -1.
3. all the node data will be unique.

Example:
      40
  20     50
10  30      60

LCA of 40 & 50 is 40,
LCA of 10 & 30 is 20,
LCA of 30 & 60 is 40
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

//Time : O(h), since at every node we are determining whether val1 and val2 are greater and smaller than root->data and then going the correct way only
             //first we are going and finding the smaller of val1 and val2 and than backtracking and then finding the bigger val.
             //So overall we are not going to every node of tree
//Space : O(h), because of the O(h) recursive calls  

int getLCA(BinaryTreeNode<int>* root , int val1 , int val2){
	if(root == NULL) return -1;
    
    if(root->data == val1 || root->data == val2) return root->data;
    
    int x = root->data;
    if(val1 < x && val2 < x){
        return getLCA(root->left, val1, val2);
    }
    else if(val1 > x && val2 > x){
        return getLCA(root->right, val1, val2);
    }
    else{ //means the val1 and val2 are on either side of root->data
        int leftLCA = getLCA(root->left, val1, val2);
        int rightLCA = getLCA(root->right, val1, val2);
        
        if(leftLCA == -1 && rightLCA == -1) return -1;
        else if(leftLCA == -1) return rightLCA;
        else if(rightLCA == -1) return leftLCA;
        else return root->data;
    }
}