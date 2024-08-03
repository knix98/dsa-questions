/*
Given a BST, convert it into a sorted linked list. You have to return the head of LL.
*/

#include <iostream>
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
 	class Node{
    	public:
    	T data;
    	Node<T> *next;
    
    	Node(T data) {
        	this->data = data;
        	this->next = NULL;
    	}
 	};


//APPROACH 1: The more complex approach using double pointer
//(Node<int>** head) is a double pointer containing address of a pointer variable (which is saved and is supposed to be pointing towards the head of the final LL)
//this helper function wud take in the constant **head and a *tail pointers to the final LL as arguments
//and return the tail of the updated final LL, after adding all the nodes in it to the final linked list
Node<int>* helper(BinaryTreeNode<int>* root, Node<int>** head, Node<int>* tail){
    if(root == NULL) return tail; //if no nodes in the tree, then return the tail as it is without any further updates to it
    
    Node<int>* leftAnsTail = helper(root->left, head, tail); //first receive the updated tail(of final LL) after all the nodes of the left subtree added to final LL
    
    //now leftAnsTail is the pointer to the tail of the final LL
    if(leftAnsTail == NULL){ 
        *head = new Node<int>(root->data);
        leftAnsTail = *head;
    }
    else{
        leftAnsTail->next = new Node<int>(root->data);
        leftAnsTail = leftAnsTail->next;
    }
    
    Node<int>* rightAnsTail = helper(root->right, head, leftAnsTail);
    //now rightAnsTail is the pointer to the tail of the final LL
    return rightAnsTail;

    /*
    the above could also be written directly as:
    return helper(root->right, head, leftAnsTail);
    */
}


Node<int>* constructLinkedList(BinaryTreeNode<int>* root) {
	Node<int>* head = NULL;
    helper(root, &head, NULL); //pass the address of the created pointer for storing address of head node
                               //using this '&head' the helper function wud be able to save the address of the newly created head node whenever head node(least value) data encountered in the tree
                               //NULL is passes as tail pointer since no tail as of now (since no LL created initially)
    
    return head; //after function executed, head wud be containing the address of the head node of LL created in heap memory
}





//APPROACH 2: the easier approach using a pair return type, returning the head and tail nodes of the LL
//APPROACH : 1st call recursion on left tree and get full LL of left tree similarly call recursion on right tree
//			 and get full LL of right tree. 
#include<utility>
pair<Node<int>*, Node<int>*> constructLinkedListHelper(BinaryTreeNode<int>* root){
    if(root == NULL){
        pair<Node<int>*, Node<int>*> p;
        p.first = NULL;
        p.second = NULL;
        return p;
    }
    
    pair<Node<int>*, Node<int>*> leftTr = constructLinkedListHelper(root->left);
    Node<int>* rootNode = new Node<int>(root->data); //rootNode created
    pair<Node<int>*, Node<int>*> rightTr = constructLinkedListHelper(root->right);
    
    pair<Node<int>*, Node<int>*> ans;
    
    if(leftTr.first != NULL){ //means left tree LL is not empty
        ans.first = leftTr.first; //left tree LL's head would be final head too
        leftTr.second->next = rootNode; //connect rootNode to left tree LL's tail
    }
    else{
        ans.first = rootNode; //if left LL empty then rootNode will be final head
    }
    
    rootNode->next = rightTr.first;
    
    if(rightTr.second != NULL){
        //rightTr.second->next = NULL;
        ans.second = rightTr.second;
        return ans;
    }
    else{
        ans.second = rootNode;
        return ans;
    }
}


Node<int>* constructLinkedList(BinaryTreeNode<int>* root) {
	// Write your code here
    if(root==NULL){
        return NULL;
    }
    
    return constructLinkedListHelper(root).first;
}