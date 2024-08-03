/*
Given a binary tree and data of two nodes, find 'LCA' (Lowest Common Ancestor) of the given two nodes in the binary tree.
LCA of two nodes A and B is the lowest or deepest node which has both A and B as its descendants.

Note:
1. If out of 2 nodes only one node is present, return that node.
2. If both are not present, return -1.

Example:
      10
  20     30
40  50      60

LCA of 40 & 50 is 20,
LCA of 40 & 60 is 10,
LCA of 30 & 60 is 30
*/

#include <iostream>
#include <stack>
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

// Approach 1: Using pure recursion (best approach)
// Time: O(n), Space : O(h)
int getLCA(BinaryTreeNode<int> *root, int a, int b)
{
    // Write your code here
    if (root == NULL)
    {
        return -1;
    }

    if (root->data == a || root->data == b)
    {                      // if we find a or b at root only then, whether we find a or b down the tree or not,
        return root->data; // our final LCA would be root->data only
    }
    else
    {
        int leftAns = getLCA(root->left, a, b);
        if (leftAns == a || leftAns == b)
        {
            int rightAns = getLCA(root->right, a, b);
            if (rightAns == a || rightAns == b)
            {                      // this case means that one of a and b is present in left and the other
                return root->data; // is present in right....so common  LCA would be root only.
            }
            else if (rightAns == -1)
            {
                return leftAns;
            }
        }
        else if (leftAns == -1)
        {
            return getLCA(root->right, a, b);
        }
        else
        { // if leftAns != a or b or -1, that means we found some LCA in left tree only, so return that itself
            return leftAns;
        }
    }
}

// Approach 2: using a stack to get the paths of both and then compare

// this function wud return true/false whether int a was found or not
// and also fill the stack passed to it with the path from root to a if a is found
bool path(BinaryTreeNode<int> *root, int a, stack<int> &s)
{
    if (root == NULL)
    {
        return false;
    }

    s.push(a);
    if (root->data == a)
    {
        return true;
    }

    if (path(root->left, a, s) || path(root->right, a, s))
    {
        return true;
    }

    s.pop();
    return false;
}

int getLCA(BinaryTreeNode<int> *root, int a, int b)
{
    stack<int> pathA;
    stack<int> pathB;

    bool aFound = path(root, a, pathA);
    bool bFound = path(root, b, pathB);

    if (!aFound && !bFound)
    { // if both a and b not found
        return -1;
    }
    if (!aFound || !bFound)
    { // if 1 of them only not found, other found
        return (aFound ? a : b);
    }

    // if both of them found...
    stack<int> &bigger = (pathA.size() > pathB.size() ? pathA : pathB);

    // if a and b are present at different levels in the tree then, remove the extra nodes from the bigger path
    while (pathA.size() != pathB.size())
    {
        bigger.pop();
    }

    // now since same number of levels are present in both the paths, so compare each level in both the paths
    // and see at which level the node->data is same for both the paths....that would be the LCA
    while (pathA.top() != pathB.top())
    {
        pathA.pop();
        pathB.pop();
    }

    return pathA.top();
}
