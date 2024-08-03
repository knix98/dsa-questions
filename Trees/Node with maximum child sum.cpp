/*
Given a generic tree, find and return the node for which sum of its data and data of all its child nodes is maximum. 
In the sum, data of the node and data of its immediate child nodes has to be taken.
*/


//APPROACH 1:
/*
    One approach for this question would have been-> to make a pair class which contains
    a TreeNode and an int sum, and create a helper function whose return type would be this pair.
    And in this pair we would store the node which along with its children has the highest sum and in int sum 
    we would store the highest sum value. Then we would solve the problrm using recursion on tree, by comparing 
    the pair->sum returning from each recursion. If childAns->sum > ans->sum, then we would shallow copy the node address
    and sum value from childAns to ans
    Time : O(n), n=total nodes in trees
    Space: O(h), h=height of tree , (based on maximum no. of recursive calls at a given time)
*/


//APPROACH 2:  Use a queue to store and examine each nodes
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

TreeNode<int>* maxSumNode(TreeNode<int>* root) {
    // Write your code here
    queue<TreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    
    int max=0;
    TreeNode<int>* ansNode = NULL;
    while(!pendingNodes.empty()){
        TreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        int sum = front->data;
        for(int i=0; i<front->children.size(); i++){
            sum = sum + front->children[i]->data;
            pendingNodes.push(front->children[i]);
        }
        if(sum > max){
            max = sum;
            ansNode = front;
        }
    }
    
    return ansNode;
}


//Approach 3: Return the maximum sum node only and recalculate it's sum for comparing with the max sum
TreeNode<int>* maxSumNode(TreeNode<int>* root) {
    if(root == NULL){
        return NULL;
    }
    
    int maxSum = root->data;
    for(int i=0; i<root->children.size(); i++){
        maxSum += root->children[i]->data;
    }
    
    TreeNode<int> *ans = root; //this will store the final ans node
    
    for(int i=0; i<root->children.size(); i++){
        TreeNode<int> *childNode = maxSumNode(root->children[i]);
        
        int childSum = childNode->data; //calculate the sum of the childnode for comparing with maxSum
        for(int j=0; j<childNode->children.size(); j++){
            childSum += childNode->children[j]->data;
        }
        
        if(childSum > maxSum){
            maxSum = childSum;
            ans = childNode;
        }
    }
    
    return ans;
}