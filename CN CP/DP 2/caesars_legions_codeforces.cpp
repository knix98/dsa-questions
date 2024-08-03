/*
https://codeforces.com/problemset/problem/118/D
*/


// time and space both : O(n1*n2*(k1+k2))
#include<bits/stdc++.h>
using namespace std;

const int mod = 1e8;

int main()
{
    int n1, n2, k1, k2;
    cin >> n1 >> n2 >> k1 >> k2;

    int dp[n1+1][n2+1][k1+k2+1];
    // dp[i][j][k] = i n1 and j n2 remaining with us. and if(k<=k1) means currently there are k n1 type people standing towards the end of queue (where we have to put a new person now)
    // and if(k1 < k <= (k1+k2)) means currently there are (k-k1) n2 type people standing towards the end of queue (where we have to put a new person now)

    // base case 
    for(int i=0; i<=(k1+k2); i++) dp[0][0][i] = 1;

    for(int i=0; i<=n1; i++){
        for(int j=(i==0 ? 1 : 0); j<=n2; j++){
            for(int k=0; k<=(k1+k2); k++){
                dp[i][j][k] = 0;
                if(k == k1){
                    // means we cant keep n1 any more so we have to keep n2 only
                    if(j > 0) dp[i][j][k] = (dp[i][j][k] + dp[i][j-1][k1+1]) % mod;
                }
                else if(k == k1+k2){
                    // means we cant keep n2 any more so we have to keep n1 only
                    if(i > 0) dp[i][j][k] = (dp[i][j][k] + dp[i-1][j][1]) % mod;
                }
                else if(k < k1){
                    // means the last person is of type n1 or k==0
                    if(i > 0) dp[i][j][k] = (dp[i][j][k] + dp[i-1][j][k+1]) % mod;
                    if(j > 0) dp[i][j][k] = (dp[i][j][k] + dp[i][j-1][k1+1]) % mod;
                }
                else{  // k > k1
                    // means the last person is of type n2
                    if(i > 0) dp[i][j][k] = (dp[i][j][k] + dp[i-1][j][1]) % mod;
                    if(j > 0) dp[i][j][k] = (dp[i][j][k] + dp[i][j-1][k+1]) % mod;
                }
            }
        }
    }

    // Debugging...
    // for(int i=0; i<=n1; i++){
    //     for(int j=(i==0 ? 1 : 0); j<=n2; j++){
    //         cout << "(" << i << "," << j << ")" << " => ";
    //         for(int k=0; k<=(k1+k2); k++){
    //             cout << dp[i][j][k] << " ";
    //         }
    //         cout << endl;
    //     }
    // }

    cout << dp[n1][n2][0];
}
