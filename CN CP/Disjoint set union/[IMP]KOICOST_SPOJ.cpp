/*
Problem name from spoj : KOICOST - Cost
https://www.spoj.com/problems/KOICOST/
*/

// Time complexity of both approaches = mlogm which comes from sorting the m edges in decreasing order
// about approach is written in CN CP notes of DSU chapter
#include<bits/stdc++.h>

using namespace std;

const int MAX = (int)(1e5+5);

class DSU{
	int parent[MAX];
	int subtree[MAX];
public:
	DSU(int n){
		for(int i=0; i<=n; i++){
			parent[i] = i;
			subtree[i] = 1;
		}
	}

	int findRoot(int u){
		while(u != parent[u]){
			parent[u] = parent[parent[u]];
			u = parent[u];
		}

		return u;
	}

	void combine(int u, int v){
		int ru = findRoot(u);
		int rv = findRoot(v);

		if(ru == rv) return;
		else if(subtree[ru] > subtree[rv]){
			parent[rv] = ru;
			subtree[ru] += subtree[rv];
		} else{
			parent[ru] = rv;
			subtree[rv] += subtree[ru];
		}
	}

	long long getSize(int u){
		int ru = findRoot(u);
		return subtree[ru] * 1ll;
	}

};

int main(){
	const long long mod = 1000000000;
	int n, m;
	cin>>n>>m;
	pair<int, pair<int, int>> edges[m];  // first weight, then the pair containing the edge nodes

	for(int i=0; i<m; i++){
		int u, v, w;
		cin>>u>>v>>w;
		edges[i] = {w, {u, v}};
	}

	sort(edges, edges + m); // sorting in ascending order according to weight of edges, will start from the edge at the end

	long long csum[m]; // prefix-sum/cumulative-sum of the edge weights only after they were sorted
	csum[0] = edges[0].first;
	for(int i=1; i<m; i++){
		csum[i] = csum[i-1] + 1ll * edges[i].first;
	}

	DSU dsu = DSU(n);

	long long ans = 0;

	for(int i=m-1; i>=0; i--){
		int u = edges[i].second.first;
		int v = edges[i].second.second;

		int ru = dsu.findRoot(u);
		int rv = dsu.findRoot(v);

		if(ru == rv){ // that means after removing current edge, no nodes are getting disconnected, so no need of counting here
			continue;
		}

		long long current = ((dsu.getSize(ru) * dsu.getSize(rv)) % mod) * csum[i]; // calculating the answer total for the nodes from the 2 sets 
		current %= mod;
		ans += current;
		ans %= mod;
		
        dsu.combine(u, v); // keep combining 
	}

	cout<<ans;

	return 0;
}



// lastest code by me
#include<bits/stdc++.h>
using namespace std;

#define ll long long
ll const mod = 1e9;

struct Edge{
	int u;
	int v;
	int w;
};

class cmp{
	public:
	bool operator() (Edge &a, Edge &b) {
		return a.w < b.w;
	}
};

class DSU{
	public:
	vector<int> parent;
	vector<int> size;
	ll connectedNodesPairs;

	DSU(int n) {
		for(int i=0; i<=n; i++) parent.push_back(i), size.push_back(0);
		connectedNodesPairs = 0;
	}

	int root(int u) {
		while(parent[u] != u) {
			parent[u] = parent[parent[u]];
			u = parent[u];
		}

		return u;
	}

	void combine(int u, int v) {
		int ru = root(u);
		int rv = root(v);

		if(ru == rv) return;

		ll su = size[u], sv = size[v];

		// subtract the number of pairs that were there in the 2 disconnected components of ru and rv
		connectedNodesPairs = (connectedNodesPairs - (((su * (su-1)) / 2) % mod)) % mod;
		connectedNodesPairs = (connectedNodesPairs - (((sv * (sv-1)) / 2) % mod)) % mod;

		if(su > sv) {
			parent[rv] = ru;
			su = size[u] = size[u] + size[v];
		}
		else {
			parent[ru] = rv;
			su = size[v] = size[v] + size[u];
		}

		// now finally add the number of pairs that are there in the final combined component
		connectedNodesPairs = (connectedNodesPairs + (((su * (su-1)) / 2) % mod)) % mod;
	}
};

int main() {
	int v, e;
	// Hard-coded input values
	v = 6;
	e = 7;
	
	priority_queue<Edge, vector<Edge>, cmp> maxpq;
	
	// Hard-coded edge values
	Edge edges[] = {
		{1, 2, 10},
		{2, 3, 2},
		{4, 3, 5},
		{6, 3, 15},
		{3, 5, 4},
		{4, 5, 3},
		{2, 6, 6}
	};
	
	for(int i = 0; i < e; i++) {
		maxpq.push(edges[i]);
	}

	DSU dsu = DSU(v);

	int ans = 0;
	while(!maxpq.empty()) {
		Edge e = maxpq.top();
		maxpq.pop();

		dsu.combine(e.u, e.v);
		ans = (ans + ((dsu.connectedNodesPairs * e.w) % mod)) % mod;
	}

	cout << ans;

	return 0;
}