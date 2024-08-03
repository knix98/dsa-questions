/*
For a given Binary Tree of type integer, update it with its corresponding mirror image.

Input:
      1
  2       3
4   5   6   7

Output:
      1
  3       2
7   6   5   4
*/

#include <iostream>
#include <queue>
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

void mirrorBinaryTree(BinaryTreeNode<int> *root)
{
    // Write your code here
    if (root == NULL)
    {
        return;
    }

    BinaryTreeNode<int> *temp = root->left;
    root->left = root->right;
    root->right = temp;

    mirrorBinaryTree(root->left);
    mirrorBinaryTree(root->right);
}