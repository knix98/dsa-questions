/*
    E - Knapsack 2
    link = https://atcoder.jp/contests/dp/tasks/dp_e
*/



#include<bits/stdc++.h>

using namespace std;

// since here the normal DP approach for knapsack which has F(n, w) is TLE, since w can be as large as 1e9
// so we decided to choose F(n, v) since n<=100 and v<=1000 (so max v possible = n*v = 100*1000 (i.e when all items are taken) = 100000) 
// So F(n,v) = minm weight required to make a value of v with n items to choose from
// F(n, v) = MIN(F(n-1, v-V[n]) + W[n], F(n-1, v)) , i.e 2 cases => if nth weight is taken, if nth weight not taken
// Base cases => F(n, 0) = 0;    F(0, v) = MAX, (MAX = some impossible value)

int main(){
	// freopen("input.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);

	int n, W;
	cin>>n>>W;
	int w[n+1], v[n+1];  // since we would be doing a DP approach in which we will be considering n items remaining, so better to have 1-based indexing 
                         // in our DP array, because index=0 would mean 0 items
	for(int i=1; i<=n; i++){
		cin>>w[i]>>v[i];
	}

	const long long MAX = (long long)(1e9+7);

    // calculating max V possible for our DP by adding all the v given to us
	int V = 0;
	for(int i=1; i<=n; i++) V += v[i];

	long long dp[n+1][V+1];

    // base cases
	for(int i=0; i<=n; i++) dp[i][0] = 0;
	for(int i=1; i<V; i++) dp[0][i] = MAX;

	for(int i=1; i<=n; i++){
		for(int j=1; j<V; j++){
			if(v[i] <= j){  // if v-V[n] is positive then only first case would be considered
				dp[i][j] = min(dp[i-1][j], dp[i-1][j-v[i]] + w[i]);
			} else{
				dp[i][j] = dp[i-1][j];
			}
		}
	}

	int maxV = 0;  // ans would be the maxV that can be made with all n items, but the min weight required should be less than W
	for(int i=V-1; i>=0; i--){
		if(dp[n][i] <= W){
			maxV = i;
			break;
		}
	}

	cout<<maxV<<"\n";

}