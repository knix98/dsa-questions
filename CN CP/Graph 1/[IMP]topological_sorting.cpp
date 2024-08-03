/*
https://classroom.codingninjas.com/app/classroom/me/22205/content/575410/offering/8882679/problem/8987

*/


// approach 1 : using indegree values for each node
// can read about this approach solution in CN CP pdf notes
#include<queue>

vector<int> topologicalBFS(vector<vector<int>> &graph, vector<int> &inDegree, int v){
    queue<int> pending;
    vector<int> ans;

    for(int i=0; i<v; i++){
        if(inDegree[i] == 0) pending.push(i);
    }

    while(!pending.empty()){
        int front = pending.front();
        ans.push_back(front);
        pending.pop();

        for(int node : graph[front]){
            inDegree[node]--;
            if(inDegree[node] == 0) pending.push(node);
        }
    }

    return ans;
}

vector<int> topologicalSort(vector<vector<int>> &edges, int e, int v) {
    vector<vector<int>> graph(v);
    vector<int> inDegree(v, 0);

    for(vector<int> edge : edges){
        graph[edge[0]].push_back(edge[1]);
        inDegree[edge[1]]++;
    } 

    return topologicalBFS(graph, inDegree, v);
}




// approach 2 : using dfs traversal 
// this method would generate the topological sort in reverse order, since we would be inserting the leaf nodes first
// so just reverse the answer array before returning it as answer
#include<algorithm>

void dfs(vector<vector<int>> &graph, int node, vector<int> &ans, vector<int> &vis){
    vis[node] = 1;
    
    // first traverse over all the outgoing edges from this current node
    for(int neighbour : graph[node]){
        if(!vis[neighbour]) dfs(graph, neighbour, ans, vis);
    }

    // after doing the above traversal, we can be sure that all the outgoing edges and the nodes in that have been covered
    // so now we can push the current node in answer
    ans.push_back(node);
}

vector<int> topologicalSort(vector<vector<int>> &edges, int e, int v) {
    vector<vector<int>> graph(v);

    for(vector<int> edge : edges){
        graph[edge[0]].push_back(edge[1]);
    } 

    vector<int> ans;
    vector<int> vis(v, 0);
    for(int i=0; i<v; i++){
        if(!vis[i]) dfs(graph, i, ans, vis);
    }

    reverse(ans.begin(), ans.end());

    return ans;
}
