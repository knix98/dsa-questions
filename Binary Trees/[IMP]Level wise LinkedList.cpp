/*
Given a binary tree, write code to create a separate linked list for each level. 
You need to return the array which contains head of each level linked list.
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

template <typename T>
	class Node {
		public:
    	T data;
    	Node<T> *next;
    	Node(T data) {
        	this->data=data;
        	this->next=NULL;
    	}
	};

vector<Node<int>*> constructLinkedListForEachLevel(BinaryTreeNode<int> *root) {
    queue<BinaryTreeNode<int>*> nodes;
    vector<Node<int>*> ans;
    
    if(root == NULL){
        return ans; //return empty vector (base case)
    }
    
    nodes.push(root);
    nodes.push(NULL); //because after root node, new level starts
    Node<int>* head = NULL;
    Node<int>* tail = NULL;
    
    while(!nodes.empty()){
        BinaryTreeNode<int> *front = nodes.front();
        nodes.pop();
        if(front != NULL){
        	if(front->left != NULL) nodes.push(front->left);
            if(front->right != NULL) nodes.push(front->right);
            
            if(head == NULL){
                head = new Node<int>(front->data);
                tail = head;
            }
            else{
                tail->next = new Node<int>(front->data);
                tail = tail->next;
            }
        }
        else{
            if(head != NULL) ans.push_back(head);
            head = NULL;
            tail = NULL;
            
            if(!nodes.empty()) nodes.push(NULL);
        }
    }
    
    return ans;
}