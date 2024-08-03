/*
Given a binary search tree and an integer S, find pair of nodes in the BST which sum to S. 
You can use extra space of the order of O(log n).
Note:
1. Assume BST contains all unique elements.
2. In a pair, print the smaller element first.
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


//explanation for this beautiful approach written in 1st time BST notes
#include<stack>
void fillStack(BinaryTreeNode<int> *root, stack<BinaryTreeNode<int>*> &st, char c){
    if(root == NULL){
        return;
    }
    
    if(c == 'L'){
        while(root != NULL){
            st.push(root);
            root = root->left;
        }
    }
    else if(c == 'R'){
        while(root != NULL){
            st.push(root);
            root = root->right;
        }
    }
}

void printNodesSumToS(BinaryTreeNode<int> *root, int s) {
    // Write your code here
    if(root == NULL){
        return;
    }
    stack<BinaryTreeNode<int>*> small;
    stack<BinaryTreeNode<int>*> big;
    fillStack(root, small, 'L');
    fillStack(root, big, 'R');
    
    while(small.top()->data < big.top()->data){
        BinaryTreeNode<int>* smallTop = small.top();
        BinaryTreeNode<int>* bigTop = big.top();
        int sum = smallTop->data + bigTop->data;
        if(sum < s){
            small.pop();
            fillStack(smallTop->right, small, 'L');
        }
        else if(sum > s){
            big.pop();
            fillStack(bigTop->left, big, 'R');
        }
        else if(sum == s){
            cout << smallTop->data << " " << bigTop->data << endl;
            small.pop();
            fillStack(smallTop->right, small, 'L');
            big.pop();
            fillStack(bigTop->left, big, 'R');
        }
    }
}