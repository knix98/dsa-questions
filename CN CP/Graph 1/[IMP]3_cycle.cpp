/*
https://classroom.codingninjas.com/app/classroom/me/22205/content/575410/offering/8882687/problem/7887
*/


// doing it using adjacency matrix approach in O(n^3) solution
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;

    vector<int> l1(m);
    for(int i=0; i<m; i++){
        cin >> l1[i];
    }

    vector<int> l2(m);
    for(int i=0; i<m; i++){
        cin >> l2[i];
    }

    // building up adjacency matrix of size n*n
    // even though the edges have been given based on 1 based indexing , we will store them as 0 based indexing
    // that is, we will consider nodes numbered from 0 to n-1 and solve accordingly
    vector<vector<int>> graph(n, vector<int>(n, 0));
    int u, v;
    for(int i=0; i<m; i++){
        u = l1[i];
        v = l2[i];

        graph[u-1][v-1] = 1;
        graph[v-1][u-1] = 1;
    }

    int threeCycles = 0;
    
    for(int node = 0; node < n; node++){
        for(int i = node+1; i<n; i++){
            if(graph[node][i]){
                for(int j=i+1; j<n; j++){
                    if(graph[node][j] && graph[i][j]) threeCycles++;
                }
            }
        }
    }

    cout << threeCycles;

    return 0;
}