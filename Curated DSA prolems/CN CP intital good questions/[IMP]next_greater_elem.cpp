/*
https://classroom.codingninjas.com/app/classroom/me/22205/content/575390/offering/8882300/problem/346?leftPanelTabValue=SUBMISSION

Given an array, print the Next Greater Element (NGE) for every element. The Next greater Element for an element x, is the first greater element on right side of x in the array. Elements for which no greater element exist, consider next greater element as -1.

Input format :

Line 1 : Size of input array

Line 2 : Array elements (separated by space)

Constraints:
Time Limit: 1 second
Size of input array lies in the range: [1, 1000000]
Constraints:
Time Limit: 1 second
Size of input array lies in the range: [1, 1000000]
Sample Input
5
3  8  1  2  0
Sample Output
8 -1  2 -1 -1
*/


// Method 1 : using stack : Time = space = O(n)
vector<int> nextGreaterElement(vector<int> input) {
	// Write your code here
	int n = input.size();
	vector<int> ans(n);
	stack<int> s; // this stack would be in increasing order when reading from left to right
	for(int i=n - 1; i >= 0; i--){
		while(!s.empty() && s.top() <= input[i]){
			s.pop();
		}

		if(s.empty()) ans[i] = -1;
		else ans[i] = s.top();

		s.push(input[i]);
	}

	return ans;
}


// Method 2 : using upper_bound : for an index i you can find next greater elem by applying upper_bound on [i+1, n)
// Time : O(nlogn), space : O(1)