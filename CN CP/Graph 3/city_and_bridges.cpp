/*
https://classroom.codingninjas.com/app/classroom/me/22205/content/575426/offering/8882988/problem/13747?leftPanelTabValue=PROBLEM
*/



void dfs(int node, int parent, vector<vector<int>> &g, vector<bool> &visited, vector<int> &low, vector<int> &inTime, vector<bool> &ans, int &timer){
    visited[node] = true;
    inTime[node] = low[node] = timer++;
    int child = 0; // this will keep count of the number of child nodes of current node in the dfs tree
    bool isArticulationPoint = false;

    for(int v : g[node]){
        if(v==parent) continue;

        if(visited[v]){
            // means back-edge
            low[node] = min(low[node], inTime[v]);
        }
        else{
            // means forward-edge
            child++;
            dfs(v, node, g, visited, low, inTime, ans, timer);

            if((parent != -1) && (low[v] >= inTime[node])){
                // here we can only determine whether current node is articulation point or not for only non-root nodes
                if (!isArticulationPoint) {  // since from other nodes also it might prove that the current node is articulation, but we will push node in ans only once
                  isArticulationPoint = true;
                  ans[node] = true;
                }
            }

            low[node] = min(low[node], low[v]);
        }
    }

    // if the current node is root node, then we need to determine whether its articulation or not here
    // for root to be articulation, child of root > 1
    if((parent == -1) && (child > 1)) ans[node] = true;
} 

void cityAndBridges(vector<vector<int>> &edges, int n, int m, int q, vector<int> &query) 
{
    vector<vector<int>> g(n, vector<int>(0));

    for(int i=0; i<m; i++){
        g[edges[i][0]].push_back(edges[i][1]);
        g[edges[i][1]].push_back(edges[i][0]);
    }

    vector<bool> visited(n, false);
    vector<int> inTime(n);
    vector<int> low(n);
    vector<bool> ans(n, false);
    int timer = 1;

    for(int i=0; i<n; i++) if(!visited[i]) dfs(i, -1, g, visited, low, inTime, ans, timer);

    for(int q : query){
        if(ans[q]) cout << "Yes" << " ";
        else cout << "No" << " ";
    }
}