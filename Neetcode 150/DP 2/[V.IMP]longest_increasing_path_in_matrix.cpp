/*
https://leetcode.com/problems/longest-increasing-path-in-a-matrix/submissions/1453285541/
*/


/*
DFS + memo, cache on indices, compare to prev for increasing check

    Time: O(m x n)
    Space: O(m x n)

here the thing to think/note is we will never form a recursion loop (i.e. come back to a node on which a recursion call is already in progress) :
    4 <- 3
         ^
         |
    1 -> 2

    as seen in the above image : 4 would not call recursion again on 1 (because 1 is smaller). So the recursion calls would always be in a increasing sequence
*/
class Solution {
private:
    int ans;
    int m, n;
    vector<vector<int>> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

    bool check(int i, int j) {
        return i >= 0 && i < m && j >= 0 && j < n;
    }

    void memoisation(vector<vector<int>> &mat, vector<vector<int>> &dp, int i, int j) {
        if(dp[i][j]) return;

        int ni, nj;
        dp[i][j] = 1;
        for(int k = 0; k<4; k++) {
            ni = i + dirs[k][0]; 
            nj = j + dirs[k][1];
            if(check(ni, nj) && mat[ni][nj] > mat[i][j]) {
                memoisation(mat, dp, ni, nj);
                if(dp[ni][nj] + 1 > dp[i][j]) {
                    dp[i][j] = dp[ni][nj] + 1;
                }
            }
        }

        ans = max(ans, dp[i][j]);
    }

public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        m = matrix.size(); 
        n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        ans = 1;

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(!dp[i][j]) memoisation(matrix, dp, i, j);
            }
        }

        return ans;
    }
};