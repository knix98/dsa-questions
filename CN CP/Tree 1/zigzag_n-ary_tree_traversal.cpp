/*
https://classroom.codingninjas.com/app/classroom/me/22205/content/575409/offering/8882659/problem/16294
*/


/**************************************************
   
    class TreeNode
    {
    public:
        int val;
        vector < TreeNode* > child;
        
        TreeNode(int val)
        {
            this->val = val;
        }

        ~TreeNode()
        {
            for( int i=0 ; i<child.size();i++)
            {
                delete child[i];
            }
        }
    };
    
*****************************************************/

// the method below is using 2 stacks for zig-zag traversal, plz look at the code once for revision
// second method could be to simply do level order traversal and store the nodes at each level in a 2d array
// and then print nodes in odd levels in left to right fashion.... and nodes in even levels in right to left fashion

#include<stack>

vector<int> zigzagLevelOrder(int n, TreeNode* root)
{
    vector<int> ans;

    stack<TreeNode*> nodes;
    nodes.push(root);

    bool ltr = true;
    while(ans.size() < n) {
        stack<TreeNode*> nextNodes;
        while(!nodes.empty()){
            TreeNode* top = nodes.top();
            nodes.pop();

            ans.push_back(top->val);

            vector < TreeNode* > nodeChild = top->child;
            if(ltr){
                for(int i=0; i<nodeChild.size(); i++){
                    nextNodes.push(nodeChild[i]);
                }
            }
            else{
                for(int i=nodeChild.size()-1; i>=0; i--){
                    nextNodes.push(nodeChild[i]);
                }
            }
        }

        nodes = nextNodes;
        ltr = !ltr;
    }

    return ans;
}