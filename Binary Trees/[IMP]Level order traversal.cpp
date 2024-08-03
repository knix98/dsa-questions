/*
For a given a Binary Tree of type integer, print it in a level order fashion where each level will be printed on a new line. 
Elements on every level will be printed in a linear fashion and a single space will separate them.

Input: 
     10
  20     30
40  50      60

Output:
For the above-depicted tree, when printed in a level order fashion, the output would look like:

10
20 30 
40 50 60
Where each new line denotes the level in the tree.
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

//First code is my approach, second code is the solution approach
//SECOND CODE IS BETTER APPROACH.....USE THAT ONLY...................................................
void printLevelWise(BinaryTreeNode<int> *root) {
    // Write your code here
    queue<BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    int count = 1; 			//count denotes the total number of elements to be printed in the current line
    			   			//since in first line only root->data will be printed hence initially count =1		
    
    while(!pendingNodes.empty()){
        int k=0; 			//k will keep updating as we keep enquing the children of the front nodes
        		 			//that is, k represents the total number of elements that would be printed in the next line
        		 			//after the current line printing is done
        while(count!=0){
            BinaryTreeNode<int>* front = pendingNodes.front();
            pendingNodes.pop();
            count--;
            cout << front->data << " ";
            if(front->left != NULL){
                pendingNodes.push(front->left);
                k++;
            }
            if(front->right != NULL){
                pendingNodes.push(front->right);
                k++;
            }
        }
        cout << endl; 		//after count==0 means current line printing is done, move to next line
        count = k; 			//for next line the updated k represents the total number of elements to be printed
    }
}



// Solution approach
//in this approach, we push a NULL pointer after the nodes of every line, so that
//whenever we encounter a NULL in the queue we should know that nodes after this have to be printed in the next line

void printLevelWise(BinaryTreeNode<int> *root){
    queue<BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    pendingNodes.push(NULL); //after printing root->data move to next line
    
    while(!pendingNodes.empty()){
        BinaryTreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        if(front != NULL){
            cout << front->data << " ";
            if(front->left != NULL){
                pendingNodes.push(front->left);
            }
            if(front->right != NULL){
                pendingNodes.push(front->right);
            }
        }
        else{ //if front == NULL
            if(pendingNodes.empty()){ //represents that this was the last NULL in the queue, which means printing is done
                return;
            }
            else{
                cout << endl;
                pendingNodes.push(NULL); //this will push a NULL after the nodes that are currently present in the queue
            }							 //the cuurently present nodes are the ones which will be printed in the next line
        }
    }
}