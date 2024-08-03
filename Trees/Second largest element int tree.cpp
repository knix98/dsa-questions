/*
Given a generic tree, find and return the node with second largest value in given tree.
Note: Return NULL if no node with required value is present.
*/



/*
Approach 1: create a pair class having data members as TreeNode<int>* pointers for largest and second largest node.
And create a helper function which returns this pair from any tree passed to it in argument.
Time: O(n), n = no. of nodes in the tree
Space: O(h), h = height of tree, since max recursion calls wud go till no. of nodes present in one height of a tree

Approach 2: Use a queue to store and check each TreeNodes for largest and second largest elements 
Time: O(n) 
Space: O(n) (worst case obviously)

Second approach is coded below
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

TreeNode<int>* getSecondLargestNode(TreeNode<int>* root) {
    if(root == NULL){
        return NULL;
    }
    
    TreeNode<int> *lar = root; //pointer for storing address of node containing largest int data
    TreeNode<int> *seclar = NULL; // for second largest
    
    queue<TreeNode<int>*> nodes;
    nodes.push(root);
    
    while(!nodes.empty()){
        TreeNode<int> *front = nodes.front();
        nodes.pop();
        
        if(front->data > lar->data){
            seclar = lar;
            lar = front;
        }
        else if(front->data < lar->data){
            if(seclar != NULL && seclar->data < front->data){
                seclar = front;
            }
            else if(seclar == NULL){
                seclar = front;
            }
        }
        
        for(int i=0; i<front->children.size(); i++){
            nodes.push(front->children[i]);
        }
    }
    
    return seclar;
}