/*
https://classroom.codingninjas.com/app/classroom/me/22205/content/575411/offering/8882709/problem/7990
*/



// this question had weighted-directed-graph...so see that djikstra(if -ve weight cycle not present) and bellman-ford can be used on directed graphs as well
// as written in my hand notes too
#include<bits/stdc++.h>
using namespace std;

#define ll long long

vector<unordered_map<int, int>> graph(201);
vector<ll> min_dist(201);

int bellFord(int n, int m, int src, int dest){
    min_dist[src] = 0;
    int changes = 1;  // because we just changed min_dist of src node to 0 from INT_MAX, consider this as the 0th iteration
    int iteration = 1; // for doing n iterations of bellman-ford algo

    while(changes > 0 && iteration <= n){
        changes = 0;

        for(int i=0; i<n; i++){
            for(auto edge : graph[i]){
                int from_node = i;
                int to_node = edge.first;
                int edge_weight = edge.second;

                if(min_dist[from_node] < 1e9 && min_dist[from_node] + edge_weight < min_dist[to_node]) {
                    // the 2 above conditions to satisfy : 
                    // 1. the from_node should have gotten its min_dist value (lesser than 1e9) from src node till now. 
                    // This condition would also take care of the case that if from_node and to_node belongs to a different connected component.
                    // For nodes , which are not inside the connected component of the source node, we should not do anything
                    // 2. min_dist[from_node] + edge_weight < min_dist[to_node]
                    min_dist[to_node] = min_dist[from_node] + edge_weight;
                    changes++;
                }
            }
        }

        iteration++;
    }

    if(iteration > n && changes > 0) {
        // that means negative cycle is present in graph, because changes were done in nth iteration as well
        return 1e9;
    }
    else{
        return min_dist[dest];
    }
}

int main(){
    int t, n, m, s, d;
    cin >> t;

    while(t--){
        cin >> n >> m >> s >> d;

        s--, d--;  // because I would be using 0 based indexing
        for(int i=0; i<n; i++) graph[i].clear(), min_dist[i] = 1e9;

        int a, b, w;
        for(int i=0; i<m; i++){
            cin >> a >> b >> w;

            a--, b--;  // because I would be using 0 based indexing
            if(graph[a].count(b) == 0) graph[a][b] = w;
            else if (graph[a][b] > w) graph[a][b] = w;
        }

        cout << bellFord(n, m, s, d) << endl;
    }

    return 0;
}