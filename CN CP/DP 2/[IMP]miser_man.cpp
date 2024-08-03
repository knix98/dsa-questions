/*
https://classroom.codingninjas.com/app/classroom/me/22205/content/575428/offering/8883035/problem/1716?leftPanelTabValue=PROBLEM
*/



#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> dp(n, vector<int>(m));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> dp[i][j];
        }
    }

    vector<int> next(m), curr(m);
    for(int j=0; j<m; j++) next[j] = dp[n-1][j];

    for(int i=n-2; i>=0; i--){
        for(int j=0; j<m; j++){
            curr[j] = next[j];
            if(j>=1) curr[j] = min(curr[j], next[j-1]);
            if(j<m-1) curr[j] = min(curr[j], next[j+1]);

            curr[j] += dp[i][j];
        }

        next = curr;
    }

    int ans = INT_MAX;
    for(int i : curr) ans = min(ans, i);

    cout << ans;

    return 0;
}