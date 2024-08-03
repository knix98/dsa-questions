/*
For a given a Binary Tree of type integer, find and return the minimum and the maximum data values.
Return the output as an object of Pair class, which is already created.
Note:
All the node data will be unique and hence there will always exist a minimum and maximum node data.

Constraints:
2 <= N <= 10^5
Where N is the total number of nodes in the binary tree.
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

/*
	The first value of the pair must be the minimum value in the tree and 
	the second value of the pair must be the maximum value in the tree
*/

//Time: O(n)
//Space: O(h)
#include<climits>
#include<algorithm>
pair<int, int> getMinAndMax(BinaryTreeNode<int> *root) {
    if(root == NULL){
        /*Since it's given that a unique min and a unique max wud always be there in the tree,
        so when root==NULL, we should put INT_MAX as min value so that this INT_MAX returned would be greater than any value in tree,
        so the actual min value in the whole tree would be able to replace this INT_MAX as min value easily.
        Similarly put INT_MIN in max value*/
        pair<int, int> p(INT_MAX, INT_MIN);
        return p;
    }
    
    pair<int, int> left = getMinAndMax(root->left);
    pair<int, int> right = getMinAndMax(root->right);
    
    pair<int, int> ans;
    ans.first = min({root->data, left.first, right.first}); //nice way to find max and min of multiple arguments using {}
    ans.second = max({root->data, left.second, right.second});
    
    return ans;
}