/*
You are given the list of costs of pants in an array “pants”, shirts in an array “shirts”, shoes in an array “shoes”, and skirts in an array “skirts”. You are also given a budget amount ‘X’ to spend. You want to buy exactly 1 item from each list. Your task is to determine the total number of possible combinations that you can buy, given that the total amount of your purchase does not exceed your budget amount.
Input Format:
The first line of input contains an integer ‘T’ denoting the number of test cases to run. Then the test case follows.

The first line of each test case contains five integers ‘P’, ‘Q’, ‘R’, ‘S’ and, ‘X’. Denotes the number of pants, shirts, shoes, skirts, and budget amount respectively.

The second line of each test case contains exactly ‘P’ integers. Denotes the cost of each pant.

The third line of each test case contains exactly ‘Q’ integers. Denotes the cost of each shirt.

The fourth line of each test case contains exactly ‘R’ integers. Denotes the cost of each shoe.

The fifth line of each test case contains exactly ‘S’ integers. Denotes the cost of each skirt.
Output Format :
For each test case, return an integer that represents the total number of combinations to buy that are valid according to the above conditions.

Output for each test case will be printed in a new line. 
Note:
You do not need to print anything; it has already been taken care of. Just implement the given functions.
Constraints:
1 <= T <= 100
1 <= ‘P’, ‘Q’, ‘R’, ‘S’  <= 10
1 <= ‘X’ <= 10^9
1 <= pants[i], shirts[i], shoes[i], skirts[i] <= 10^9

Time Limit: 1 sec
Sample Input 1:
2
2 2 1 1 10
3 4
2 4
2
1
3 2 2 1 15
3 4 6
1 4
2 3
8
Sample Output 1:
3
3
Explanation For Sample Output 1:
In the first case, 
There are a total of four ways to buy. Only valid purchases are [3, 2, 2, 1], [3, 4, 2, 1], [4, 2, 2, 1] because the sum of the cost of each item of each valid purchase is less than the budget amount.

In the second case, 
There are a total of four ways to buy. Only valid purchases are [3, 1, 2, 8], [3, 1, 3, 8], [4, 1, 2, 8] because the sum of the cost of each item of each valid purchase is less than the budget amount.
Sample Input 2 :
2
3 3 3 3 14
3 4 7
1 3 5 
6 8 10
1 2 3
4 3 2 2 20
2 8 7 10
5 5 5
6 3
4 5
Sample Output 2:
12
21
*/



// APPROACH : here we would have to calculate all possible prices and see which of them fall below budget => T = O(pants*shirts*shoes*skirts)
// To reduce this time complexity we can divide the 4 commodities into half
// That is, calculate all prices for pantsAndShirts and sort them
// Then for each combined price value of shoesAndSkirts , binary search for the smaller values in the sorted pantsAndShirts array
// smaller values means = smaller than (Budget - shoesAndSkirts)
// Time complexity reduces to = O((pa*sh)log(pa*sh) + (sho*sk)log(pa*sh))

#include<bits/stdc++.h>

int shoppingOptions(vector<int>& pants, vector<int>& shirts, vector<int>& shoes, vector<int>& skirts, int budget)
{
	vector<int> pantsShirts;
	for(int i=0; i<pants.size(); i++){
		for(int j=0; j<shirts.size(); j++){
			pantsShirts.push_back(pants[i] + shirts[j]);
		}
	}

	sort(pantsShirts.begin(), pantsShirts.end());

	int ans = 0;

	for(int i=0; i<shoes.size(); i++){
		for(int j=0; j<skirts.size(); j++){
			int find = budget - (shoes[i] + skirts[j]);
			auto it = upper_bound(pantsShirts.begin(), pantsShirts.end(), find);
			ans += distance(pantsShirts.begin(), it);
		}
	}

	return ans;
}
