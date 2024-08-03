/*
Painter's Partition Problem

Given an array/list of length ‘N’, where the array/list represents the boards and each element of the given array/list represents the length of each board. Some ‘K’ numbers of painters are available to paint these boards. Consider that each unit of a board takes 1 unit of time to paint.


You are supposed to return the area of the minimum time to get this job done of painting all the ‘N’ boards under a constraint that any painter will only paint the continuous sections of boards.


For example :
In the below figure where array/list elements are {2, 1, 5, 6, 2, 3}.

A painter can paint blocks {5,6} or {1,5,6,2} together but not {2,5,6} or {5,6,3}.
Input format :
The first line contains a single integer ‘T’ denoting the number of test cases.

The first line of each test case contains two integers ‘N’ and ‘K’ denoting the number of elements in the array/list and number of painters available.

The second line contains ‘N’ single space-separated integers denoting the elements of the array/list.
Output format :
For each test case, print the minimum time required to get the job done.
Note :
You do not need to print anything; it has already been taken care of.
Sample Input 1 :
2
4 2
5 5 5 5
4 2
10 20 30 40
Sample Output 1 :
10
60
Explanation For Sample Input 1 :
In the first test case, we can divide the boards into 2 equal-sized partitions, so each painter gets 10 units of the board and the total time taken is 10.


In the second test case, we can divide the first 3 boards for one painter and the last board for the second painter.
Sample Input 2 :
2
2 2
48 90
4 2
1 2 3 4
Sample Output 2 :
90
6
Constraints :
1 <= T <= 5
1 <= N <= 10^4
1 <= K <= N
1 <= ARR[i] <= 10^5

Where ‘T’ is the number of test cases.
'N' is the length of the given array/list (boards).
‘K’ is the number of painters available.
And, ARR[i] denotes the i-th element in the array/list.

Time Limit: 1 sec.
*/




// Explanation written in CN CP notes

#include<bits/stdc++.h>
#define ll long long

int findLargestMinDistance(vector<int> &boards, int k)
{
    int n = boards.size();
    if(k == n){  // if this is case, then obviously, every painter would get 1 board only
        int maxBoard = boards[0];
        for(int i=1; i<n; i++){
            maxBoard = maxBoard > boards[i] ? maxBoard : boards[i];
        }

        return maxBoard;   // answer would be maxBoard in this case
    }

    ll totalArea = 0, maxBoard = 0;
    for(int i=0; i<n; i++) {
        totalArea += boards[i];
        maxBoard = maxBoard > boards[i] ? maxBoard : boards[i];
    }

    ll i = maxBoard, j = totalArea;

    ll ans = totalArea;  // keeping the current answer as maxPossible answer, since we need to find the least possible area value

    while(i <= j){
        ll maxArea = (i+j)/2;

        int id = 0;
        int painters = 0;
        while(id < n){
            ll currArea = 0;
            while(id < n){
                if((currArea + boards[id]) > maxArea) break;
                currArea += boards[id];
                id++;
            }

            painters++;
        }

        if (painters <= k) {
            ans = maxArea;
            j = maxArea - 1;
        }
        else if(painters > k) i = maxArea + 1;
    }

    return (int)(ans);
}