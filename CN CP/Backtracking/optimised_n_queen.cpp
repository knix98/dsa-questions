/*
You are given an integer 'N'. For a given 'N' x 'N' chessboard, find a way to place 'N' queens such that no queen can attack any other queen on the chessboard.
A queen can be killed when it lies in the same row, or same column, or the same diagonal of any of the other queens. You have to print all such configurations.
Input Format:
The first and the only line of input contains an integer 'N' representing the size of the chessboard and the number of queens.
Output Format:
Each line would be representing a single configuration.

Each configuration would contain 'N '* 'N' elements printed row-wise separated by spaces. The position where we can place the queen will have the value 1 rest will have the value 0.
Note:
You do not need to print anything, it has already been taken care of. Just implement the given function.
Constraints:
1 <= 'N' <= 10

Time Limit: 1sec
Sample Input 1:
4
Sample Output 1:
0 0 1 0 1 0 0 0 0 0 0 1 0 1 0 0
0 1 0 0 0 0 0 1 1 0 0 0 0 0 1 0 
Explanation For Sample Input 1:
Output depicts two possible configurations of the chessboard for 4 queens.

The Chessboard matrix for the first configuration looks as follows:-

0 0 1 0
1 0 0 0
0 0 0 1
0 1 0 0

Queen contained cell is depicted by 1. As seen, No queen is in the same row, column, or diagonal as the other queens. Hence this is a valid configuration.
Sample Input 2:
3
Sample Output2:
      (Blank)
Explanation For Sample Input 2:
Since no possible configuration exists for 3 Queen's.The output remains Empty.
*/



// Time : without optimisation checking takes O(n) time so : O(n^n * n), but with optimisation checking takes O(1) time so : O(n^n) 
// read CN CP notes for this bit of optimisation
void solve(vector<vector<int>> &board, int l, int n, vector<vector<int>> &ans, vector<int> &d1, vector<int> &d2, vector<int> &col){
    // base case
    if(l > n){
        vector<int> push(n*n);
        int k = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                push[k++] = board[i][j];
            }
        }

        ans.push_back(push);
        return;
    }

    int i = l-1; // since l = current level  (i.e, if level = 1 => row = 0)
    for(int j=0; j<n; j++){
        if(!col[j] && !d1[(n-i-1) + j] && !d2[i+j]){
            board[i][j] = 1;
            col[j]++;   
            d1[(n-i-1) + j]++;
            d2[i+j]++;
            solve(board, l+1, n, ans, d1, d2, col);
            board[i][j] = 0;
            col[j]--;  // doing -- instead of col[j] = 0, because col[j] might also be getting attacked by some other previous queen
            d1[(n-i-1) + j]--;
            d2[i+j]--;
        }
    }
}

vector<vector<int>> solveNQueens(int n) {
    vector<vector<int>> board(n, vector<int>(n, 0));

    vector<vector<int>> ans;

    vector<int> d1(2*n - 1, 0);
    vector<int> d2(2*n - 1, 0);
    vector<int> col(n, 0);

    solve(board, 1, n, ans, d1, d2, col);  // 1 is first level

    return ans;
}