/*
https://classroom.codingninjas.com/app/classroom/me/22205/content/575411/offering/8882705/problem/7912
*/



#include<bits/stdc++.h>
using namespace std;

int v, e;
int a, b, w;
vector<vector<pair<int,int>>> graph(1001);
vector<int> min_dist(1001);

// the time complexity of this djikstra algo is ElogV (remember, because its derived by some manipulative maths, and not straight forward)
// where E = edges in graph, and V = vertices in graph
void dijkstra(){
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> min_pq;

    min_dist[0] = 0;
    min_pq.push({0, 0});   // {distance from source, node in consideration}

    while(!min_pq.empty()){
        pair<int,int> top = min_pq.top();
        min_pq.pop();

        int node = top.second;  // current node 
        int d = top.first;   // current node's distance from source calculated in this case        

        if(d > min_dist[node]) continue; // means this node has already been processed earlier and this data is obsolete now

        for(auto neighbour : graph[node]){  // if we come here means, d == min_dist[node]
            int nei_node = neighbour.first;
            int nei_weight = neighbour.second;

            if(d + nei_weight < min_dist[nei_node]){  // means we would have to update min_dist[nei_node]
                min_dist[nei_node] = d + nei_weight;
                min_pq.push({min_dist[nei_node], nei_node});  // if any node's min_dist updated, then push it into pq
            }
        }
    }
}

int main(){
    int t;
    cin >> t;

    while(t--){
        cin >> v >> e;

        for(int i=0; i<v; i++) graph[i].clear(), min_dist[i] = INT_MAX;

        for(int i=0; i<e; i++){
            cin >> a >> b >> w;

            graph[a].push_back({b, w});
            graph[b].push_back({a, w});
        }

        dijkstra();

        for(int i=0; i<v; i++){
            cout << i << " " << min_dist[i] << endl;
        }
    }

    return 0;
}