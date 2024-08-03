/*
https://classroom.codingninjas.com/app/classroom/me/22205/content/575395/offering/8882396/problem/594?leftPanelTabValue=PROBLEM

For a given integer array/list 'ARR' of size 'N' containing all distinct values, find the total number of 'Inversions' that may exist.

An inversion is defined for a pair of integers in the array/list when the following two conditions are met.

A pair ('ARR[i]', 'ARR[j]') is said to be an inversion when:

1. 'ARR[i] > 'ARR[j]' 
2. 'i' < 'j'

Where 'i' and 'j' denote the indices ranging from [0, 'N').
Detailed explanation ( Input/output format, Notes, Images )
Constraints :
1 <= N <= 10^5 
1 <= ARR[i] <= 10^9

Where 'ARR[i]' denotes the array element at 'ith' index.

Time Limit: 1 sec
Sample Input 1 :
3
3 2 1
Sample Output 1 :
3
Explanation of Sample Output 1:
We have a total of 3 pairs which satisfy the condition of inversion. (3, 2), (2, 1) and (3, 1).
Sample Input 2 :
5
2 5 1 3 4
Sample Output 2 :
4
Explanation of Sample Output 1:
We have a total of 4 pairs which satisfy the condition of inversion. (2, 1), (5, 1), (5, 3) and (5, 4).
*/




#include <bits/stdc++.h> 
#define ll long long

ll helper(ll *arr, int n, int st, int en){
    if(st >= en){
        return 0;
    }

    int mid = (st+en)/2;

    ll leftAns = helper(arr, n, st, mid);
    ll rightAns = helper(arr, n, mid+1, en);

    int tempSize = en - st + 1;
    ll temp[tempSize] = {0};

    ll ans = 0;

    int i=st, j=mid+1, t = 0;
    while(i <= mid || j <= en){
        if(j > en || (i <= mid && arr[i] < arr[j])){
            temp[t] = arr[i];
            ans += (j - (mid+1)); 
            i++;
        }
        else{
            temp[t] = arr[j];
            j++;
        }

        t++;
    }

    for(int k = 0, l = st; k < tempSize; k++, l++){
        arr[l] = temp[k];
    }

    return ans + leftAns + rightAns;
}

long long getInversions(long long *arr, int n){
    return helper(arr, n, 0, n-1);
}