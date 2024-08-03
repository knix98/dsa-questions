/*
Given an array A and an integer K, print all subsets of A which sum to K.
Subsets are of length varying from 0 to n, that contain elements of the array. 
But the order of elements should remain same as in the input array.
Note : The order of subsets are not important. Just print them in different lines.

Input:
4
1 -1 3 -3
0

Output:
3 -3
1 -1
1 -1 3 -3
*/

#include<iostream>
using namespace std; 

void helper(int input[], int n, int print[], int prtSize, int k){
    //prtSize = total elements present in the print array
    
    //BASE CASE: when we reach end of array, and k==0, this means all the ints kept in print[] sum upto k, so print them 
    if(n==0 && k==0){
        for(int i=0; i<prtSize; i++){
            cout << print[i] << " ";
        }
        cout << endl;
        return;
    }
    else if(n==0){  //n==0 && k!=0
        return;
    }
    
    //recursion calls after excluding the 1st element of input array
    helper(input+1, n-1, print, prtSize, k);
    
    print[prtSize] = input[0]; //include input[0] in print[] before calling next recursion
    helper(input+1, n-1, print, prtSize+1, k-input[0]);
}

void printSubsetSumToK(int input[], int size, int k) {
    // Write your code here
    int print[size];
    helper(input, size, print, 0, k);
}