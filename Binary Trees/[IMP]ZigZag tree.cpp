/*
Given a binary tree, print the zig zag order. In zigzag order, level 1 is printed from left to right, 
level 2 from right to left and so on. This means odd levels should get printed from left to right and even level right to left.
*/

#include <iostream>
#include <queue>
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

#include<stack>
void zigZagOrder(BinaryTreeNode<int> *root) {
    if(root == NULL){
        return;
    }
    
	stack<BinaryTreeNode<int>*> ltr;
    stack<BinaryTreeNode<int>*> rtl;
    
    ltr.push(root); //root is in the left to right line
    
    while(!rtl.empty() || !ltr.empty()){
        while(!ltr.empty()){ //first finish printing the nodes in the left to right line
            BinaryTreeNode<int>* top = ltr.top();
            ltr.pop();
            
            cout << top->data << " ";
            
            if(top->left) rtl.push(top->left);
            if(top->right) rtl.push(top->right);
        }
        
        cout << endl; //move to new line after all nodes in ltr line printed
        
        while(!rtl.empty()){ //now print all nodes in the rtl line
            BinaryTreeNode<int>* top = rtl.top();
            rtl.pop();
            
            cout << top->data << " ";
            
            if(top->right) ltr.push(top->right);
            if(top->left) ltr.push(top->left);
        }
        
        cout << endl; //move to new line after all nodes in the rtl line printed
    }
}