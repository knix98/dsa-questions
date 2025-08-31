/*
https://leetcode.com/problems/new-21-game/description/

APPROACH : 
dp[i] = probability of reaching less than n points when I have i points currently
dp[i] = (1/maxPts) ( dp[i+1] + dp[i+2] + .... dp[i+t] )
where (1/maxPts) = prob of picking any 1 card , and t = min(i + maxPts, n)
since we need prefSum of dp array instead of individual dp[i] values, so in dp[i] we will store prefSum value
i.e, dp[i] = ( dp[i] + dp[i+1] + ... dp[n] ), n = end index of our dp array
*/

class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        double p = (double)1/maxPts;

		vector<double> dp(n+2, 1); // for i = k to n , dp[i] = 1;
		dp[n+1] = 0;
		for(int i=n-1; i>=k; i--) dp[i] += dp[i+1];

		for(int i=k-1; i>=0; i--) {
			int t = min(i + maxPts, n);
			dp[i] = p * (dp[i+1] - dp[t+1]);
			dp[i] += dp[i+1];
		}

		return dp[0] - dp[1];
    }
};