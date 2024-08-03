#include <bits/stdc++.h>
using namespace std;

int bfs(vector<vector<int>> &tree, int n, int k, vector<int> &degree){  // k is the number of rounds of cutting we have to do
    vector<int> leaves;
    for(int i=1; i<n+1; i++) if(degree[i] <= 1) leaves.push_back(i);

    while(k--){
        vector<int> newLeaves;

        for(int leaf : leaves){
            for(int node : tree[leaf]){
                // if(degree.find(node) != degree.end()) degree[node]--;
                degree[node]--;
                if(degree[node] == 1) newLeaves.push_back(node);
            }
        }

        n -= leaves.size();
        leaves = newLeaves;
    }

    return n;
}

int main() {
    int t;
    cin >> t;

    vector<int> ans;
    while(t--){
        int n, k;
        cin >> n >> k;

        vector<vector<int>> tree(n+1, vector<int>(0)); // constructing a adjacency list for a tree with edges from 1 to n
        vector<int> degree(n+1, 0);
        for(int i=0; i<n-1; i++){  // n-1 edges
            int u, v;
            cin >> u >> v;

            tree[u].push_back(v);
            tree[v].push_back(u);
            degree[u]++;
            degree[v]++;
        }

        if(k >= n) cout << 0 << endl;
        else cout << bfs(tree, n, k, degree) << endl;
    }

    return 0;
}