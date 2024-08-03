/*
Print all the nodes at k level in the tree. Assume that root is at level 0.

Sample Input 1: for k = 2,
         10
  20     30     40
40  50

Sample Output 1:
40 50
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

template<typename T>
void printAtLevelK(TreeNode<T> *root, int k){
    if(root == NULL){  //Edge case
        return;
    }

    if(k == 0){  //Base case
        cout << root->data << " ";
        return;
    }

    for(int i=0; i<root->children.size(); i++){
        printAtLevelK(root->children[i], k-1);
    }
}