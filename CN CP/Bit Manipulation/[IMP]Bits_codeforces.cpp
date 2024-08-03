/*
                                                                    A. Bits
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
Let's denote as  the number of bits set ('1' bits) in the binary representation of the non-negative integer x.

You are given multiple queries consisting of pairs of integers l and r. For each query, find the x, such that l ≤ x ≤ r, and  is maximum possible. If there are multiple such numbers find the smallest of them.

Input
The first line contains integer n — the number of queries (1 ≤ n ≤ 10000).

Each of the following n lines contain two integers li, ri — the arguments for the corresponding query (0 ≤ li ≤ ri ≤ 1018).

Output
For each query print the answer in a separate line.

Examples
inputCopy
3
1 2
2 4
1 10
outputCopy
1
3
7
Note
The binary representations of numbers from 1 to 10 are listed below:

1 = 1

2 = 10

3 = 11

4 = 100

5 = 101

6 = 110

7 = 111

8 = 1000

9 = 1001

10 = 1010
*/




// Approach : suppose range is [1, 10] or [0001, 1010]
// So we will start increasing the number of set bits in the lowest number from the right side 
// because setting the LSB side bits would increase the overall number by the least amount and hence allow us to set more number of bits in the overall number
// so first => 0011 in the range
// second => 0111 in the range
// third => 1111 goes out of range
// So 0111 is the answer
#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    int t;
	cin >> t;

	vector<ll> ans;
	while(t--){
		ll l, r;
		cin >> l >> r;

		ll currAns = l; // we will start from the lowest number in range
		ll tempForLLRangeShifting = 1;

		for(int i=0; i<63; i++){
			ll check = currAns | (tempForLLRangeShifting<<i); // making set bit at position i
			if(check > r) break;
			currAns = check;
		}

		ans.push_back(currAns);
	}

	for(auto i : ans) cout << i << endl;
}