/*
Given an array consisting of positive and negative integers, find the length of the longest consecutive subarray whose sum is zero.
*/

// SOLUTION................................
//  Only in questions where in we have to find the longest "consecutive subsequence" summing to 0, we can use this technique
//  Otherwise if we have to find any subset(not necessarilly consecutive) summing to zero, then we have no choice but to examine all the subsets
//  possible using recursion mainly. But this algo wud be O(2^n), because there are 2^n subsets possible in all.

// First APproach : recursive program to find any longest subset(not necessarily continuos) of zero sum............................
/*
#include<algorithm>
int helper(int *arr, int n, int sum){ //recursive funcn whuch returns longest subset length summing to the given sum as funcn argument
    if(n==0){
        return 0;
    }
    else if(n==1){
        if(arr[0] == sum){
            return 1;
        }
        else{
            return 0;
        }
    }

    int bigSum = helper(arr+1, n-1, sum); //getting longest subset from the smaller array only
    int smallSum = helper(arr+1, n-1, sum-arr[0]); //getting subset when arr[0] also included

    if(bigSum == 0 && smallSum == 0){ //if no subsets found in smaller array
        if(sum == arr[0]){
            return 1;
        }
        else{
            return 0;
        }
    }
    else if(bigSum != 0 && smallSum != 0){
        return max(bigSum, smallSum+1);
    }
    else{
        if(bigSum != 0){
            return bigSum;
        }
        else{
            return smallSum+1;
        }
    }
}

int lengthOfLongestSubsetWithZeroSum(int* arr, int n) {
    // Write your code here
    return helper(arr, n, 0);
}
*/

// SECOND APPROACH :
#include <unordered_map>
int lengthOfLongestSubsetWithZeroSum(int *arr, int n)
{
    unordered_map<int, int> sumIndex; // key :sum upto index, value :index of the sum(i.e key)
    int sum = 0;                      // will be used to calculate the sum upto any index
    int ans = 0;                      // ans = length of longest zero sum subset
    sumIndex[0] = -1;                 // index = -1 indicates that no elements from the array are included hence sum upto index -1 is 0

    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (sumIndex.count(sum) == 0)
        { // if this sum not encountered before then include this sum in the map with its index
            sumIndex[sum] = i;
        }
        else // if this sum has been encountered before, then we wud not include the current index at this sum in the map
             // because the map should only contain the index at which a particular sum was first encountered, because
             // then only we wud be able to calculate the length of subsequence with the first encountered index as starting point
        {
            int subsetLength = i - sumIndex[sum]; // sumIndex[sum] :gets the index at which the sum value was encountered the first time
            if (subsetLength > ans)
            {
                ans = subsetLength;
            }
        }
    }

    return ans;
}
