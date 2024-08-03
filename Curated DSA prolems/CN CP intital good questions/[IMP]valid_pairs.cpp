/*
https://classroom.codingninjas.com/app/classroom/me/22205/content/575390/offering/8882312/problem/2305?leftPanelTabValue=PROBLEM

Given an array of integers and numbers k and m, write a function that returns true if given array can be divided into pairs such that the sum of every pair gives remainder m when divided by k.

Constraints :
 1 <= N <= 10^4
 1 <= M < K <= 10^2

Sample Input :
4
2 1 5 7
9
3
Sample Output :
true
Explanation :
Pairs will be (2,1) and (5,7)
*/



// time : O(n) , space : O(k) , because we will be storing remainders of each elem after dividing by k , so they would always be in range [0, k-1]
#include<unordered_map>

bool CheckSumPairs(int ar[], int n, int k, int m) {
    // THEORY : suppose 2 values a and b, then (a%k) + (b%k) == m or k+m
    // because (a%k) + (b%k) would always be < 2k , so only 2 valid values are possible => m or k+m
    // APPROACH : store the remainders of each element, when divided by k, in a map 
    unordered_map<int, int> mp;

    for(int i=0; i<n; i++){
        int rem = ar[i] % k;  // calculating remainder

        if(rem <= m){
            // if rem <= m , then check if map contains a value which == m-rem
            if(mp[m-rem] > 0) mp[m - rem]--; // that means a pair is made, so remove the m-rem found from the map
            else{
                mp[rem]++;  // means no pair element found for current element till now , so include the rem of current element in the map
            }
        }
        else{ // similar calculations to above case, just difference is => this time we need to find a value in map which == (k+m)-rem
            if(mp[(k+m)-rem] > 0) mp[(k+m) - rem]--;
            else{
                mp[rem]++;
            }
        }
    }

    for(int i=0; i<n; i++){ // now just iterate over the map and check whether a rem value coudn't form a pair => then return false
        // this way of iterating over a map, using array indices is also useful instead of using iterator
        if(mp[ar[i] % k] > 0) return false;
    }

    return true;
}