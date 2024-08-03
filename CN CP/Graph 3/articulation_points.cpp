/*
https://classroom.codingninjas.com/app/classroom/me/22205/content/575426/offering/8882982/problem/8221
*/




#include<bits/stdc++.h>
using namespace std;

/*
algo is similar as bridges algo and can read from CN pdf notes
*/

/*
    concept of dfs tree of a graph:
        if graph =>            1         so 1 has 2 child nodes in actual graph
                              / \
                             2___3

        then its dfs tree =>            1      but 1 has only 1 child node in dfs tree
                                       /
                                      2___3
*/

void dfs(int node, int parent, vector<vector<int>> &g, vector<bool> &visited, vector<int> &low, vector<int> &inTime, vector<int> &ans, int &timer){
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
                  ans.push_back(node);
                }
            }

            low[node] = min(low[node], low[v]);
        }
    }

    // if the current node is root node, then we need to determine whether its articulation or not here
    // for root to be articulation, child of root > 1
    if((parent == -1) && (child > 1)) ans.push_back(node);
} 

int main(){
    int t, n, m;
    cin >> t;

    int a, b;
    while(t--){
        cin >> n >> m;

        vector<vector<int>> g(n+1, vector<int>(0));

        for(int i=0; i<m; i++){
            cin >> a >> b;
            g[a].push_back(b);
            g[b].push_back(a);
        }

        vector<bool> visited(n+1, false);
        vector<int> inTime(n+1);
        vector<int> low(n+1);
        vector<int> ans;
        int timer = 1;

        for(int i=1; i<=n; i++) if(!visited[i]) dfs(i, -1, g, visited, low, inTime, ans, timer);

        sort(ans.begin(), ans.end());

        for(int i : ans) cout << i << " ";
        cout << endl;
    }

    return 0;
}





