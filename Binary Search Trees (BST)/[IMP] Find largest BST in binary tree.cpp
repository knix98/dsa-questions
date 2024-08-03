/*
    Given a Binary tree, find the largest BST subtree. That is, you need to find the BST with maximum height in the given binary tree. 
    You have to return the height of largest BST.
    Note :
    The binary tree will be consisting of only unique elements.
*/

#include<algorithm>
#include<climits>

class answer{
	public:
	bool isBST;
	int min;
	int max;
	int height;

	answer(bool a, int b, int c, int d){
		isBST = a; // is current tree BST
		min = b; // current tree's min value
		max = c; // current tree's max value
		height = d; // current tree's height
	}
};

answer helper(BinaryTreeNode<int> *root, int &ans){
	if(root == NULL){
		answer returnAns(true, INT_MAX, INT_MIN, 0);
		return returnAns;
	}

	answer leftAns = helper(root->left, ans);	
	answer rightAns = helper(root->right, ans);

	int ansMin = min({leftAns.min, rightAns.min, root->data});	
	int ansMax = max({leftAns.max, rightAns.max, root->data});
	int ansHeight = max(leftAns.height, rightAns.height) + 1;

	if(leftAns.isBST && rightAns.isBST && leftAns.max < root->data && rightAns.min > root->data){
        // that means current tree is BST
        // so check if current tree's height is greater than the global ans variable
		if(ansHeight > ans){
			ans = ansHeight;
		}

        // return the answer for the current tree with isBST = true
		answer returnAns(true, ansMin, ansMax, ansHeight);
		return returnAns;
	}

    // else return isBSt = false
	answer returnAns(false, ansMin, ansMax, ansHeight);
	return returnAns;
}

int largestBSTSubtree(BinaryTreeNode<int> *root) {
	int ans = 0;
	helper(root, ans);
	return ans;
}