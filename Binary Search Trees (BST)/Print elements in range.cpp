/*
Given a Binary Search Tree and two integers k1 and k2, find and print the elements which are in range k1 and k2 (both inclusive).
Print the elements in increasing order.
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

// Obvious solution...
void elementsInRangeK1K2(BinaryTreeNode<int> *root, int k1, int k2)
{
    if (root == NULL)
    {
        return;
    }

    elementsInRangeK1K2(root->left, k1, k2);
    if (root->data >= k1 && root->data <= k2)
    {
        cout << root->data << " ";
    }
    elementsInRangeK1K2(root->right, k1, k2);
}

// A bit optimised solution...
void elementsInRangeK1K2(BinaryTreeNode<int> *root, int k1, int k2)
{
    // Write your code here
    if (root == NULL)
    {
        return;
    }

    int x = root->data;

    if (x >= k1 && x <= k2)
    { // if x lies in range then make calls on both the child trees
        elementsInRangeK1K2(root->left, k1, k2);
        cout << x << " ";
        elementsInRangeK1K2(root->right, k1, k2);
    }
    else if (x < k1)
    { // no possible solutions in left sub tree in this case
        elementsInRangeK1K2(root->right, k1, k2);
    }
    else if (x > k2)
    { // no possible solutions in right sub tree in this case
        elementsInRangeK1K2(root->left, k1, k2);
    }
}
