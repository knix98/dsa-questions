/*
Coin Change (Infinite Supply)

You are given an infinite supply supply of coins of each of denominations D = {D0, D1, D2, D3, ...... Dn-1}. 
You need to figure out the total number of ways W, in which you can make change for Value V using coins of denominations D.

Note :
Return 0, if change isn't possible.

Input Format :
Line 1 : Integer n i.e. total number of denominations
Line 2 : n integers i.e. n denomination values
Line 3 : Value V
Output Format :
Line 1 :  Number of ways i.e. W

Constraints :
1<=n<=10
1<=V<=500

Sample Input 1 :
3
1 2 3
4
Sample Output :
4
Sample Output Explanation :
Number of ways are - 4, i.e. (1,1,1,1), (1,1, 2), (1, 3) and (2, 2).
*/




#include<bits/stdc++.h>

int countWaysToMakeChange(int denominations[], int numDenominations, int value){
// starting our DP from nth index (out of bounds), assuming that an imaginary coin is present here. 
// And since its imaginary, only 1 possibility exists for this coin : we will not take this coin
// hence for this imaginary case , only dp[0] = number of ways required to make 0 value with coins array starting from this index = 1 (only 1 way = dont take any coin)
  vector<int> nextArray(value + 1, 0);
  nextArray[0] = 1;

  for(int i=numDenominations-1; i>=0; i--){
    vector<int> currArray(value+1, 0);
    int den = denominations[i];
    
    for(int j=0; j<=value; j++){
      // we have to do addition of 2 : ways in which coins array starts from current index + ways in which coins array starts from next index
      int includedValue = j - den;
      if(includedValue >= 0) currArray[j] += currArray[includedValue];

      int excludedValue = j;
      currArray[j] += nextArray[j];
    }

    nextArray = currArray;
  }

  return nextArray[value];
}
