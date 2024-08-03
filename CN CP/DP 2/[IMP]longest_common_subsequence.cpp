/*
https://classroom.codingninjas.com/app/classroom/me/22205/content/575428/offering/8883015/problem/859?leftPanelTabValue=PROBLEM
*/



#include<bits/stdc++.h>

int lcs(string s, string t)
{
	int n = s.size();
	int m = t.size();

	vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
	// dp[0][j] = dp[i][0] = 0, since that means one of them is 0 length string, so lcs = 0

	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			if(s[i-1] == t[j-1]) dp[i][j] = 1 + dp[i-1][j-1]; // if first letters of both strings are equal
			else dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
		}
	}

	return dp[n][m];
}