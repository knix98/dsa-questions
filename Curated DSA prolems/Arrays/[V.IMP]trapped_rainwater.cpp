/*
https://classroom.codingninjas.com/app/classroom/me/11692/content/204216/offering/2653314/problem/13701?leftPanelTabValue=PROBLEM

Ninja was feeling bored today. He went for a walk and thought of a problem. You are given 'N' bars where each bar has an integral length denoted by an array ARR[i]. 
It represents an elevation map wherein ARR[i] denotes the elevation of the i-th bar. Your task is to write a function that returns the total amount of rainwater that can be trapped in these elevations.

Note :
The width of each bar is the same and is equal to 1.
Detailed explanation ( Input/output format, Notes, Images )
Constraints :
1 <= T <= 10
0 <= N <= 10^4
0 <= ARR[i] <= 10^5

Time Limit: 1 sec
Sample Input 1 :
2
3
1 2 3
3
3 2 1
Sample Output 1 :
0
0
Sample Input 2 :
2
1
100
3
5 1 5
Sample Output 2 :
0
4
Sample Input 3 :
1
5
90 70 20 80 50
Sample Output 3 :
70
Example:
Refer to the image for better comprehension:
*/



#include<bits/stdc++.h>
using namespace std;

// METHOD 1 : time : O(n), space : O(n)
// APPROACH : at any i we should know what is the leftmax height and rightmax height uptill this i
// then water at this i = min(leftmax, rightmax) - arr[i]
long getTrappedWater(long *arr, int n){
    if(n <= 2) return 0;

    // precalculate leftmax and rightmax at every i
    vector<long> leftmax(n), rightmax(n); 
    leftmax[0] = arr[0];
    rightmax[n-1] = arr[n-1];
    for(int i=1, j=n-2; i<n; i++, j--){
        leftmax[i] = max(leftmax[i-1], arr[i]);
        rightmax[j] = max(rightmax[j+1], arr[j]);
    }

    long ans = 0;
    for(int i=0; i<n; i++){
        ans += (min(leftmax[i], rightmax[i]) - arr[i]);
    }

    return ans;
}


// Two Pointer approach
// METHOD 2 : time : O(n), space : O(1)
// can refer to takeuforward (striver) video
long getTrappedWater(long *arr, int n) {
    int i = 0, j = n-1;
    long leftmax = 0, rightmax = 0;

    long ans = 0;
    while(i<=j){
        if(arr[i] <= arr[j]){
            if(arr[i] >= leftmax){
                leftmax = arr[i];
            }
            else {
                // we are confidently able to use only leftmax for calculation of water at i, instead of min(leftmax, rightmax) because we know from the top "if condition" that,
                // i is only moving left if arr[i] <= arr[j]...so at any current i we can be sure that there would be a j on right such that arr[j] >= leftmax
                // so basically we can say that, if arr[j] is such that all the arr[i]s left to it are smaller than arr[j] => then j would always be fixed at that
                // position and i would keep on moving right, till a arr[i] comes such that it is greater than arr[j] and moves j leftwards
                ans += (leftmax - arr[i]);  
            }
            i++;
        }
        else{
            if(arr[j] >= rightmax){
                rightmax = arr[j];
            }
            else {
                // similar logic as above here also
                ans += (rightmax - arr[j]);
            }
            j--;
        }
    }

    return ans;
}