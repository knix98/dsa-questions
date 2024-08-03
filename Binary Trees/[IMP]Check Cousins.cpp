/*
Given the binary Tree and two nodes say ‘p’ and ‘q’. Determine whether the two nodes are cousins of each other or not.
Two nodes are said to be cousins of each other if they are at same level of the Binary Tree and have different parents.
Do it in O(n).
*/

#include <iostream>
using namespace std;

template <typename T>
class BinaryTreeNode
{
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

// SOLUTION...............................................................................................................................
// this helper function fills the pair given to it with p's parent node and p's depth if p is found and returns true, otherwise returns false if p is not found
bool helper(BinaryTreeNode<int> *root, int p, pair<BinaryTreeNode<int> *, int> &ans)
{
    // no need to check root->data, since it wud have been checked earlier in the main function, or previous recursive calls
    if ((root->left && root->left->data == p) || (root->right && root->right->data == p))
    {
        ans.first = root;
        ans.second = 1;
        return true;
    }

    if ((root->left && helper(root->left, p, ans)) || (root->right && helper(root->right, p, ans)))
    {
        ans.second++; // increment the depth
        return true;
    }

    return false;
}

bool isCousin(BinaryTreeNode<int> *root, int p, int q)
{
    // if 1 of p or q is at top then it can't be anybody's cousin
    if (root == NULL || root->data == p || root->data == q)
    {
        return false;
    }

    // pans is a pair in which first is a pointer to the parent node of the 'int p' node
    // second is the depth value of 'int p' node from root
    pair<BinaryTreeNode<int> *, int> pans;
    if (!helper(root, p, pans))
    {
        return false;
    }

    pair<BinaryTreeNode<int> *, int> qans;
    if (!helper(root, q, qans))
    {
        return false;
    }

    if (pans.first == qans.first || pans.second != qans.second)
    {
        return false;
    }

    return true;
}