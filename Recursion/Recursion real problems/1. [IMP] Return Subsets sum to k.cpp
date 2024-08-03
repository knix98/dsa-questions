/*
Given an array A of size n and an integer K, return all subsets of A which sum to K.
Subsets are of length varying from 0 to n, that contain elements of the array. 
But the order of elements should remain same as in the input array.
Note : The order of subsets are not important.

Constraints :
1 <= n <= 20

Input:
4
1 -1 3 -3
0

Output:
3 -3
1 -1
1 -1 3 -3
*/

/***
You need to save all the subsets in the given 2D output array. And return the number of subsets(i.e. number of rows filled in output) from the given function.

In ith row of output array, 1st column contains length of the ith subset. And from 1st column actual subset follows.
For eg. Input : {1, 3, 4, 2} and K = 5, then output array should contain
	{{2, 1, 4},	// Length of this subset is 2
	{2, 3, 2}}	// Length of this subset is 2

Don’t print the subsets, just save them in output.
***/

int helper(int input[], int n, int output[][50], int opstart, int k){
    //opstart denotes at which row index we have to add the next possible solution row
    //before opstart, previous soln rows have already been added
    
    //BASE CASE: when we reach the end of array and k==0, this means that the integers selected in this recursive path sum 
    //upto k. So in order to have those integers added as a possible solution row in output arr, we need to include/initiate a solution 
    //in the output arr at output[opstart]
    if(n==0 && k==0){  
        output[opstart][0] = 0;
        return 1;
    }
    else if(n==0 && k!=0){ //this means: the ints selected in the recursive path do not sum upto k 
        return 0;
    }
    
    //calling recursion calls after excluding the last element
    int size1 = helper(input, n-1, output, opstart, k);
    //update the opstart and k for the next recursive call in which we have included the last element in the sum
    int size2 = helper(input, n-1, output, opstart+size1, k-input[n-1]);
    
    //attach last element of input arr, in the 2nd recursive calls solutions
    for(int i=opstart+size1; i < opstart+size2+size1; i++){
        output[i][output[i][0] + 1] = input[n-1];
        output[i][0]++;
    }
    
    return size1+size2;
}

int subsetSumToK(int input[], int n, int output[][50], int k) {
    return helper(input, n, output, 0, k);
}