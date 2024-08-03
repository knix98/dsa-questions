/*
Given a generic tree, find and return the height of given tree.

Sample Input 1:
         10
  20     30     40
40  50

Sample Output 1:
3
*/

#include <iostream>
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

int getHeight(TreeNode<int>* root) {
    // Write your code here
    if(root == NULL){
        return 0;
    }
    
    int maxSmallHeight = 0;
    
    for(int i=0; i<root->children.size(); i++){
        int smallHeight = getHeight(root->children[i]);
        if(smallHeight > maxSmallHeight){
            maxSmallHeight = smallHeight;
        }
    }
    
    return 1 + maxSmallHeight;
}