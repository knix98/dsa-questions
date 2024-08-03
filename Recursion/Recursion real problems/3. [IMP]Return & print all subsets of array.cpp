/*
Given an integer array (of length n), find and return all the subsets of input array.
Subsets are of length varying from 0 to n, that contain elements of the array. 
But the order of elements should remain same as in the input array.
Note : The order of subsets are not important.

Sample Input:
3
15 20 12
Sample Output:
[] (this just represents an empty array, don't worry about the square brackets)
12 
20 
20 12 
15 
15 12 
15 20 
15 20 12
*/

// 1. Return all subsets of array
/***
You need to save all the subsets in the given 2D output array. And return the number of subsets(i.e. number of rows filled in output) from the given function.

In ith row of output array, 1st column contains length of the ith subset. And from 1st column actual subset follows.
For eg. Input : {1, 2}, then output should contain 
	{{0}, 		// Length of this subset is 0
	{1, 2},		// Length of this subset is 1
	{1, 1},		// Length of this subset is also 1
	{2, 1, 2}}	// Length of this subset is 2

Don’t print the subsets, just save them in output.
***/
#include<iostream>
using namespace std;

int subset(int input[], int n, int output[][20]) {
    // Write your code here
	if(n==0){
        output[0][0] = 0;
        return 1;
    }
    
	int smallOutputSize = subset(input, n-1, output);
    for(int i=0, j=smallOutputSize; i<smallOutputSize; i++,j++){
        for(int k=0; k<=output[i][0]; k++){
            output[j][k]=output[i][k];
        }
        output[j][0]++;
        output[j][output[i][0] + 1] = input[n-1];
    }
    
    return smallOutputSize*2;
}



// 2. Print all the subsets of array
void helper(int input[], int n, int print[], int printSize){
    if(n==0){
        for(int i=0; i<printSize; i++){
            cout << print[i] << " ";
        }
        cout << endl;
        return;
    }
    
    helper(input+1, n-1, print, printSize);
    print[printSize] = input[0];
    helper(input+1, n-1, print, printSize+1);
}

void printSubsetsOfArray(int input[], int size) {
    int print[size];
	helper(input, size, print, 0);
}