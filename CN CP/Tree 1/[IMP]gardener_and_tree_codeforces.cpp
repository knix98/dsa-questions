/*
Codeforces problem : E. Gardener and Tree
https://codeforces.com/problemset/problem/1593/E

Example :

        5                                  5
      / | \        cut leaf nodes         / \
    1   4   2         =======>           4   2       ====>       5
        |   |
        3   6                         leaf = 4,2               leaf = 5 only

    leaf = 1,3,6
*/




// latest simple code by me
int solve(vector<vector<int>> &tree, int n, int k, vector<int> &degree){  // k is the number of rounds of cutting we have to do
    vector<int> leaves;
    for(int i=1; i<n+1; i++) if(degree[i] <= 1) leaves.push_back(i);  // first pushing the first layer of leaves

    while(k--){
        vector<int> newLeaves; // this will store the newly generated leaves, after cutting previous leaves

        for(int leaf : leaves){
            for(int node : tree[leaf]){
                degree[node]--;
                if(degree[node] == 1) newLeaves.push_back(node);
            }
        }

        n -= leaves.size();
        leaves = newLeaves;
    }

    return n;
}

int main() {
    int t;
    cin >> t;

    vector<int> ans;
    while(t--){
        int n, k;
        cin >> n >> k;

        vector<vector<int>> tree(n+1, vector<int>(0)); // constructing a adjacency list for a tree with edges from 1 to n
        vector<int> degree(n+1, 0); // this would store for every node => how many other nodes it is connected to currently
        for(int i=0; i<n-1; i++){  // n-1 edges
            int u, v;
            cin >> u >> v;

            tree[u].push_back(v);
            tree[v].push_back(u);
            degree[u]++;
            degree[v]++;
        }

        if(k >= n) cout << 0 << endl;
        else cout << solve(tree, n, k, degree) << endl;
    }

    return 0;
}





// here adjacency list would come in handy, as adjacency list helps us to easily identify the degree (how many other nodes its connected to) of any node
// so a leaf = whose degree is 1  
// so in every round of cutting, we will keep on cutting the nodes whose degree is 1 at that moment
// and after cutting a leaf node, all the other nodes's (which were connected to this leaf node would) degree would decrease by 1
#include <bits/stdc++.h>
using namespace std;

int bfs(vector<vector<int>> &tree, int n, int k, vector<int> &degree){  // k is the number of rounds of cutting we have to do
    queue<int> pendingNodes; // if a node is present inside this queue, then that definitely means that this node is a leaf, and will be cut when taken out of this queue
    vector<int> visited(n+1, 0); // as soon as node pushed in queue, mark it as visited

    // first push all the leaf nodes in the queue
    for(int i=1; i<=n; i++){
        if(degree[i] <= 1) {
            pendingNodes.push(i);
            visited[i] = 1;  // as soon as node pushed in queue, mark it as visited, otherwise it might be pushed multiple/duplicate times in future
        }
    }
    pendingNodes.push(-1);  // -1 would denote a change of level , or that now 1 round of cutting has been completed

    int totalNodesRemaining = n;

    while(k > 0 && !pendingNodes.empty()){
        int node = pendingNodes.front();
        pendingNodes.pop();
        
        if(node == -1){
            k--;
            if(!pendingNodes.empty()) pendingNodes.push(-1);
            continue;
        }

        totalNodesRemaining--;  // since the current node taken out , can be considered as cut from the tree

        // now traverse over all the neighbours of this leaf node and if they are already not in queue, then decrease their degree by 1 
        // and then check their degree => if degree has become <=1 , then push inside queue
        for(int i=0; i<tree[node].size(); i++){
            int adjacentNode = tree[node][i];

            if(!visited[adjacentNode]) {
                degree[adjacentNode]--;
                
                if(degree[adjacentNode] <= 1){
                    pendingNodes.push(adjacentNode);
                    visited[adjacentNode] = 1;
                }
            }
        }
    }

    return totalNodesRemaining;
}

int main() {
    int t;
    cin >> t;

    while(t--){
        int n, k;
        cin >> n >> k;

        vector<vector<int>> tree(n+1, vector<int>(0)); // constructing a adjacency list for a tree with edges from 1 to n
        vector<int> degree(n+1, 0); // this would store for every node => how many other nodes it is connected to currently
        for(int i=0; i<n-1; i++){  // n-1 edges
            int u, v;
            cin >> u >> v;

            tree[u].push_back(v);
            tree[v].push_back(u);
            degree[u]++;
            degree[v]++;
        }

        if(k >= n) cout << 0 << endl;
        else cout << bfs(tree, n, k, degree) << endl;
    }

    return 0;
}