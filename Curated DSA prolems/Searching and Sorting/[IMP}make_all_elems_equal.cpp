/*
https://classroom.codingninjas.com/app/classroom/me/11692/content/204217/offering/2650137/problem/14252?leftPanelTabValue=SUBMISSION

It is the test day at the DOJO, and the Ultimate Ninja Ankush has given you an array and asked to make all elements equal with minimum cost possible. Find the minimum cost to ace the exam ultimate ninja Ankush gave you.

More Formally, you are given an array of integers of size ‘N’. You have to make the elements of the array equal, and the cost of changing the element ‘x’ to ‘y’ is abs(x -y). Your task is to find the minimum cost to make the elements of the array equal.

You are supposed to tell the minimum cost to pass your test.

For example:
Consider ARR = [3, 4, 5] now suppose if we want to change every element value to 4, then the cost of changing 3 to 4 is |3 - 4| which is 1, and the cost of changing 5 to 4 is |5 - 4| which is 1, so the total cost is 1 + 1 = 2. The value 2 is the minimum cost to make all values in the array equal. Hence, the answer is 2.
Detailed explanation ( Input/output format, Notes, Images )
Constraints:
1 <= 'T' <= 5
1 <= 'N' <= 10 ^ 5
1 <= 'ARR[i]' <= 10 ^ 8

Time limit: 1 sec.
Sample Input 1:
2
3
1 8 19
4
2 3 4 5
Sample Output 1:
18
4
Explanation:
In test case 1
We can change all element’s value to 8 with cost |1-8| + |19 - 8| = 18. The value 18 is the minimum cost to make all values in the array equal. Hence, the answer is 18.

In test case 2 
We can change all element’s value to 3 with cost |2 - 3| + |3 - 4| + |3 - 5| = 4. The value 4 is the minimum cost to make all values in the array equal. Hence, the answer is 4. 
Sample Input 2:
1
3
1 100 101
4
2 17 26 11
Sample Output 2:
100
30
*/



// Time : O(nlogn), space : O(1)
// APPROACH : calculate cost with each elem and find minimum from that
// first sort arr => 2, 11, 17, 26
// now cost at 2 = 48
// for cost at 11 => diff = 11-2=9 . We have to subtract this diff 3 times(number of elems to right of 2) from cost at 2 and add this diff to prevcost 1 times(number of elems to left of 11)
#include<algorithm>

int findMinimumCost(vector<int> &arr, int n) {
    sort(arr.begin(), arr.end());

    // first calculate total cost from first elem
    int prevCost = 0;
    for(int i=1; i<n; i++) prevCost += (arr[i] - arr[0]);

    int minCost = prevCost;
    for(int i=1; i<n; i++){
        int diff = arr[i] - arr[i-1];
        int currCost = prevCost - (diff * (n-i)) + (diff * i);
        if(minCost > currCost) minCost = currCost;
        prevCost = currCost;
    }

    return minCost;
}




// int findMinimumCost(vector<int> &arr, int n)
// {
//     sort(arr.begin(), arr.end());
//     int x = arr[n/2];
//     int ans = 0;

//     for(int i=0; i<n; i++){
//         ans += arr[i] > x ? arr[i] - x : x - arr[i];
//     }

//     return ans;
// }