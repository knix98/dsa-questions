/*
Is it a tree ?  -> can look at this problem by going in :  Tree 1 -> Assignment -> Is it a tree ?
https://classroom.codingninjas.com/app/classroom/me/22205/content/575409/offering/8882659/problem/835
*/



// IMP : for being a tree => just 2 things to check
// 1. edges = n-1
// 2. there should be no cycle in the graph
// if both the above conditions satisfied, then this graph is a tree

#include <bits/stdc++.h>
using namespace std;

int findRoot(vector<int> &parent, int u){
    while(u != parent[u]){
        parent[u] = parent[parent[u]];
        u = parent[u];
    }

    return u;
}

void combine(vector<int> &parent, vector<int> &setSize, int ru, int rv){
    // comine the smaller set to larger set
    // or make the parent as the one with the larger setSize
    if(setSize[ru] > setSize[rv]){
        parent[rv] = ru;
        setSize[ru] += setSize[rv];
    }
    else{
        parent[ru] = rv;
        setSize[rv] += setSize[ru];
    }
}

int main() {
	int n, m;
	cin >> n >> m;
	
	if(m != n-1) cout << "NO";
	else{
		string answer = "YES";

		// DSU algorithm
		vector<int> parent(n+1, 0);   // using 1 based indexing for edges 1 to n
		for(int i=1; i<=n; i++) parent[i] = i;

		vector<int> setSize(n+1, 1);

		for(int i=0; i<m; i++){
			int u, v;
			cin >> u >> v;

			// first find the roots of u and v
			int ru = findRoot(parent, u);
			int rv = findRoot(parent, v);

			if(ru == rv){
				// means u and v already belonged to the same set, and now we are asking to make an edge btw them
				// or, a path from u to v already existed, and now we are making a direct edge between them
				// so its sure that a cycle is going to form here
				answer = "NO";
			}
			else{
				combine(parent, setSize, ru, rv);
			}
		}

		cout << answer;
	}
}