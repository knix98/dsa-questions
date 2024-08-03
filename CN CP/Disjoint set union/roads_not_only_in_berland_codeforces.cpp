/*
    D. Roads not only in Berland => can read problem statement from codeforces
*/


// basically in this we will use DSU to build the graph edge-by-edge. and when we encounter an edge which is forming a cycle in the graph,
// then question says to possibly use this useless edge to form a connection between 2 unconnected graphs(if they are present)
// so we will also maintain a "roots" vector in which initially every node would be marked as a root in itself, but as we go on building the DSU
// we will keep unmarking some nodes as non-root nodes
#include <bits/stdc++.h>
using namespace std;

class DSU {
    vector<int> parent;
    vector<int> setSize;
    int n;

    public :
    DSU(int n){
        this->n = n;

        parent = vector<int>(n+1, 0);
        for(int i=1; i<=n; i++) parent[i] = i;

        setSize = vector<int>(n+1, 1);
    }

    int findRoot(int u){
        while(parent[u] != u){
            parent[u] = parent[parent[u]];
            u = parent[u];
        }

        return u;
    }

    // this func would combine the roots ru and rv and then return the combined root 
    int combine(int ru, int rv) {
        if(setSize[ru] < setSize[rv]){
            parent[ru] = rv;
            setSize[rv] += setSize[ru];
            return rv;
        }
        else{
            parent[rv] = ru;
            setSize[ru] += setSize[rv];
            return ru;
        }
    }
};

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> edges;
    for(int i=0; i<n-1; i++){
        vector<int> v(2);
        cin >> v[0] >> v[1];
        edges.push_back(v);
    }

    DSU dsu = DSU(n);

    vector<int> roots(n+1, 1);  // for identifying which node is a root of some connected component
    roots[0] = 0;

    vector<pair<int,int>> deleteEdges;  // for storing the edges which are forming cycles

    for(int i=0; i<n-1; i++){
        int u = edges[i][0];
        int v = edges[i][1];

        int ru = dsu.findRoot(u);
        int rv = dsu.findRoot(v);

        if(ru != rv) {
            int combinedRoot = dsu.combine(ru, rv);

            // mark the combinedRoot as a root, and unmark the other root (ru or rv) as non-root
            roots[combinedRoot] = 1;

            if(combinedRoot != rv) roots[rv] = 0;
            else roots[ru] = 0;
        }
        else{
            pair<int,int> p(u, v);
            deleteEdges.push_back(p);
        }
    }

    cout << deleteEdges.size() << endl;
    if(deleteEdges.size() > 0){
        vector<int> ROOTS;  // store all the various different roots in this
        for(int i=0; i<n+1; i++){
            if(roots[i] > 0){
                ROOTS.push_back(i);
            }
        }

        // suppose roots are : [1, 5, 7] => 3 unconnected graphs
        // then using the deleteEdges present with you , form 2 connections =>  connect 1 to 5, connect 5 to 7
        int rootIndex = 1;
        for(auto edge : deleteEdges){
            cout << edge.first << " " << edge.second << " " << ROOTS[rootIndex-1] << " " << ROOTS[rootIndex] << endl;
            rootIndex++;
        }
    }
}