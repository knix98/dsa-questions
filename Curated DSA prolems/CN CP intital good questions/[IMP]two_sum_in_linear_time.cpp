/*
https://classroom.codingninjas.com/app/classroom/me/22205/content/575390/offering/8882314/problem/8164?leftPanelTabValue=PROBLEM

You are given an array of integers 'ARR' of length 'N' and an integer Target. Your task is to return all pairs of elements such that they add up to Target.

Note:

We cannot use the element at a given index twice.
Follow Up:

Try to do this problem in O(N) time complexity. 
Detailed explanation ( Input/output format, Notes, Images )
Constraints:
1 ≤ n ≤ 105
1 ≤ arr[i] ≤ 105

Where 'T' denotes the number of test cases, 'N' represents the size of the array, 'TARGET' represents the sum required, and 'ARR[i]' represents array elements.

Time Limit: 1 sec.
Sample Input 1 :
2
4 9
2 7 11 13
5 1
1 -1 -1 2 2
Sample Output 1:
2 7
-1 2
-1 2
Explanation for Sample 1:
For the first test case, we can see that the sum of  2 and 7 is equal to 9 and it is the only valid pair.

For the second test case, there are two valid pairs (-1,2) and (-1,2), which add up to 1.
Sample Input 2 :
1
4 16
2 7 11 13
Sample Output 2 :
-1 -1
*/




#include<unordered_map>

vector<pair<int,int>> twoSum(vector<int>& arr, int target, int n)
{
    vector<pair<int, int>> ans;
	unordered_map<int, int> mp;

    for(int i=0; i<n; i++){
        if(mp[target - arr[i]] > 0) {
            mp[target - arr[i]]--;

            pair<int, int> p(arr[i], target - arr[i]);
            ans.push_back(p);
        }
        else{
            mp[arr[i]]++;
        }
    }

    if(ans.empty()){
        pair<int, int> p(-1, -1);
        ans.push_back(p);
    }

    return ans;
}