/*
D. How many trees?
https://codeforces.com/problemset/problem/9/D
*/


/*
Here we would have to do a DP approach. Suppose with n nodes , fix 1 node as root and divide the remaining nodes in left and right subtree (like we do while calculating number of binary trees in catalan approach)
So n nodes can be divided into => 1(root), k, n-1-k ... where k varies from k=0 to n-1
But here its not like we have to get all possible trees with k nodes, but we have to get trees greater than or equal to a given height h
So a DP required where n [0, n] is the rows and h [0, h] are the columns.
And dp[i][j] would mean => trees possible with i nodes and which do not have height lesser than j
So following the catalan approach of fixing 1 node as root => dp[i][j] = (dp[0][j-1] * dp[i-1-0][j-1]) + (dp[1][j-1] * dp[i-1-1][j-1]) + ....
Basically wanting the answers from left and right subtree , but asking their trees should have (height >= j-1)

But this approach of DP will give incorrect results because => when we are saying both the subtrees height should be greater than j-1, then we are not considering
cases where one 1 subtree can have height >= j-1 , and other subtree is allowed to have height < j-1
And if we attempt to somehow count these cases as well => then duplicate cases are getting counted
Therefore in this approach of saying that subtrees height should be >= j-1 we are not in full control of cases

Therefore better DP approach is => dp[i][j] = trees possible with i nodes and which have height lesser than or equal to j
And then doing => dp[i][j] = (dp[0][j-1] * dp[i-1-0][j-1]) + (dp[1][j-1] * dp[i-1-1][j-1]) + ....  
would give us correct results since if we are saying that total tree height <= j , and definitely both the subtree's heights <= j-1, and we are not missing any case
*/
#include<bits/stdc++.h>
using namespace std;

#define ll long long

const int N = 35;
vector<vector<ll>> dp(N+1, vector<ll>(N+1, 0));

void solve(int n, int h) {
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            int nodes = i;
            int maxHeight = j;
            for(int k=0; k<nodes; k++){
                dp[i][j] += (dp[k][maxHeight-1] * dp[nodes-1-k][maxHeight-1]);  // dp[i][j] == dp[nodes][maxHeight]
            }
        }
    }
}

int main(){
    int n, h;
    cin >> n >> h;

    // base case : trees with 0 nodes would always have only 1 way to form a tree whose height is <= any h
    for(int i=0; i<N+1; i++) dp[0][i] = 1;

    solve(n, h);

    // since ans = all trees with (height <= n) - all trees with (height <= h-1) = all trees with (n >= height >= h)
    cout << (dp[n][n] - dp[n][h - 1]) << endl;
    
    return 0;
}