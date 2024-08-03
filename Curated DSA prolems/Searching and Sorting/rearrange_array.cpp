/*
https://classroom.codingninjas.com/app/classroom/me/11692/content/204217/offering/2650137/problem/13854?leftPanelTabValue=PROBLEM

Ninja has given you two arrays ‘ARR’ and ‘BRR’ of size ‘N’ and ‘M’ respectively. He asked you to rearrange the elements of ‘ARR’ in such a way that the relative order among the elements will be the same as the elements of array ‘BRR’. It is given that elements of ‘BRR’ are non-repeating. If an element is not present in ‘BRR’, then you need to append them in the last in sorted order.

For example

Consider the arrays as ARR = { 9, 5, 8, 4, 6, 5 } and BRR = { 8, 4, 5 }
The output for the above example  is { 8, 4, 5, 5, 6, 9 }.
Detailed explanation ( Input/output format, Notes, Images )
Constraints:
1 <= T <= 5
1 <= N <= 10 ^ 5
1 <= M <= 10 ^ 5
(-10 ^ 9) <= ARR[i] , BRR[i]  <= (10 ^ 9) 

Time limit: 1 sec
Sample Input 1:
2
6 3
9 5 8 4 6 5 
8 4 5
4 4
1 8 1 6 
1 9 6 7 
Sample Output 1:
8 4 5 5 6 9
1 1 6 8
Explanation:
For test case 1:
As 8 comes first in BRR, so we first add all occurrences of 8 in ARR, in our resultant array RES. Now, RES={8} and ARR={9,5,4,6,5}.
After 8, 4 comes in BRR, so we add all occurrences of 4 that are in ARR, in the RES array. Now, RES={8,4} and ARR={9,5,6,5}.
After 4, 5 comes in BRR, so we add all occurrences of 5 that are in ARR, in the RES array. Now, RES={8,4,5,5} and ARR={9,6}.
Now, after processing all the elements of BRR, we will add the remaining elements of ARR in sorted order, in our RES array.
So the final RES is {8,4,5,5,6,9}.

For test case 2: 
As 1 comes first in BRR, so we first add all occurrences of 1 in ARR, in our resultant array RES. Now, RES={1,1} and ARR={8,6}.
After 1, 9 comes in BRR, so we add all occurrences of 9 that are in ARR, in the RES array, but 9 is not present in ARR, so RES remains the same. Now, RES={1,1} and ARR={8,6}.
After 9, 6 comes in BRR, so we add all occurrences of 6 that are in ARR, in the RES array. Now, RES={1,1,6} and ARR={8}.
After 9, 7 comes in BRR, so we add all occurrences of 7 in ARR, in our RES, but 7 is not present in ARR, so RES remains the same. Now, RES={1,1,6} and ARR={8}.
Now, after processing all the elements of BRR, we will add the remaining elements of ARR in sorted order, in our RES array.
So the final RES is {1,1,6,8}.
Sample Input 2:
2
3 4
1 2 8  
1 2 8 3
3 2
1 2 3 
2 2 
Sample Output 2:
1 2 8 
2 2 1 3 
*/



// Time : O(nlogn + mlogn), space : O(n)
#include<bits/stdc++.h>
using namespace std;

vector<int> relativeSorting(vector<int> &arr, vector<int> &brr, int n, int m)
{
	map<int,int> fq;  // using map because we want the elems that are not present in brr, in sorted order in the end
	for(int i : arr) fq[i]++;  // store frequencies of arr elems

	vector<int> ans;
	for(int i : brr){
		if(fq[i]){  // if this elem was present in arr as well...
			while(fq[i]){
				ans.push_back(i);
				fq[i]--;
			}
			fq.erase(i);  // remove this elem now from fq, so that in the end only the non brr elems are left in the fq in sorted order
		}
	}

	for(auto i : fq){
		while(i.second){
			ans.push_back(i.first);
			i.second--;
		}
	}

	return ans;
}