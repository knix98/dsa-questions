/*
https://classroom.codingninjas.com/app/classroom/me/11692/content/204438/offering/2653309/problem/14165?leftPanelTabValue=PROBLEM
*/




/************************************************************

    Following is the Binary Tree node structure:
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/



/*
Intuition : we can do bfs and store NULL node after each of the levelNodes. Then the 1st and last nodes between NULL nodes would 
correspond to left fence and right fence nodes respectively.
Case 1 : NULL 1 2 3 NULL  => then 1 is left fence and 3 is right fence node
Case 2 : NULL 1 NULL  => then I would take 1 as left fence node

NOTE : this code might not pass in CN platform , but this is correct code
*/
void dfs(TreeNode<int>* node, vector<int> &leaves){
    if(node->left == NULL && node->right == NULL){
        leaves.push_back(node->data);
        return;
    }

    if(node->left) dfs(node->left, leaves);
    if(node->right) dfs(node->right, leaves);
}

vector<int> traverseBoundary(TreeNode<int>* root){
    queue<TreeNode<int>*> bfs;
    bfs.push(root);
    bfs.push(NULL);

    vector<int> lefts, rights, leaves;  // for collecting lefts, rights, leaves nodes
    vector<int> levelNodes;  // I will collect the left and right node for a level in this 
    while(!bfs.empty()){
        TreeNode<int> *front = bfs.front();
        bfs.pop();

        if(front != NULL){
            if(front->left) bfs.push(front->left);
            if(front->right) bfs.push(front->right);

            if(levelNodes.size() == 2) levelNodes[1] = front->data;  // keep updating the right node value untill we find the last right node for this level
            else levelNodes.push_back(front->data);
        }
        else {  // if NULL comes , that means this level is complete
            if(!bfs.empty()) bfs.push(NULL);

            if(levelNodes.size() >= 1) lefts.push_back(levelNodes[0]);
            if(levelNodes.size() >= 2) rights.push_back(levelNodes[1]);
            
            levelNodes.clear();
        }
    }

    // now need to collect all leaves nodes, that can be done using dfs only in the required order
    dfs(root, leaves);

    vector<int> ans;
    for(int i : lefts) ans.push_back(i);  // first inserting all lefts
    for(int i=1; i<leaves.size()-1; i++) ans.push_back(leaves[i]);  // the first leaf would be taken in lefts and last leaf in rights, so just insert the in-between leaves
    for(int i=rights.size()-1; i>=0; i--) ans.push_back(rights[i]);  // inserting rights in reverse order

    return ans;
}