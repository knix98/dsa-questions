/*
https://classroom.codingninjas.com/app/classroom/me/22205/content/575411/offering/8882722/problem/13698
*/



// here in the question , its given that edge_weights are greater than 0, so we can easily use djikstra here
// but look at the solution code once and see how the case of => "if no edge present then return -1", has been handeled
#include<bits/stdc++.h>

#define ll long long

ll dijkstra(vector<vector<pair<ll, ll>>> &graph, vector<ll> &min_dist, int src, int dest){
    priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> min_pq;

    min_dist[src] = 1;  // keeping distance of source from source as 1 and not 0 because, here multiplication of distances is going to happen
    min_pq.push({1, src});   // {distance from source, node in consideration}

    while(!min_pq.empty()){
        pair<ll,ll> top = min_pq.top();
        min_pq.pop();

        ll node = top.second;
        ll d = top.first;

        if(d > min_dist[node]) continue; // means this node has already been processed earlier and this data is obsolete now

        for(auto neighbour : graph[node]){
            ll nei_node = neighbour.first;
            ll nei_weight = neighbour.second;

            if(d * nei_weight < min_dist[nei_node]){
                min_dist[nei_node] = d * nei_weight;
                min_pq.push({min_dist[nei_node], nei_node});
            }
        }
    }

	return min_dist[dest] < LLONG_MAX ? min_dist[dest] : -1;
}

long long int minEffortsRequired(vector<pair<pair<int, int>, long long int>>&edges, int n, int src, int dest)
{
	if(src == dest) return 0;

	vector<vector<pair<ll, ll>>> graph(n);
	vector<ll> min_dist(n, LLONG_MAX);

	ll a, b, w;
	for(int i=0; i<edges.size(); i++){
		a = edges[i].first.first;
		b = edges[i].first.second;
		w = edges[i].second;

		graph[a].push_back({b, w});
	}

	return dijkstra(graph, min_dist, src, dest);
}