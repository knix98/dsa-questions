#include <iostream>
#include<vector>
#include<queue>
using namespace std;

template <typename T>
class TreeNode{
    public:
    T data;
    vector<TreeNode<T>*> children;

    TreeNode(T data){
        this->data = data;
    }
};


//since no argument is being passed to this function, so the function wud not be able to know the typename T
// so an arguments-less function can't be made universal using templates
TreeNode<int>* takeInputLevelwise(){
    int rootData;
    cout << "Enter root data : ";
    cin >> rootData;
    TreeNode<int> *root = new TreeNode<int>(rootData);

    queue<TreeNode<int>*> nodes;
    nodes.push(root);

    while(!nodes.empty()){
        TreeNode<int> *front = nodes.front();
        nodes.pop();

        int children;
        cout << "Enter number of children of " << front->data << " : ";
        cin >> children;
        
        for(int i=1; i<=children; i++){
            int childData;
            cout << "Enter data for " << i << "th child of " << front->data << " : ";
            cin >> childData;

            TreeNode<int> *child = new TreeNode<int>(childData);
            front->children.push_back(child);
            nodes.push(child);
        }
    }

    return root;
}


//here, since a root TreeNode containing a defined 'data' of some fixed datatype is being passed as argument, so
//the function wud be able to figure out the 'typename T' by the datatype of the data of the root TreeNode
//so a function with a argument can be made universal using templates
template<typename T>
void printLevelwise(TreeNode<T> *root){
    if(root == NULL){
        return;
    }

    queue<TreeNode<T>*> nodes;
    nodes.push(root);

    while(!nodes.empty()){
        TreeNode<T> *front = nodes.front();
        nodes.pop();

        cout << front->data << " ";

        for(int i=0; i<front->children.size(); i++){
            nodes.push(front->children[i]);
        }
    }
}


int main(){
    TreeNode<int> *root = takeInputLevelwise();
    printLevelwise(root);
}