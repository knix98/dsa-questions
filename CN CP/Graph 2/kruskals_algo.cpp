/*
https://classroom.codingninjas.com/app/classroom/me/22205/content/575411/offering/8882692/problem/7911
*/


#include<bits/stdc++.h>
using namespace std;

bool cmp(pair<int, pair<int,int>> &a, pair<int, pair<int,int>> &b){
    return a.first < b.first; 
}

class DSU{
    vector<int> parent;
    vector<int> setSize;
    int maxSetSize = 1;  // denoting the size of set having maximum setSize

    public :
    DSU(int n){
        for(int i=0; i<n; i++){
            parent.push_back(i);
            setSize.push_back(1);
        }
    }

    int findRoot(int u){
        int temp = u;
        while(parent[temp] != temp){
            temp = parent[parent[temp]];
        }

        parent[u] = temp;
        return temp;
    }

    bool combine(int u, int v){
        int ru = findRoot(u);
        int rv = findRoot(v);

        if(ru == rv) return false;

        int combinedRoot;
        if(setSize[ru] > setSize[rv]){
            parent[rv] = ru;
            setSize[ru] += setSize[rv];
            combinedRoot = ru;
        }
        else {
            parent[ru] = rv;
            setSize[rv] += setSize[ru];
            combinedRoot = rv;
        }

        parent[u] = combinedRoot;
        parent[v] = combinedRoot;

        if(setSize[combinedRoot] > maxSetSize) maxSetSize = setSize[combinedRoot];  // update maxSetSize

        return true;
    }

    int getMaxSetSize() {return maxSetSize;}
};

int main(){
    int t;
    cin >> t;

    while(t--){
        int v, e;
        cin >> v >> e;

        vector<pair<int, pair<int,int>>> edges;
        int edgeWeight, u, x;
        for(int i=0; i<e; i++){
            cin >> u >> x >> edgeWeight;
            edges.push_back({edgeWeight, {u, x}});
        }

        // sort(edges.begin(), edges.end());  // sorting according to edgeWeight        
        sort(edges.begin(), edges.end(), cmp);  // sorting according to edgeWeight

        DSU dsu = DSU(v);

        int mst = 0;
        for(auto edge : edges){
            edgeWeight = edge.first;
            u = edge.second.first;
            x = edge.second.second;

            if(dsu.combine(u, x)) mst += edgeWeight;
            if(dsu.getMaxSetSize() == v) break;  // if maxSetSize has reached all the vertices, that means the tree has been completed
        }

        cout << mst << endl;
    }
    
    return 0;
}