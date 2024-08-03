/*
codeforces - military problem - https://codeforces.com/problemset/problem/1006/E
*/

#include<bits/stdc++.h>
using namespace std;

void DFS(vector<vector<int>> &tree, int root, vector<int> &dfs, vector<vector<int>> &dfsIndexRange){
    dfs.push_back(root);
    dfsIndexRange[root].push_back(dfs.size()-1); // since just now only we pushed the root of the subtree, so the last index of dfs currently , would be the starting index of this subtree's dfs

    for(int i=0; i<tree[root].size(); i++){  // the input was given in ascending order of the nums only, so we can be assured that the children of the root would be in ascending order only
        DFS(tree, tree[root][i], dfs, dfsIndexRange);
    }

    dfsIndexRange[root].push_back(dfs.size()-1); // since right now the last element in the dfs array would be the last element of the dfs traversal of this subtree also
}

int main(){
    int n, q;
    cin >> n >> q;

    // now we will take cin of the parents of nums => [2, n]
    vector<vector<int>> tree(n+1, vector<int>(0));
    for(int i=2; i<=n; i++){
        int parent;
        cin >> parent;
        tree[parent].push_back(i);
    }

    vector<int> dfs;  // for storing the dfs traversal 
    vector<vector<int>> dfsIndexRange(n+1, vector<int>(0)); // this vector would store for every node => what is the index range in the dfs traversal array in which this node's subtree's nodes lie
    DFS(tree, 1, dfs, dfsIndexRange);

    // taking queries now
    vector<int> answers;
    while(q--){
        int root, position;
        cin >> root >> position;

        int rootTreeSize = dfsIndexRange[root][1] - dfsIndexRange[root][0] + 1;
        if(position > rootTreeSize) answers.push_back(-1);
        else{
            answers.push_back(dfs[dfsIndexRange[root][0] + position - 1]);
        }
    }

    for(int i : answers) cout << i << endl;
}