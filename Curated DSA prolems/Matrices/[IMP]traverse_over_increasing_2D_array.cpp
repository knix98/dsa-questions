/*
https://classroom.codingninjas.com/app/classroom/me/11692/content/204223/offering/2650147/problem/13861?leftPanelTabValue=PROBLEM

Antonio serves in the army, now in one of his missions he encounters some mines present in the form of a matrix, each mine has a specific number written on it and as well as each row and each column of mines are sorted in increasing order and all these mines have distinct numbers. Someone tipped Antonio and gave him a number and said that if this number mine is present in the matrix then it is safe for you to land on it else you will get blast. Now for this Antonio wants your help to find whether that number mine is present or not.

You will be given a 2 - D array 'MATRIX' of size N x N and an integer value 'X'. your task is to find the position of 'X' in the matrix if it exists then return the pair {i, j} where 'i' represents the row and 'j' represents the column of the array, otherwise return {-1,-1}.

For example:

If the given matrix is:
[ [11, 12, 15],
  [13, 14, 19],
  [16, 17, 20] ] 
We have to find the position of X = 19. We will return {1, 2} since MATRIX[1][2] = 19.
Note:

It is guaranteed that the matrix contains distinct elements.
Detailed explanation ( Input/output format, Notes, Images )
Constraints:
1 ≤ T ≤ 10
1 ≤ N ≤ 10 ^ 3
1 ≤ X ≤ 10 ^ 6
1 ≤ MATRIX[ i ][ j ] ≤ 10 ^ 6

Time Limit: 1 sec.
Sample Input 1:
2
3 70
10 20 50
30 40 90
60 70 100
2 88
44 55
88 99
Sample Output 1:
2 1
1 0
Explanation of Input 1:
For the first test case, the given matrix is 
[ [10, 20, 50],
  [30, 40, 90],
  [60, 70, 100] ] 

We have to find the position of 70. So we return {2,1}.

The second test case,  the given matrix is:
[[44, 55],
 [88, 99]] 
We have to find the position of 88. So we return {1,0}.
Sample Input 2:
2
3 16
2 4 8
3 6 9
4 7 16
1 10
4
Sample Output 2
2 2
-1 -1
*/


// This is the best approach of travelling and finding any element in such a matrix(in least number of steps) O(n) complexity 
// This approach can be thought of as applying binary search to such a matrix: that is starting from some middle value,
// and then searching in the left half or the right half depending on the value

pair<int, int> search(vector<vector<int>> &matrix, int x)
{
    int n = matrix.size();

    int i=0, j=n-1; //starting middle point for searching
    while(i < n && j >= 0){
        if(matrix[i][j] == x){
            pair<int, int> ans(i,j);
            return ans;
        }

        if(matrix[i][j] < x){
            i++;  // this way we are ignoring the values matrix[i][0] to matrix[i][j] ... because they are obviously even more lesser than x
        }
        else{
            j--;  // this way we are ignoring the values matrix[i][j] to matrix[n-1][j] ... because they are obviously even more greater than x
        }
    }

    pair<int, int> ans(-1, -1);
    return ans;
}