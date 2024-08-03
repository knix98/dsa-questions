/*
Find the good sets!

You are given array a consisting of n distinct integers. A set s of numbers is called good if you can rearrange the elements in such a way that each element divides the next element in the order, i.e. 'si' divides 'si + 1', such that i < |s|, where |s| denotes size of set |s|.
Find out number of distinct good sets that you can create using the values of the array. You can use one value only once in a particular set; ie. a set cannot have duplicate values. Two sets are said to be different from each other if there exists an element in one set, which does not exist in the other.
As the answer could be large, print your answer modulo 10^9 + 7.

Input Format:
First line of the input contains an integer T denoting the number of test cases. T test cases follow.

First line of each test case contains an integer n denoting number of elements in array a.

Next line contains n space separated integers denoting the elements of array a.

Output Format:
For each test case, output a single line containing the corresponding answer.

Constraints
1 ≤ T ≤ 10
1 ≤ n ≤ 10^5
1 ≤ ai ≤ 10^5
All the elements of array a are distinct.

Input
2
2
1 2
3
6 2 3
Output:
3
5
Explanation
Test case 1. There are three sets which are good {1}, {2}, {1, 2}.

Test case 2. There are five sets which are good {6}, {2}, {3}, {6 2}, {6, 3}.
*/




// We will use a DP approach here .
// Starting from the last element
#include<bits/stdc++.h>
using namespace std;

void solve(vector<int> &nums, int &ans){
    int mod = 1e9 + 7;

    for(int i=100000; i>=1; i--){
        if(nums[i] == 0) continue;

        int multiply = 2;
        while(i*multiply <= 100000){ // check which multiples of i exist within range and then number of good sets starting from those multiples would also be counted in sets starting from i
            if(nums[i*multiply] > 0) nums[i] = ( nums[i] + (long long)(nums[i*multiply]) ) % mod;
            multiply++;
        }

        ans = ( ans + (long long)(nums[i]) ) % mod; // finally after getting the number of good sets for current i, add it to the final ans
    }
}

int main(){
    int t;
    cin >> t;

    vector<int> answers;

    while(t--){
        int n;
        cin >> n;

        vector<int> nums(100001, 0);
        for(int i=0; i<n; i++){
            int temp;
            cin >> temp;
            nums[temp] = 1;   // 1 signifies , that this index i is one of the num, and every num always has one good set , containing only 1 element (itself)
        }

        int ans = 0;
        solve(nums, ans);

        answers.push_back(ans);
    }

    for(auto i : answers) cout << i << endl;
    
    return 0;
}