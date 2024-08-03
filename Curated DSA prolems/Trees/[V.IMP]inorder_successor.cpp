/*
https://classroom.codingninjas.com/app/classroom/me/11692/content/204438/offering/2653309/problem/14207?leftPanelTabValue=PROBLEM
*/




/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;
        TreeNode<T> *next;

	    TreeNode(T data)
	    {
		    this->data = data;
		    left = NULL;
		    right = NULL;
		    next=NULL;
	    }
    };

************************************************************/

// in this problem, we have to set the inorder successor of each node, inside the *next pointer of each node 

// this func would take the current last node in inorder traversal path as input and after the curr root's whole tree traversal is over, then return the 
// the last node currently in inorder traversal path
TreeNode<int>* inorder(TreeNode<int> *last, TreeNode<int> *root){
    if(root == NULL) return last;

    TreeNode<int>* leftLast = inorder(last, root->left);
    if(leftLast) leftLast->next = root;
    return inorder(root, root->right);
}

void inorderSuccessor(TreeNode<int> *root)
{
    inorder(NULL, root);
}