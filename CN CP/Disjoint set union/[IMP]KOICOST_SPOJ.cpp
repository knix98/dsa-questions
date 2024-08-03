/*
Problem name from spoj : KOICOST - Cost
*/


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