/*
https://codeforces.com/problemset/problem/25/C
*/

#include<bits/stdc++.h>
using namespace std;

/*
3
0 4 5
4 0 9
5 9 0
2
2 3 8
1 2 1
*/

// intuition written in CN CP hand notes of graph-2 chapter
int main() {
    int n;
    cin >> n;

    vector<vector<int>> dp(n+1, vector<int>(n+1));
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin >> dp[i][j];
        }
    }

    vector<long long> ans;
    int q; // queries
    cin >> q;
    int a, b, w;
    while(q--){
        cin >> a >> b >> w;

        long long sum = 0;
        for(int i=1; i<=n; i++){
            for(int j=i+1; j<=n; j++){
                dp[i][j] = min({dp[j][i], dp[i][a] + w + dp[b][j], dp[i][b] + w + dp[a][j]});
                dp[j][i] = dp[i][j];
                sum += dp[i][j];
            }
        }

        ans.push_back(sum);
    }

    for(auto i : ans) cout << i << " ";

    return 0;
}