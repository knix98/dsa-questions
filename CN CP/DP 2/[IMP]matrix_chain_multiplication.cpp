/*
https://classroom.codingninjas.com/app/classroom/me/22205/content/575428/offering/8883024/problem/860?leftPanelTabValue=PROBLEM
*/



#include<bits/stdc++.h>
using namespace std;

int matrixChainMultiplication(int* arr, int n) {
    n = n+1; // because if arr = [10, 15, 20, 25], n = 3 in input, so making it n = 4
    vector<vector<int>> dp(n, vector<int>(n, 0));
    // dp[i][j] = suppose if i=0, j=2 then dp[0][2] means minm calculations required when considering matrices in [10, 15, 20]

    for(int i = n-3; i>=0; i--){  // starting from i=n-3, because we need to have atleast 3 numbers for atleast 2 matrices multiplication
        for(int j=i+2; j<n; j++){  // j should always be atleast 2 distance away from i (since, we need to have atleast 3 numbers for atleast 2 matrices multiplication)
            int localAns = INT_MAX;
            for(int k=i+1; k<j; k++){
                int check = dp[i][k] + dp[k][j] + (arr[i]*arr[k]*arr[j]);
                localAns = min(localAns, check);
            }
            dp[i][j] = localAns;
        }
    }

    return dp[0][n-1];
}