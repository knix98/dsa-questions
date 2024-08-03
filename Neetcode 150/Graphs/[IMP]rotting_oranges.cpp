/*
https://leetcode.com/problems/rotting-oranges/
*/


class Solution {
private:
   int orangesLeft, m, n;
   vector<vector<int>> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

   int bfs(vector<vector<int>>& grid, queue<pair<int, int>> &q) {
      int x, y, nx, ny, maxLevel = 10;
      while(!q.empty()) {
         x = q.front().first;
         y = q.front().second;
         q.pop();

         for(int i=0; i<4; i++) {
            nx = x + dirs[i][0];
            ny = y + dirs[i][1];
            if(nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == 1) {
               orangesLeft--;
               grid[nx][ny] = grid[x][y] + 1;
               if(grid[nx][ny] > maxLevel) maxLevel = grid[nx][ny];
               q.push({nx, ny});
            }
         }
      }

      return maxLevel - 10;
   }

public:
   int orangesRotting(vector<vector<int>>& grid) {
      m = grid.size();
      n = grid[0].size();

      queue<pair<int, int>> q;
      for(int i=0; i<m; i++) {
         for(int j=0; j<n; j++) {
            if(grid[i][j] == 1) orangesLeft++;
            else if(grid[i][j] == 2) grid[i][j] = 10, q.push({i, j});  // grid[i][j] = 10 means 0 level of bfs, similarly 11 would mean 1 level and so on in bfs
         }
      }

      int ans = bfs(grid, q);
      return orangesLeft ? -1 : ans;
   }
};