#include<bits/stdc++.h>

using namespace std;

const int N = (int)(1e5+5);  // assuming that the maximum node number would not exceed 1e5

vector<int> tree[N];  // adjacency list


void dfs(int s, int p){  // s = current node, p = parent of current node
	cout<<s<<" ";
	for(int v: tree[s]){
		if(v != p){
			dfs(v, s);
		}
	}
}

void bfs(int root){
	queue<int> q;
	q.push(root);
	vector<bool> visited(N, false);

	visited[root] = true;

	cout<<"Running BFS---\n";

	while(!q.empty()){
		int u = q.front();
		cout<<u<<" ";
		q.pop();

		for(int v: tree[u]){
			if(!visited[v]){
				visited[v] = true;
				q.push(v);
			}
		}
	}
	cout<<endl;

}

int main(){
	int n;
	cin>>n;  // input number of nodes

	for(int i=0; i<n-1; i++){  // taking input of the n-1 edges of the tree and preparing the adjacency list for this tree
		int u, v;
		cin>>u>>v;
		tree[u].push_back(v);
		tree[v].push_back(u);
	}

	cout<<"Running DFS---\n";
	dfs(1, 0);  // pass root and parent of root (which is nobody, hence passing 0 as parent of root)(since nodes are numbered from 1 to n)

	cout<<endl;
 
	bfs(1); // pass the root node

	return 0;
}