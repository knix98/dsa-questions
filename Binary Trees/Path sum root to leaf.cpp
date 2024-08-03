/*
For a given Binary Tree of type integer and a number K, print out all root-to-leaf paths where the sum of 
all the node data along the path is equal to K.

Example:
         2
       /   \
     3       9
    / \       \ 
   4   8       2
  /           /
 4           6

If you see in the above-depicted picture of Binary Tree, we see that there are a total of two paths, 
starting from the root and ending at the leaves which sum up to a value of K = 13.

The paths are:
a. 2 3 4 4
b. 2 3 8

One thing to note here is, there is another path in the right sub-tree in reference to the root, 
which sums up to 13 but since it doesn't end at the leaf, we discard it.
The path is: 2 9 2(not a leaf)

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


//Time : O(n),  Space : O(h), since O(h) recursion calls & O(h) number of nodes stored at max at any time in the vector
#include<vector>
void helper(BinaryTreeNode<int> *root, int k, vector<int> &v){
    if(root == NULL) return;
    
    if(root->left == NULL && root->right == NULL){
        if(k - root->data == 0){
            for(int i=0; i<v.size(); i++){
                cout << v[i] << " ";
            }
            cout << root->data << endl;
        }
    }
    else{ //if root is not leaf node, then push root->data in vector and proceed further in the tree
        v.push_back(root->data);
        helper(root->left, k-root->data, v);
        helper(root->right, k-root->data, v);
        v.pop_back(); //root->data removed from vector and return
    }
}

void rootToLeafPathsSumToK(BinaryTreeNode<int> *root, int k) {
	vector<int> v;
    helper(root, k, v);
}