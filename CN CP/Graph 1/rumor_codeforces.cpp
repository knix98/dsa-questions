/*
https://codeforces.com/problemset/problem/893/C
*/

/*
Input :
5 2
2 5 3 4 8
1 4
4 5
*/


// just have to do a bfs/dfs traversal over all nodes that are connected and determine the minimum cost amongst them and add it to the totalCost
#include<bits/stdc++.h>
using namespace std;

#define ll long long

ll bfs(vector<vector<int>> &graph, vector<ll> &cost, vector<int> &vis, int node){
    queue<int> pending;
    pending.push(node);
    vis[node] = 1;

    ll minCost = LONG_LONG_MAX;

    while(!pending.empty()){
        int front = pending.front();
        pending.pop();
        minCost = minCost > cost[front] ? cost[front] : minCost;

        for(int i : graph[front]){
            if(!vis[i]) {
                pending.push(i);
                vis[i] = 1;
            }
        }
    }

    return minCost;
}

int main() {
    int v, e;
    cin >> v >> e;

    vector<ll> cost(v);
    for(int i=0; i<v; i++) cin >> cost[i];

    vector<vector<int>> graph(v);
    int a, b;
    for(int i=0; i<e; i++){
        cin >> a >> b;
        graph[a-1].push_back(b-1);  // since I am storing nodes from 0 to v-1, but edges are given considering 1 to v nodes numbering
        graph[b-1].push_back(a-1);
    }

    ll totalCost = 0;
    vector<int> vis(v, 0);

    for(int i=0; i<v; i++){
        if(!vis[i]){
            totalCost += bfs(graph, cost, vis, i);
        }
    }

    cout << totalCost;

    return 0;
}