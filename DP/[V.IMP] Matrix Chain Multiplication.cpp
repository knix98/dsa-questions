/*
Given a chain of matrices A1, A2, A3,.....An, you have to figure out the most efficient way to multiply these matrices.
In other words, determine where to place parentheses to minimize the number of multiplications.
You will be given an array p[] of size n + 1. Dimension of matrix Ai is p[i - 1]*p[i].
You need to find minimum number of multiplications needed to multiply the chain.

Input Format:
The first line of input contains an integer, that denotes the value of n.
The following line contains n+1 integers, that denote the value of elements of array p[].

Constraints :
1 <= n <= 100
Time limit: 1 second

Sample Input 1:
3
10 15 20 25
Sample Output 1:
8000
Sample Output Explanation:
There are two ways to multiply the chain - (A1)*(A2*A3) or (A1*A2)*(A3).
If we multiply in order- (A1)*(A2*A3), then number of multiplications required are 11250.
If we multiply in order- (A1*A2)*(A3), then number of multiplications required are 8000.
Thus minimum number of multiplications required are 8000.
*/

// Solution explanation written in DSA revison notes...
#include <climits>
#include <vector>

int matrixChainMultiplication(int *arr, int n)
{
    vector<vector<int>> dp;
    for (int i = 0; i < n + 1; i++)
    {
        vector<int> v;
        for (int j = 0; j < n + 1; j++)
        {
            v.push_back(0);
        }

        dp.push_back(v);
    }

    // for (int st = 0, en = st + 1; en <= n; st++, en++){
    //   dp[st][en] = 0;
    // }

    for (int len = 2; len <= n; len++)
    {
        for (int st = 0, en = st + len; en <= n; st++, en++)
        {
            dp[st][en] = INT_MAX;
            for (int i = st + 1; i <= en - 1; i++)
            {

                int check = dp[st][i] + dp[i][en] + arr[st] * arr[i] * arr[en];

                if (check <= dp[st][en])
                {
                    dp[st][en] = check;
                }
            }
        }
    }

    return dp[0][n];
}


// similar approach as above, but written in a more easier way during competitve course by me and without using len variable
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