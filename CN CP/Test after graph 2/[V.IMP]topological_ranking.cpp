/*
https://classroom.codingninjas.com/app/classroom/me/22205/content/575412/offering/8882723/problem/16366?leftPanelTabValue=PROBLEM
*/



// latest code by me : we have to get a topological order here. But we cannot use dfs, because although dfs would give us a valid topological order,
// but we want all the nodes having same rank (as in they are at same level in bfs) to be printed together in ascending order.
// So we can think of it as collecting leaf nodes in each round of cutting of leaf nodes (center of n-ary tree problem)
#include<bits/stdc++.h>

vector<int> topo(vector<vector<int>> &graph, vector<int> &outdegree, int n){
    vector<int> ans;
    set<int> leaves; // will use set for storing each layer of leaves in ascending order
    for(int i=1; i<=n; i++) if(outdegree[i] == 0) leaves.insert(i); // first layer of leaves

    while(leaves.size() > 0){
        set<int> newLeaves;

        for(int leaf : leaves){
            ans.push_back(leaf);

            for(int node : graph[leaf]){
                outdegree[node]--;
                if(outdegree[node] == 0) newLeaves.insert(node);
            }
        }

        leaves = newLeaves;
    }

    return ans;
}

vector<int> rankOfEach(int n, int k, vector<vector<int>> &relations) {
    vector<vector<int>> graph(n+1);
    vector<int> outdegree(n+1, 0);
    for(auto it : relations){
        graph[it[1]].push_back(it[0]);  // making edge in reverse direction (from leaf/child to parent node) because
                                        // when we cut a leaf, then we need to know its parent in order to reduce the
                                        // parent's outdegree value
        outdegree[it[0]]++;  // increasing outdegree of parent node (in accordance with the original direction of the edge)
    }

    return topo(graph, outdegree, n);
}




// earlier code
#include<bits/stdc++.h>

vector<int> topological_sort(vector<vector<int>> &graph, vector<int> &in_degree, int n){
    queue<int> pending;

    for(int i=1; i<=n; i++){
        if(in_degree[i] == 0) pending.push(i);
    }
    pending.push(-1); // -1 denotes a change of rank by 1, like from 1st to 2nd

    priority_queue<int, vector<int>, greater<int>> min_pq; // for arranging the nodes having same rank in ascending order (given in question)

    vector<int> ans;

    while(!pending.empty()){
        while(pending.front() != -1){
            int front = pending.front();
            pending.pop();
            ans.push_back(front);

            for(int i : graph[front]){
                in_degree[i]--;
                if(in_degree[i] == 0) min_pq.push(i);
            }
        }

        pending.pop();

        while(!min_pq.empty()){
            int top = min_pq.top();
            min_pq.pop();
            pending.push(top);
        }

        if(!pending.empty()) pending.push(-1);  
    }

    // reverse(ans.begin(), ans.end());

    return ans;
}

bool cmp(vector<int> &a, vector<int> &b){
    if(a[0] != b[0]) return a[0] < b[0];
    else return a[1] < b[1];
}

vector<int> rankOfEach(int n, int k, vector<vector<int>> &relations) {
    // sort(relations.begin(), relations.end(), cmp);

    vector<vector<int>> graph(n+1);
    vector<int> in_degree(n+1, 0);

    // IMP : since in this ranking we want to keep the student having higher rank first, and since in test cases, 3 2 means 2 is having higher rank than 3,
    // and since in topological sorting algo, the nodes having the 0 indegree are spotted first, so while bulding the graph we will keep edge from
    // edge[1] to edge[0], so that indegree of edge[1] (having higher rank) is lesser
    for(auto edge : relations){
        graph[edge[1]].push_back(edge[0]);
        in_degree[edge[0]]++;
    }

    // for(int i=1; i<=n; i++){
    //     sort(graph[i].begin(), graph[i].end());
    // }

    return topological_sort(graph, in_degree, n);
}