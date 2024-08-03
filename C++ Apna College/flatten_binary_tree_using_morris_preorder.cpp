/*
    Flatten a binary tree into a LL.
    Means right child of every node should be the next element in the flattend LL and left child of every node should be NULL.
    Using morris pre-order traversal, do this in O(n) time and O(1) space
*/  

#include <bits/stdc++.h>
using namespace std;

template <typename T>
class BinaryTreeNode {
   public:
    T data;
    BinaryTreeNode<T>* left;
    BinaryTreeNode<T>* right;

    BinaryTreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

BinaryTreeNode<int>* takeInput() {
    int rootData;

    cin >> rootData;
    if (rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while (!q.empty()) {
        BinaryTreeNode<int>* currentNode = q.front();
        q.pop();
        int leftChild, rightChild;

        cin >> leftChild;
        if (leftChild != -1) {
            BinaryTreeNode<int>* leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode->left = leftNode;
            q.push(leftNode);
        }

        cin >> rightChild;
        if (rightChild != -1) {
            BinaryTreeNode<int>* rightNode =
                new BinaryTreeNode<int>(rightChild);
            currentNode->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

void flatten(BinaryTreeNode<int>* root) {
    // O(n) time and O(1) space approach using morris preorder traversal
    BinaryTreeNode<int>* cur = root;

    while(cur){
        // considering cur as current root, we need to find the tail node of left sub-tree
        // so that we could attach head of right sub-tree (cur->right) to this leftTail
        BinaryTreeNode<int>* leftTail = cur->left;
        
        while(leftTail && leftTail->right){
            leftTail = leftTail->right;
        }

        if(leftTail){ // if leftTail != NULL
            // then attach left subtree, right subtree and cur in preorder fashion
            leftTail->right = cur->right;
            cur->right = cur->left;
        }

        // before moving to cur->right for next iteration, make cur->left as NULL
        cur->left = NULL;
        cur = cur->right;
    }
}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    flatten(root);

    // input tree (level-wise) => 1 2 7 3 4 -1 8 -1 -1 5 6 9 -1 -1 -1 -1 -1 -1 -1
    while(root){
        cout << root->data << " ";
        if(root->left) cout << "Wrong ";
        root = root->right;
    }

    return 0;
}


// Easier and more intuitive recursive approach : O(n) time and O(n) space complexity
/*
    // this func will make a preOrder LL from the root of the tree passed to it and return the tail node of the resultant LL
    TreeNode* helper(TreeNode* root){
        if(!root){
            return NULL;
        }

        TreeNode* leftAns = helper(root->left);
        TreeNode* rightAns = helper(root->right);

        TreeNode* tail = root;
        TreeNode* rootRight = root->right;
        if(leftAns){
            root->right = root->left;
            tail = leftAns;
        }

        if(rightAns) {
            tail->right = rootRight;
            tail = rightAns;
        }

        root->left = NULL;
        return tail;
    }

    void flatten(TreeNode* root) {
        helper(root);
    }
*/