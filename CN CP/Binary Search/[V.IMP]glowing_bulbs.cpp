/*
Glowing Bulbs

There are an infinite number of electric bulbs. Each bulb is assigned a unique integer starting from 1. There are ‘N’ switches also and each switch is labeled by a unique prime number. If a switch labeled with prime integer ‘p’ is turned ON, then all the bulbs having a number that is multiple of ‘p’ will start glowing. For example, if we turn ON the switch labelled 2, then all the bulbs having numbers 2, 4, 6, 8, 10, ... i.e all bulbs with numbers as multiples of 2 will start glowing.
You are given an array/list ‘LABELS’ consisting of ‘N’ unique prime integers representing the label of the switches and an integer ‘K’. Your task is to find the integer assigned to Kth glowing bulb from the start when all these ‘N’ switches are turned ON.
Note :
1. Some bulbs can glow by multiple switches and some are not glowed by any switch.
2. If any of the switches that can glow a bulb is turned ‘ON’, then the corresponding bulb will glow.
Example :
Consider 3 switches with labels [3, 5,  7] and we need to find the 5th glowing bulb from the start after turning these 3 switches ON.
We can see that bulbs numbered  3, 6, 9, 15, 18 …  will glow if the switch having label 3 is turned ON.
The bulbs numbered 5, 10, 15, 20 … will glow if the switch having label 5 is turned ON.
The bulbs numbered 7, 14, 21, 28 … will glow if the switch having label 7 is turned ON.
It implies that bulbs numbered 3, 5, 6, 7, 9, 10, 14, 15, 18, 20, 21… will glow when these three switches are turned ON.
The 5th glowing bulb from start is assigned integer 9. Thus, we should return 9.
Input Format :
The first line of input contains an integer ‘T’ denoting the number of test cases. Then ‘T’ test cases follow.

The first line of each test case consists of two space-separated integers ‘N’ and ‘K’ respectively.

The second line of each test case consists of ‘N’ space-separated prime integers representing array/list ‘LABELS’.
Output Format :
For each test case, print the integer assigned to the Kth glowing bulb when all the given switches in ‘LABELS’ are turned ON.

Print the output of each test case in a separate line.
Note :
You do not need to print anything, it has already been taken care of. Just implement the given function.
Constraints :
1 <= T <= 50
1 <= N <= 10
1 <= K <= 10^12
1 < LABELS[i] < 30

Where 'LABELS[i]' is a prime integer and all integers in array/list ‘LABELS’ are distinct.

Time limit: 1 sec
Sample Input 1 :
2
1 5
2
3 5
3 5 7
Sample Output 1 :
10
9
Explanation Of Sample Input 1 :
Test case 1:
Here, there is only one switch having label 2. When this switch is turned On, then the bulbs having numbers which are multiples of 2 i.e, 2, 4, 6, 8, 10, 12, 14, 16…  will start glowing. Clearly, the 5th such bulb from start is assigned integer 10.

Test case 2:
See the problem statement for an explanation.
Sample Input 2 :
2
2 6
2 3
2 6
7 11
Sample Output 2 :
9
28
*/




// This problem was in mock chalenge 3.
// Approach and explanation and new things I learned for this solution is written in mock chalenge 3 CN CP notes 
#include<bits/stdc++.h>
using namespace std;

#define ll long long

ll position(vector<int> &labels, ll value) {
	int n = labels.size();
	int maxValue = (1<<n) - 1;

	ll ansPosition = 0;

	for(int i=1; i<=maxValue; i++) {
		ll LCM = 1;
		int subsetElementsCount = 0;

		for(int j=0; j<n; j++){
			if(i & (1<<j)) {
				LCM *= labels[j];
				subsetElementsCount++;
			}
		}

		if((subsetElementsCount % 2) == 0) ansPosition -= (value/LCM);
		else ansPosition += (value/LCM);
	}

	return ansPosition;
}

long long findKthGlowingBulb(vector<int> &labels, long long k) {
	sort(labels.begin(), labels.end());

	ll minValue = labels[0];
	ll maxValue = (ll)(1)<<62;

	ll ans;
	while(minValue <= maxValue) {
		ll midValue = (minValue + maxValue) / 2;

		ll midValuePosition = position(labels, midValue);
		// if(midValuePosition == k) {
		// 	// check if midValue is actually a multiple of somebody or not
		// 	bool flag = false;
		// 	for(int i=0; i<labels.size(); i++) {
		// 		if((midValue % labels[i]) == 0) {
		// 			flag = true;
		// 			break;
		// 		}
		// 	}

		// 	if(flag) return midValue;
		// 	else{
		// 		maxValue = midValue-1;
		// 	}
		// }
		if (midValuePosition >= k) {
			maxValue = midValue-1;
			if(midValuePosition == k) ans = midValue;
		}
		else minValue = midValue + 1;
	}

	return ans;
}