/*
    Print all nodes which are present at a distance k from a given node in a binary tree.
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

void collectNodes(TreeNode* root, int d, vector<int> &ans){
    if(root == NULL) return;
    if(d == 0){
        ans.push_back(root->val);
        return;
    }

    collectNodes(root->left, d-1, ans);
    collectNodes(root->right, d-1, ans);
}

int targetFinder(TreeNode* root, TreeNode* target, int k, vector<int> &ans) {
    if(root == NULL){
        return -1;
    }

    if(root == target){
        collectNodes(root, k, ans);
        return 0;
    }

    int leftAns = targetFinder(root->left, target, k, ans);
    if(leftAns != -1){
        int diff = k - (leftAns + 1);
        if(diff == 0){
            ans.push_back(root->val);
        }
        else if(diff > 0){
            collectNodes(root->right, diff-1, ans);
        }

        return leftAns + 1;
    }

    int rightAns = targetFinder(root->right, target, k, ans);
    if(rightAns != -1){
        int diff = k - (rightAns + 1);
        if(diff == 0){
            ans.push_back(root->val);
        }
        else if(diff > 0){
            collectNodes(root->left, diff-1, ans);
        }

        return rightAns + 1;
    }

    return -1;
}

vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
    vector<int> v;
    targetFinder(root, target, k, v);
    return v;
}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    vector<int> ans = nodesAtK(root, 4, 2);

    // input tree (level-wise) => 1 2 7 3 4 -1 8 -1 -1 5 6 9 -1 -1 -1 -1 -1 -1 -1
    for(int i=0; i<ans.size(); i++){
        cout << ans[i] << " ";
    }

    return 0;
}