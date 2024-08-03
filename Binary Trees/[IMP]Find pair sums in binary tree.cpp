/*
Given a binary tree and an integer S, print all the pair of nodes whose sum equals S.
Note:
1. Assume the given binary tree contains all unique elements.
2. In a pair, print the smaller element first. Order of different pairs doesn't matter.
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

#include<algorithm>
#include<vector>
void fillArray(BinaryTreeNode<int> *root, vector<int> &v){
    if(root == NULL) return;
    
    fillArray(root->left, v);
    v.push_back(root->data);
    fillArray(root->right, v);
}

void pairSum(BinaryTreeNode<int> *root, int sum) {
	vector<int> v;
    fillArray(root, v);
    sort(v.begin(), v.end());
    
    int i=0, j = v.size() - 1;
    
    while(i<j){
        int x = v[i] + v[j];
        
        if(x == sum){
            cout << v[i] << " " << v[j] << endl;
            i++; j--;
        }
        else if(x < sum) i++;
        else if(x > sum) j--;
    }
}