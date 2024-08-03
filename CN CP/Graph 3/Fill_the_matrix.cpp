/*
https://classroom.codingninjas.com/app/classroom/me/22205/content/575426/offering/8882988/problem/7975?leftPanelTabValue=PROBLEM
*/



#include<bits/stdc++.h>
using namespace std;

class DSU {
    vector<int> parent;
    vector<int> setSize;

    public:
    DSU(int n){
        for(int i=0; i<=n; i++){   // 1 based indexing from 1 to n
            parent.push_back(i);
            setSize.push_back(1);
        }
    }

    int findRoot(int u){
        while(parent[u] != u){
            parent[u] = parent[parent[u]];
            u = parent[u];
        }

        return u;
    }

    void combine(int u, int v){
        int ru = findRoot(u);
        int rv = findRoot(v);
        
        int combinedRoot = ru;

        if(rv != ru){
            if(setSize[rv] > setSize[ru]){
                parent[ru] = rv;
                setSize[rv] += setSize[ru];
                combinedRoot = rv;
            }
            else{
                parent[rv] = ru;
                setSize[ru] += setSize[rv];
                combinedRoot = ru;
            }
        }

        parent[ru] = combinedRoot;
        parent[rv] = combinedRoot;
    }
};

bool bipartite(int node, vector<vector<int>> &g, vector<int> &nodeColor) {
    for(int child : g[node]) {
        if(nodeColor[child] != -1){
            // means this child is visited
            if(nodeColor[child] == nodeColor[node]) return false;
        }
        else{
            nodeColor[child] = nodeColor[node] ^ 1;
            bool childAns = bipartite(child, g, nodeColor);
            if(!childAns) return false;
        }
    }

    return true;
}

string solve(){
    int n, q;
    cin >> n >> q;

    DSU dsu = DSU(n);
    vector<vector<int>> board(n+1, vector<int>(n+1, -1));
    vector<vector<int>> oneQueries;

    int x, y, v;
    for(int i=0; i<q; i++){
        cin >> x >> y >> v;
        if((x == y) && (v == 1)) return "no";
        if((board[x][y] != -1) && (board[x][y] != v)) return "no";
        if((board[y][x] != -1) && (board[y][x] != v)) return "no";

        board[x][y] = board[y][x] = v;

        if(v == 0) dsu.combine(x, y);
        if(v == 1) oneQueries.push_back({x, y});
    }

    vector<vector<int>> g(n+1, vector<int>(0));
    for(auto q : oneQueries){
        int p1 = dsu.findRoot(q[0]);
        int p2 = dsu.findRoot(q[1]);

        // make edge between p1 and p2
        g[p1].push_back(p2);
        g[p2].push_back(p1);
    }

    vector<int> nodeColor(n+1, -1);
    for(int i=1; i<=n; i++){
        if((nodeColor[i] == -1) && (dsu.findRoot(i) == i)){
            nodeColor[i] = 0;
            if(!bipartite(i, g, nodeColor)) return "no";
        }
    }

    return "yes";
}

int main(){
    int t;
    cin >> t;

    while(t--){
        cout << solve() << endl;
    }
    
    return 0;
}









