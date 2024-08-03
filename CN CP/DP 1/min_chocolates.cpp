/*
Minimum Number of Chocolates

Miss. Noor Rashid is a teacher. She wants to give some chocolates to the students in her class. All the students sit in a line, 
and each of them has a score according to performance. Noor wants to give at least one chocolate to each student. She distributes 
chocolates to them such that If two students sit next to each other, then the one with the higher score must get more chocolates. 
Miss. Noor wants to save money, so she wants to minimize the total number of chocolates.

Note :
When two students have an equal score, they are allowed to have a different number of chocolates. 

Input Format:
The first line of the input contains an integer value of N. It denotes the total number of students in Noor's class.

The second line of the input contains N integer values denoting the score of each of the students. A single space will separate them.
Output Format:
Print the minimum number of chocolates Noor must give.

Constraints
1 <= N <= 10^5
1 <= score <= 10^5

Time Limit: 1 sec

Sample Input 1 :
4
1 4 4 6
Sample Output 1 :
6
Explanation:
One of the ways in which the chocolates can be distributed, such Noor has to give minimum number of chocolates, are: The first student can be given one chocolate, second student can be given two chocolates, third student can be one chocolate and fourth can be given two chocolates.  
Sample Input 2 :
3
8 7 5
Sample Output 2 :
6
*/




#include<bits/stdc++.h>
using namespace std;

int getMin(int *arr, int n)
{
	vector<int> dp(n, 0);

	// first we will traverse from left to right and at each i we will calculate the minimum chocolates for i+1
	int minChocForNext = 1;  // since for i=0, min chocolates = 1;
	for(int i=0; i<n; i++){
		dp[i] = minChocForNext;
		if((i+1 < n) && (arr[i+1] > arr[i])) minChocForNext++;
		else if((i+1 < n) && (arr[i+1] <= arr[i])) minChocForNext = 1;
	}

	// now traverse from right to left and we know that the chocolates for the right indexes have been confirmed and now judge the chocs for curr index
	// and we just need to check one case , which was not handelled in first traversal => arr[i] > arr[i+1]
	for(int i=n-2; i>=0; i--){
		if((arr[i] > arr[i+1]) && (dp[i] <= dp[i+1])){
			dp[i] = dp[i+1] + 1;
		}
	}

	int total = 0;
	for(auto i : dp) total += i;

	return total;
}