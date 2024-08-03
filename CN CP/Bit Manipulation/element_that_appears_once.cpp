/*
You are given an arbitrary array ‘arr’ consisting of N non-negative integers, where every element appears thrice except one. You need to find the element that appears only once.
Input Format:
The first line of the input contains a single integer T, representing the number of test cases. 

The first line of each test case consists of a single integer N, representing the number of elements in the given array.

The second line of each test case contains N space-separated integers, denoting the elements of the array.
Output Format:
For each test case, print a single integer representing the element that appears only once in the array.
Note:
You do not need to print anything. It has already been taken care of. Just implement the given function. 
Constraints:
1 <= T <= 100
4 <= N <= 10^4
0 <= arr[i] < 10^9
Time Limit: 1sec
Follow Up:
Try to solve this problem in O(N) time and O(1) space complexity.
Sample Input 1:
1
4
1 2 1 1
Sample Output 1:
2
Explanation For Sample Input 1:
Clearly, the 2 appears once while 1 appears thrice. Hence, 2 is the output.
Sample Input 2:
1
7 
1 3 3 3 1 1 4
Sample Output 2:
4
*/



// Approach : count how many times set bit appears at a particular bit position accross all the elements. and do this for all the bit positions (0 to 30)
// all the elements appear thrice, so freq table would have multiples of 3 in most positions
// but only at positions where our unique element has a set bit, only in those positions freq table would have 3x + 1 sort of numbers
int elementThatAppearsOnce(vector<int> arr) {
	int ans = 0;

	int freq[32] = {0};

	for(int i=0; i<arr.size(); i++){
		for(int j = 0; j<31; j++)   // because we dont need to consider the 32nd bit, since we are dealing only with non negative numbers
		{
			if((arr[i] & (1<<j)) != 0) freq[j]++;
		}
	}

	for(int i=0; i<31; i++){
		if(freq[i] % 3 == 1) ans = ans | (1<<i);
	}

	return ans;
}