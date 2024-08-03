/*
https://classroom.codingninjas.com/app/classroom/me/22205/content/575411/offering/8882714/problem/7991
*/


#include<bits/stdc++.h>
using namespace std;

#define ll long long

// can read about approach in CN CP pdf notes
void floyd_warshall(vector<vector<ll>> &dp, int n){
    for(int i = 1; i<=n; i++){
        for(int a = 1; a<=n; a++){
            for(int b = 1; b<=n; b++){
                dp[a][b] = min(dp[a][b], dp[a][i] + dp[i][b]);  // I have not taken care of whether if dp[a][i] + dp[i][b] = 2e9 , because
                                                                // 2e9 is within range of int and hence would not give unexpected results
            }
        }
    }
}

int main(){
    int t, n, m, q;
    cin >> t;

    while(t--){
        cin >> n >> m;

        // we will used 1 based indexing for nodes this time (1 to n)
        vector<vector<ll>> graph(n+1, vector<ll>(n+1, 1e9));
        for(int i=1; i<=n; i++) graph[i][i] = 0;

        int a, b, w;
        for(int i=0; i<m; i++){
            cin >> a >> b >> w;

            if(graph[a][b] > w) graph[a][b] = w, graph[b][a] = w;
        }

        floyd_warshall(graph, n);

        cin >> q;
        while(q--){
            cin >> a >> b;
            cout << graph[a][b] << endl;
        }
    }

    return 0;
}