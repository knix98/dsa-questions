/*
https://classroom.codingninjas.com/app/classroom/me/22205/content/575409/offering/8882660/problem/15778
*/


// latest simple code by me
// Intuition : start cutting the leaf nodes in round by round manner (similar to what we did in gardener_and_tree_codeforces.cpp problem earlier)
// and the nodes which are cut in the last round of cutting , are the centers of the n-ary tree 
vector<int> solve(vector<vector<int>> &tree, int n, vector<int> &degree){
    vector<int> leaves;
    for(int i=0; i<n; i++) if(degree[i] <= 1) leaves.push_back(i);  // first pushing the first layer of leaves

    while(1){
        vector<int> newLeaves;  // this will store the newly generated leaves, after cutting previous leaves

        for(int leaf : leaves){
            for(int node : tree[leaf]){
                degree[node]--;
                if(degree[node] == 1) newLeaves.push_back(node);
            }
        }

        n -= leaves.size();
        if(n == 0) return leaves;
        leaves = newLeaves;
    }

    // NOTE : instead of this approach of using leaves and newLeaves vectors, we could have used simply just 1 queue : pendingNodes
    // You can see the pendingNodes approach in topological sort problem in graph 1, which is also solved using a similar algo
}

vector<int> Center(int n, vector<vector<int>> &edges) {
    vector<vector<int>> tree(n, vector<int>(0)); // constructing a adjacency list for a tree with edges from 0 to n-1
    vector<int> degree(n, 0); // this would store for every node => how many other nodes it is connected to currently
    
    for(int i=0; i<edges.size(); i++){  
        int u = edges[i][0];
        int v = edges[i][1];

        tree[u].push_back(v);
        tree[v].push_back(u);
        degree[u]++;
        degree[v]++;
    }

    return solve(tree, n, degree);
}





// Intuition : start cutting the leaf nodes in round by round manner (similar to what we did in gardener_and_tree_codeforces.cpp problem earlier)
// and the nodes which are cut in the last round of cutting , are the centers of the n-ary tree
#include<bits/stdc++.h>

vector<int> bfs(vector<vector<int>> &tree, int n, vector<int> &degree){
    queue<int> pendingNodes;
    vector<int> visited(n, 0);

    for(int i=0; i<n; i++){
        if(degree[i] <= 1) {
            pendingNodes.push(i);
            visited[i] = 1;  // as soon as node pushed in queue, mark it as visited, otherwise it might be pushed multiple/duplicate times in future
        }
    }
    pendingNodes.push(-1);  // -1 would denote a change of level , or that now 1 round of cutting has been completed

    int cuttingRound = 1;
    while(!pendingNodes.empty()){
        int node = pendingNodes.front();
        pendingNodes.pop();
        
        if(node == -1){
            if (!pendingNodes.empty()) {
                pendingNodes.push(-1);
                cuttingRound++;
            }

            continue;
        }

        visited[node] = cuttingRound;

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

    vector<int> ans;
    for(int i=0; i<n; i++){
        // checking which nodes were cut in the last round of cutting => those nodes are our center nodes
        if(visited[i] == cuttingRound) ans.push_back(i);
    }

    return ans;
}

vector<int> Center(int n, vector<vector<int>> &edges) {
    vector<vector<int>> tree(n, vector<int>(0)); // constructing a adjacency list for a tree with edges from 0 to n-1
    vector<int> degree(n, 0); // this would store for every node => how many other nodes it is connected to currently
    
    for(int i=0; i<edges.size(); i++){  
        int u = edges[i][0];
        int v = edges[i][1];

        tree[u].push_back(v);
        tree[v].push_back(u);
        degree[u]++;
        degree[v]++;
    }

    return bfs(tree, n, degree);
}