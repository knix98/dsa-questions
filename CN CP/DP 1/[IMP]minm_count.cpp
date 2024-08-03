/*
Minimum Count

Given an integer N, find and return the count of minimum numbers required to represent N as a sum of squares.
That is, if N is 4, then we can represent it as : {1^2 + 1^2 + 1^2 + 1^2} and {2^2}. The output will be 1, as 1 is the minimum count of numbers required to represent N as sum of squares.
Input format :
The first and the only line of input contains an integer value, 'N'.
 Output format :
Print the minimum count of numbers required.
Constraints :
0 <= n <= 10 ^ 4

Time Limit: 1 sec
Sample Input 1 :
12
Sample Output 1 :
3
Explanation of Sample Output 1 :
12 can be represented as : 
A) (1^1) + (1^1) + (1^1) + (1^1) + (1^1) + (1^1) + (1^1) + (1^1) + (1^1) + (1^1) + (1^1) + (1^1)

B) (1^1) + (1^1) + (1^1) + (1^1) + (1^1) + (1^1) + (1^1) + (1^1)  + (2 ^ 2)

C) (1^1) + (1^1) + (1^1) + (1^1) + (2 ^ 2) + (2 ^ 2)

D) (2 ^ 2) + (2 ^ 2) + (2 ^ 2)

As we can see, the output should be 3.
Sample Input 2 :
9
Sample Output 2 :
1
*/



// latest code by me ... the second code is earlier code
int minCount(int n)
{
	int dp[n+1];
	dp[0] = 0;

	for(int i=1; i<=n; i++){
		int k = floor(sqrt(i));

		dp[i] = INT_MAX;
		for( ; k>=1; k--){
			dp[i] = min(dp[i], 1 + dp[i - (k*k)]);
		}
	}

	return dp[n];
}




#include<bits/stdc++.h>
using namespace std;

int minCount(int n)
{
	// we will start from the sqrt(n)
	// so if floor(sqrt(n)) == 5, then our array will be [1,2,3,4,5]
	int m = floor(sqrt(n));
	vector<int> next(n+1, -1);  // this array would store => for each value => the min squares required for forming the value, considering only the current part of the array
								// if next[i] == -1 => it means that its not possible to make value == i , considering only the elems in the current part of the array
	next[m*m] = 1;
	next[0] = 0;

	for(int i=m-1; i>=1; i--){
		vector<int> curr(n+1, 0);

		for(int j=0; j<=n; j++){
			// acc. to recursion, we say that either we include the current i , or exclude the current i from the sum of squares
			int includedAns = -1;
			int includedValue = j - (i*i);
			if(includedValue >= 0) includedAns = curr[includedValue] > -1 ? curr[includedValue] + 1 : -1;

			int excludedValue = j;
			int excludedAns = next[excludedValue];

			// if both of includedAns or excludedAns are +ve then answer would be min of them
			if(min(includedAns, excludedAns) > -1) curr[j] = min(includedAns, excludedAns);
			else curr[j] = max(includedAns, excludedAns); 
		}

		next = curr;
	}

	return next[n];
}