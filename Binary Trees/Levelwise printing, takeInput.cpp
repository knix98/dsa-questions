#include<iostream>
#include<queue>
using namespace std;

template <typename T>
	class BinaryTreeNode {
    	public : 
    	T data;
    	BinaryTreeNode<T> *left;
    	BinaryTreeNode<T> *right;

    	BinaryTreeNode(T data) {
        	this -> data = data;
        	left = NULL;
        	right = NULL;
    	}

		~BinaryTreeNode(){
			delete left;  //even if left or right is NULL, delete NULL wud not give an error
			delete right;
		}
	};

BinaryTreeNode<int>* takeInputLevelWise(){
	int rootData;
	cout << "enter root data" << endl;
	cin >> rootData;
	if(rootData == -1){
		return NULL;
	}
	BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData); //since we would pass the pointer to tree root, hence we need to create the tree in heap, so that the tree still remains even after the takeInput func is finished
	queue<BinaryTreeNode<int>*> pendingNodes;
	pendingNodes.push(root);

	while(!pendingNodes.empty()){
		BinaryTreeNode<int>* front = pendingNodes.front();
		pendingNodes.pop();
		int left;
		cout << "enter left child of " << front->data << endl;
		cin >> left;
		if(left != -1){
			BinaryTreeNode<int>* leftChild = new BinaryTreeNode<int>(left);
			front->left = leftChild;
			pendingNodes.push(leftChild);
		}
		
		int right;
		cout << "enter right child of " << front->data << endl;
		cin >> right;
		if(right != -1){
			BinaryTreeNode<int>* rightChild = new BinaryTreeNode<int>(right);
			front->right = rightChild;
			pendingNodes.push(rightChild);
		}
	}

	return root;
}

void printLevelWise(BinaryTreeNode<int> *root) {
	// Write your code here
    if(root == NULL){ //edge case
        return;
    }
        
    queue<BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while(!pendingNodes.empty()){
    	BinaryTreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        cout << front->data << ":";
        if(front->left != NULL){
            cout << "L:" << front->left->data << ",";
            pendingNodes.push(front->left);
        }
        else{
            cout << "L:-1,";
        }
        
        if(front->right != NULL){
            cout << "R:" << front->right->data;
            pendingNodes.push(front->right);
        }
        else{
            cout << "R:-1";
        }
        
        cout << endl;
    }
}

int main(){
	BinaryTreeNode<int>* root = takeInputLevelWise();
	printLevelWise(root);
}