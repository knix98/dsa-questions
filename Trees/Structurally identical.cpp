/*
Given two generic trees, return true if they are structurally identical. Otherwise return false.

Structural Identical :-
If the two given trees are made of nodes with the same values and the nodes are arranged in the same way, 
then the trees are called identical.  
*/

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

template <typename T>
class TreeNode{
    public:
    T data;
    vector<TreeNode<T>*> children;

    TreeNode(T data){
        this->data = data;
    }
};

bool areIdentical(TreeNode<int> *root1, TreeNode<int> * root2) {
    // Write your code here
    if(root1 == NULL && root2 == NULL){ //if both roots are NULL
        return true;
    }
    else if(root1 == NULL || root2 == NULL){ //if only one of them is NULL
        return false;
    }
    
    if(root1->data == root2->data){
        if(root1->children.size() == root2->children.size()){ // if root->data and root's number of children is
            for(int i=0; i<root1->children.size(); i++){	  //same for both the roots then call recursion on each children
                if(areIdentical(root1->children[i], root2->children[i])){
                    continue; 
                }
                else{
                    return false; //if even one child tree is not identical for both the roots return false
                }
            }
        }
        else{
            return false;
        }
    }
    else{
        return false;
    }
    
    return true;
}