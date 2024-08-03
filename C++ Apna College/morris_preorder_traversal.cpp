/*
    Print preorder traversal of a binary tree using morris traversal without disturbing the input tree structure.
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

vector<int> morrisPreorder(BinaryTreeNode<int>* root) {
    vector<int> ans;
    BinaryTreeNode<int>* cur = root;

    // while(cur) { // this loop would automatically end when we reach the right-most node in tree and then we move to its right (that would be NULL automatically)

    //     while(cur->left){ // this loop would only end if 1. cur->left is NULL or 2. we encounter a thread connection back to cur.
    //                       // Both the cases would mean that the current cur's left sub-tree is taken care of or not present(NULL), so we can put cur in inorder and move to right sub-tree of cur 
            
    //         BinaryTreeNode<int>* curLeft = cur->left;
    //         while(curLeft->right){ // taking curLeft (left child of current cur) to its rightmost end
    //             if(curLeft->right == cur){ 
    //                 // but if in this process we encounter a loop, that means there is already a connection between righmost end of curLeft
    //                 // and cur...this means that the current left sub-tree is taken care of and we can store the current cur in inorder and
    //                 // move to right sub tree of cur
    //                 break;
    //             }
    //             else{
    //                 curLeft = curLeft->right;
    //             }
    //         }

    //         if(curLeft->right == cur){
    //             // this check is required...so that if loop finished because of the break statement then we should
    //             // cut off that thread between curLeft and cur
    //             // and then break from this loop also...
    //             curLeft->right = NULL;
    //             break;
    //         }
    //         else{
    //             // if loop finished on reaching right-most end of curLeft,
    //             // then make thread between curLeft and cur and move cur to cur->left
    //             curLeft->right = cur;
    //             cur = cur->left;
    //         }
    //     }

    //     // coming out of the above loop would mean => 
    //     // that the current cur's left sub-tree is taken care of or not present(NULL), so we can put cur in inorder and move to right sub-tree of cur
    //     ans.push_back(cur->data);
    //     cur = cur->right;
    // }

    while(cur){ // this loop would automatically end when we reach the right-most node in tree and then we move to its right (that would be NULL automatically)

        while(cur->left){ // this loop would only end if 1. cur->left is NULL or 2. we encounter a thread connection back to cur.
                          // Both the cases would mean that the current cur's left sub-tree is taken care of or not present(NULL),so we can move to right sub-tree of cur(since cur is also taken care of earlier in preorder)
            BinaryTreeNode<int>* curLeft = cur->left;

            while(curLeft->right){ // taking curLeft (left child of current cur) to its rightmost end
                if(curLeft->right == cur){
                    // but if in this process we encounter a loop, that means there is already a connection between righmost end of curLeft
                     // and cur...this means that the current left sub-tree is taken care of and we can move to right sub tree of cur
                    break;
                }
                else{
                    curLeft = curLeft->right;
                }
            }

            if(curLeft->right == cur){
                // this check is required...so that if loop finished because of the break statement then we should
                 // cut off that thread between curLeft and cur
                 // and then break from this loop also...
                curLeft->right = NULL;
                break;
            }
            else{
                // if loop finished on reaching right-most end of curLeft,
                // then first push cur in preorder (because in preorder root is pushed first)
                 // then make thread between curLeft and cur and move cur to cur->left
                ans.push_back(cur->data);
                curLeft->right = cur;
                cur = cur->left;
            }
        }

        // coming out of the above loop would mean => 
         // that the current cur's left sub-tree is taken care of or not present(NULL)

         // so before moving to right of cur we need to check whether loop finished because cur had no left
         // because if that is the case, then pushing of cur(in preorder) is still left...so push cur then move to cur->right
        if(!cur->left){
            ans.push_back(cur->data);
        }
        cur = cur->right;
    }

    return ans;
}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    vector<int> ans = morrisPreorder(root);

    // input tree (level-wise) => 1 2 7 3 4 -1 8 -1 -1 5 6 9 -1 -1 -1 -1 -1 -1 -1
    for(int i=0; i<ans.size(); i++){
        cout << ans[i] << " ";
    }
    return 0;
}