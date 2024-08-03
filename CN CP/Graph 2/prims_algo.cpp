/*
https://classroom.codingninjas.com/app/classroom/me/22205/content/575411/offering/8882700/problem/7992
*/


#include <bits/stdc++.h>
using namespace std;

vector<bool> selected(100001);
vector<int> min_wt(100001);
vector<unordered_map<int, int>> graph(100001);
// note : here we used unordered_map for storing graph instead of vector<vector<int>> because here multiple edges between the same nodes are given repeatedly
// so we need to know when we encounter an already present edge. This is possible using unordered_map only in efficient manner, otherwise we would have 
// to build an adjacency matrix for doing the same, which would lead to O(n^2) time and space complexity

int prim_mst() {
    set<pair<int,int>> edge_options;  // {edge_weight, connected_node}

    // putting all edges from node 0 into the set
    for(auto edge : graph[0]) {
        edge_options.insert({edge.second, edge.first});
        min_wt[edge.first] = edge.second;
    }

    // we have selected node 0 initially to start
    selected[0] = true;

    int mst = 0;
    while (!edge_options.empty()) {
        auto edge = edge_options.begin();
        edge_options.erase(edge);

        int edge_end_node = edge->second;
        int edge_weight = edge->first;

        mst += edge_weight;
        selected[edge_end_node] = true;

        for(auto ed : graph[edge_end_node]) {
            int ed_end_node = ed.first;
            int ed_weight = ed.second;

            if (!selected[ed_end_node] && min_wt[ed_end_node] > ed_weight) {
                edge_options.erase({min_wt[ed_end_node], ed_end_node});
                edge_options.insert({ed_weight, ed_end_node});
                min_wt[ed_end_node] = ed_weight;
            }
        }
    }

    return mst;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int v, e;
        cin >> v >> e;

        for(int i=0; i<v; i++) selected[i] = false, min_wt[i] = INT_MAX, graph[i].clear();

        int a, b, w;
        for (int i = 0; i < e; i++) {
            cin >> a >> b >> w;

            // note : here we used unordered_map for storing graph instead of vector<vector<int>> because here multiple edges between the same nodes are given repeatedly
            // so we need to know when we encounter an already present edge. This is possible using unordered_map only in efficient manner, otherwise we would have 
            // to build an adjacency matrix for doing the same, which would lead to O(n^2) time and space complexity
            if(graph[a].count(b) == 0) graph[a][b] = w, graph[b][a] = w;
            else if(graph[a][b] > w) graph[a][b] = w, graph[b][a] = w;
        }

        int result = prim_mst();

        cout << result << endl;
    }

    return 0;
}