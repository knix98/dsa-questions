/*
https://classroom.codingninjas.com/app/classroom/me/22205/content/575426/offering/8882988/problem/13798?leftPanelTabValue=PROBLEM
*/



// you can read from CN pdf notes about this algo of finding bridges
// inTime[i] = the time when ith node was visited...inTime[v] is constant and we dont change it
// low[i] = deepest ancestor's inTime value, upto which ith node can reach by moving foward on the forward edges

void dfs(int node, int parent, vector<vector<int>> &g, vector<vector<int>> &ans, vector<bool> &vis, vector<int> &inTime, vector<int> &low, int &timer) {
    inTime[node] = low[node] = timer++;  // first set the intime and low value for the current node
    vis[node] = true;  // mark as visited

    for(int v : g[node]){
        if(v == parent) continue;  // in this algo, we just consider the forward edges and not the edge back to the parent

        if(vis[v] == true){
            // that means the current edge is a back-edge (back edge is an edge which forms a cycle in a graph)
            // or back-edge = one which connects the current node to 1 of its ancestor nodes (other than parent)
            
            // toh just reset the low value for current node, by also considering the inTime of the ancestor
            // because no we know that the current node can reach as low as this ancestor by moving forward

            low[node] = min(low[node], inTime[v]); // in case of back-edge, we dont consider low[v], because
            // we are doing dfs tree traversal of the graph and hence we dont want to go round in any loop
            // so whenever we encounter a back-edge, we dont move forward with dfs call and also just
            // consider the inTime[v] instead of low[v] because we cannot move forward from v
        }
        else{
            // that means the current edge is a forward-edge
            // first call dfs on unvisited v
            dfs(v, node, g, ans, vis, inTime, low, timer);

            // now we are sure that after finish of dfs call for the v node, its low[v] value has been finalised
            // so if the low[v] value = most lower ancestor that v can go back to, is higher than the inTime[node],
            // that means the v cannot reach upto the current node by moving forward, which implies that,
            // the current edge between node->v is a bridge
            if(low[v] > inTime[node]){
                // means this edge is bridge
                ans.push_back({node, v});
            }

            // finally since this edge was a forward-edge, so compare the low[node] with low[v]
            low[node] = min(low[node], low[v]);
        }
    }
}

vector<vector<int>> criticalConnections(int v, vector<vector<int>> &edges) {
    vector<vector<int>> g(v, vector<int>(0));  // graph adjacency list
    // making adjacency list of size v only because nodes are numbered from [0, v-1]

    // building adjacency list
    for(vector<int> edge : edges){
        g[edge[0]].push_back(edge[1]);
        g[edge[1]].push_back(edge[0]);
    }

    vector<vector<int>> ans;
    vector<bool> vis(v, false);
    vector<int> inTime(v);
    vector<int> low(v);
    int timer = 1;

    for(int i=0; i<v; i++){
        if(!vis[i]){
            dfs(i, -1, g, ans, vis, inTime, low, timer);
        }
    }

    return ans;
}