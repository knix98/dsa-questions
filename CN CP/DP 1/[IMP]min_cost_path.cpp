/*
Min Cost Path

Given an integer matrix of size m*n, you need to find out the value of minimum cost to reach from the cell (0, 0) to (m-1, n-1).
From a cell (i, j), you can move in three directions : (i+1, j), (i, j+1) and (i+1, j+1).
Cost of a path is defined as the sum of values of each cell through which path passes.
Input Format :
Line 1 : Two integers, m and n
Next m lines : n integers of each row (separated by space)
Output Format :
Minimum cost
Constraints :
1 <= m, n <= 100
Sample Input 1 :
3 4
3 4 1 2
2 1 8 9
4 7 8 1
Sample Output 1 :
13
*/


/*
NOTE : since in this question, we are allowed to move right, down or diagonal only, so dp can be applied here because we cant move upwards
or backwards. But if the question would have been that we are allowed to move in all 4 directions NEWS, then in situation like below :
1 1 9 9 9 9 
9 1 9 1 1 1
9 1 1 1 9 1
Dp cannot be applied, in this case backtracking needs to be applied and then TIME = O(3^n), where n = number of total cells
*/
#include<bits/stdc++.h>
using namespace std;

// n - number of rows
/// m - number of columns
int minCostPath(int **input, int n, int m) {
   vector<int> nextRow(m, 0);

   // filling for the final row
   nextRow[m-1] = input[n-1][m-1];
   for(int j=m-2; j>=0; j--){
       nextRow[j] = input[n-1][j] + nextRow[j+1];
   }

   for(int i=n-2; i>=0; i--){
       vector<int> currRow(m, 0);

       for(int j=m-1; j>=0; j--){
           // we have to do this => currRow[j] = min({currRow[j+1], nextRow[j], nextRow[j+1]}) 
           currRow[j] = nextRow[j];
           if(j+1 < m){
               currRow[j] = min({currRow[j+1], nextRow[j], nextRow[j+1]});
           }

           currRow[j] += input[i][j];
       }

       nextRow = currRow;
   }

   return nextRow[0];
}
