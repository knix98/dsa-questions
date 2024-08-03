/*
https://www.hackerearth.com/practice/algorithms/dynamic-programming/bit-masking/practice-problems/algorithm/sherlock-and-coprime-subset/
*/



#include<bits/stdc++.h>
#define int long long

using namespace std;

const int M = 15;
int dp[51][1<<M];

signed main() {
	freopen("input.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	int t;
	cin>>t;
	while(t--) {
		int n;
		cin>>n;
		int a[n+1];
		for(int i=1; i<=n; i++) cin>>a[i];

		vector<int> primes;
		for(int i=2; i<51; i++) {
			bool isDivisible = false;
			for(int j=2; (j*j)<=i; j++) {
				if((i%j) == 0){
					isDivisible = true;
					break;
				}
			}
			if(!isDivisible) primes.push_back(i);
		}

		int pf_mask[n+1];
		for(int i=1; i<=n; i++) {
			int mask = 0;
			for(int j = 0; j<primes.size(); j++) {
				if((a[i] % primes[j]) == 0) {
					mask |= (1<<j);
				}
			}
			pf_mask[i] = mask;
		}

		int m = primes.size();

		
		for(int i=0; i<=n; i++) {
			for(int j=0; j<(1<<m); j++) {
				dp[i][j] = 0;
			}
		}

		for(int i=1; i<=n; i++){
			for(int mask=0; mask<(1<<m); mask++) {
				if(pf_mask[i] & mask) {
					dp[i][mask] = dp[i-1][mask];
				} else{
					dp[i][mask] = max(1 + dp[i-1][mask | pf_mask[i]], dp[i-1][mask]);
				}
			}
		}

		cout<<dp[n][0]<<"\n";

	}

	return 0;
}