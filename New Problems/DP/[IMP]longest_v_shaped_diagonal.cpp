/*
https://leetcode.com/problems/length-of-longest-v-shaped-diagonal-segment/
*/

/*
Intuition : Since in question we can take atmost only 1 clockwise 90 degree turn, this means that if we do a backtracking approach
to start from a cell containing 1 and explore paths until we reach a dead end cell at the edges of the grid, we are sure that any of these 
paths wouldn't form a closed loop, and hence once we got an answer at a leaf cell then we can backtrack to get answers for the other
previous cells in any path.

Time and space : O(m*n)
*/


class Solution {
private:
	vector<vector<vector<vector<int>>>> dp;
	vector<vector<int>> dirs = {{-1, -1}, {-1, 1}, {1, 1}, {1, -1}};
	int m;
	int n;

	bool check(int x, int y) {
		return x >= 0 && x < m && y >= 0 && y < n;
	}

	int solve(vector<vector<int>>& grid, int x, int y, int dir, bool canTurn) {
		int nextNum = grid[x][y] == 2 ? 0 : 2;
		int nx, ny;
		if(!dp[x][y][dir][0]) { // means dp[x][y][dir][0] hasnt been answered through dfs yet
			dp[x][y][dir][0] = 1;
			nx = x + dirs[dir][0], ny = y + dirs[dir][1];
			if(check(nx, ny) && grid[nx][ny] == nextNum) {
                // we go to the next cell in the same dir and tell it : canTurn = false for you
				dp[x][y][dir][0] = 1 + solve(grid, nx, ny, dir, false);
			}
		}
		int ans = dp[x][y][dir][0];

		if(canTurn) { // if we can turn from this cell then explore the canTurn case as well
			if(!dp[x][y][dir][1]) { // means dp[x][y][dir][1] hasnt been answered through dfs yet
				dp[x][y][dir][1] = 1;

                // case 1 : we go to the next cell in the same dir and tell it : canTurn = true for you (since we didnt take turn yet)
				nx = x + dirs[dir][0], ny = y + dirs[dir][1];
				if(check(nx, ny) && grid[nx][ny] == nextNum) {
					dp[x][y][dir][1] = 1 + solve(grid, nx, ny, dir, true);
				}
				
				// case 2 : since the question says that we can take at most one clockwise 90-degree turn, we will skip the anticlockwise turn
				// int newDir = dir == 0 ? 3 : dir-1;
				// nx = x + dirs[newDir][0], ny = y + dirs[newDir][1];
				// if(check(nx, ny) && grid[nx][ny] == nextNum) {
				// 	dp[x][y][dir][1] = max(dp[x][y][dir][1], 1 + solve(grid, nx, ny, newDir, false));
				// }

                // case 3 : we take the clockwise turn here only and go to the next cell with a newDir and tell it : canTurn = false for you (since we have taken turn just now)
				int newDir = dir == 3 ? 0 : dir+1;
				nx = x + dirs[newDir][0], ny = y + dirs[newDir][1];
				if(check(nx, ny) && grid[nx][ny] == nextNum) {
					dp[x][y][dir][1] = max(dp[x][y][dir][1], 1 + solve(grid, nx, ny, newDir, false));
				}
			}

			ans = max(ans, dp[x][y][dir][1]);
		}

		return ans;
	}

public:
    int lenOfVDiagonal(vector<vector<int>>& grid) {
		m = grid.size(), n = grid[0].size();
        /* <1>
        at any cell we have 4 cases : the 4 possible directions from which we arrived at this cell
        and for each direction case we need to have 2 answers : 
            1. dp[i][j][dir][0] = max possible length starting at this cell and continuing in this same dir without turning
            2. dp[i][j][dir][0] = max possible length starting at this cell and 1 clockwise turn can be taken from this dir
        */
		dp = vector<vector<vector<vector<int>>>>(m, vector<vector<vector<int>>>(n, vector<vector<int>>(4, vector<int>(2, 0))));
		int ans = 0;

        // <2> loop to find the cells which contain 1, so that we can start our dfs from there
		for(int i=0; i<m; i++) {
			for(int j=0; j<n; j++) {
				if(grid[i][j] == 1) {  
					if(ans == 0) ans = 1;

					for(int k=0; k<4; k++) {
						int x = i + dirs[k][0], y = j + dirs[k][1];
						if(check(x, y) && grid[x][y] == 2) {
							ans = max(ans, 1 + solve(grid, x, y, k, true));
						}
					}
				}
			}
		}

		return ans;
    }
};