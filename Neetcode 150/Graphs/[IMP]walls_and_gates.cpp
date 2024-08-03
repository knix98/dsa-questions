/*
https://www.lintcode.com/problem/663/
*/


/*
Approach : shortest-path questions means BFS approach
we will start bfs from the rooms having zero value/distance
*/
class Solution {
private:
    int m, n;
    vector<vector<int>> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

    bool check(int &x, int &y) {
        return (x >= 0 && x < m && y >= 0 && y < n);
    }

public:
    void wallsAndGates(vector<vector<int>> &rooms) {
        m = rooms.size();
        n = rooms[0].size();

        queue<pair<int, int>> q;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(rooms[i][j] == 0) q.push({i, j});
            }
        }

        int x, y, nx, ny;
        while(!q.empty()) {
            x = q.front().first;
            y = q.front().second;
            q.pop();

            for(int i=0; i<4; i++) {
                nx = x + dirs[i][0];
                ny = y + dirs[i][1];
                if(check(nx, ny) && rooms[nx][ny] > 0) {
                    if(rooms[nx][ny] >= 2147483647) q.push({nx, ny});
                    rooms[nx][ny] = min(rooms[nx][ny], rooms[x][y] + 1);
                }
            }
        }
    }
};