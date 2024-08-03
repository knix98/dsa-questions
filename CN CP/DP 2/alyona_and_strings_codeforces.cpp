/*
https://codeforces.com/problemset/problem/682/D
*/


#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, m, k;
    cin >> n >> m >> k;

    string s, t;
    cin >> s >> t;

    int dp[n+1][m+1][2][k+1];  // this 2 is for 2 cases : 0 = a string making is not continuing from before, 1 = string making is continuing from before

    // base cases => if(n==0 || m==0) return 0;
    for(int i=0; i<=m; i++){
        for(int j=0; j<=k; j++) dp[0][i][0][j] = dp[0][i][1][j] = 0;
    }
    for(int i=0; i<=n; i++){
        for(int j=0; j<=k; j++) dp[i][0][0][j] = dp[i][0][1][j] = 0;
    }

    // base case if k==0, means we dont have to build any string so length_max = 0
    for(int i=0; i<=n; i++){
        for(int j=0; j<=m; j++) dp[i][j][0][0] = dp[i][j][1][0] = 0;
    }

    for(int a=1; a<=n; a++){
        for(int b=1; b<=m; b++){
            for(int c=0; c<2; c++){
                for(int d=1; d<=k; d++){
                    if(c==0){
                        // means there is no string making in progress from before
                        if(s[a-1] == t[b-1]){
                            // case 1 : we ignore these first letters
                            dp[a][b][c][d] = max(dp[a-1][b][0][d], dp[a][b-1][0][d]); // NOTE : we would do d-1 only when we decide to end a continuing string
                                                                                      // here no string is continuing from before , so need to do d-1
                            // case 2 : we take these first letters
                            dp[a][b][c][d] = max(dp[a][b][c][d], 1 + dp[a-1][b-1][1][d]);
                        }
                        else{
                            // only 1 case possible : we have to ignore the unequal first letters
                            dp[a][b][c][d] = max(dp[a-1][b][0][d], dp[a][b-1][0][d]);
                        }
                    }
                    else{ // c==1
                        // means there is string making in progress from before
                        if(s[a-1] == t[b-1]){
                            // case 1 : we ignore these first letters and end the previously continuing string
                            dp[a][b][c][d] = max(dp[a-1][b][0][d-1], dp[a][b-1][0][d-1]);   // NOTE : // here string is continuing from before , so need to do d-1 , whenever we decide to end a previously continuing string

                            // case 2 : we take these first letters
                            // case 2a : we take these first letters in the continued string from before 
                            dp[a][b][c][d] = max(dp[a][b][c][d], 1 + dp[a-1][b-1][1][d]);

                            // case 2b : we take these first letters in a new string and end the previously continuing string
                            if(d > 0) dp[a][b][c][d] = max(dp[a][b][c][d], 1 + dp[a-1][b-1][1][d-1]);
                        }
                        else{
                            // only 1 case possible : we have to ignore the unequal first letters and end the previously continuing string
                            dp[a][b][c][d] = max(dp[a-1][b][0][d-1], dp[a][b-1][0][d-1]);
                        }
                    }
                }
            }
        }
    }

    // for(int i=0; i<=n; i++){
    //     for(int j=0; j<=m; j++){
    //         cout << "(" << i << "," << j << ")" << " => " << endl;
    //         for(int d = 0; d<=k; d++) cout << dp[i][j][0][d] << " ";
    //         cout << endl;
    //         for(int d = 0; d<=k; d++) cout << dp[i][j][1][d] << " ";
    //         cout << endl;
    //     }
    // }

    // cout << max(dp[n][m][0][k], dp[n][m][1][k]);
    cout << dp[n][m][0][k];
}
