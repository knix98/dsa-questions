/*
Given a binary tree with N number of nodes, check if that input tree is BST (Binary Search Tree). 
If yes, return true, return false otherwise.
Note: Duplicate elements should be kept in the right subtree.
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


//FIRST APPROACH..........................................................................................
//Notes about both the approaches written in first time notes
#include<climits>
bool isBST(BinaryTreeNode<int> *root, int min, int max){
    if(root == NULL) return true;
    
    if(root->data >= min && root->data <= max){
        return (isBST(root->right, root->data, max) && isBST(root->left, min, root->data - 1));
    }
    else{
        return false;
    }
}

bool isBST(BinaryTreeNode<int> *root) {
	return isBST(root, INT_MIN, INT_MAX);
}



//SECOND APPROACH.........................................................................................
#include<algorithm>
class IsBSTreturn{
    public:
    int max; //to store the maximum value in the tree passed as function argument
    int min; //to store the minimum value in the tree passed as function argument
    bool isBST; //to store whether given tree is BST or not
};
    
IsBSTreturn isBST2(BinaryTreeNode<int> *root){
    if(root==NULL){
        IsBSTreturn output;
        output.isBST = true;
        output.min = INT_MAX; //because we would need min of right tree and root->data < righttree.min
        					  //so for NULL tree min=INT_MAX so that any root-data < INT_MAX
        output.max = INT_MIN; //similar logic : max would be needed from left tree and root->data > lefttree.min
        
        return output;
    }
    
    IsBSTreturn lefttree = isBST2(root->left);
    IsBSTreturn righttree = isBST2(root->right);
    
    int minimum = min({root->data, lefttree.min, righttree.min});
    int maximum = max({root->data, lefttree.max, righttree.max});
    bool isBSTfinal = root->data <=righttree.min && root->data > lefttree.max && righttree.isBST && lefttree.isBST;
    
    IsBSTreturn output;
    output.min = minimum;
    output.max = maximum;
    output.isBST = isBSTfinal;
    return output;
}


bool isBST(BinaryTreeNode<int> *root) {
	// Write your code here
    if(root == NULL){
        return true;
    }
    
    return isBST2(root).isBST;
}