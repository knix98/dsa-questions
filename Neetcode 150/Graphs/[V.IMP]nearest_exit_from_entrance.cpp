/*
https://leetcode.com/problems/nearest-exit-from-entrance-in-maze/description/
*/


/*
Initially the approach that came to my mind was of backtracking and exploring all the paths. But that is not efficient
So basically, we need to remember that, whenever shortest/nearest paths are asked then we should think of possibility of bfs solution once.
*/
class Solution {
private:
    vector<vector<int>> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int rows = maze.size(), cols = maze[0].size();
        int ix = entrance[0], iy = entrance[1];
        if(maze[ix][iy] == '+') return -1;

        queue<vector<int>> pending;
        pending.push({ix, iy, 0});   // coordinates and at third index is the level of this node in bfs traversal
        maze[ix][iy] = '+';

        int x, y, nx, ny, level;
        while(!pending.empty()) {
            x = pending.front()[0];
            y = pending.front()[1];
            level = pending.front()[2];
            pending.pop();

            // because the question says that the entrance point cant be exit, so we need to check for entrance point as well
            if((x == 0 || x == rows-1 || y == 0 || y == cols-1) && (x != ix || y != iy)) return level;

            for(int i=0; i<4; i++) {
                nx = x + dirs[i][0];
                ny = y + dirs[i][1];

                if(nx >= 0 && nx < rows && ny >= 0 && ny < cols && maze[nx][ny] == '.') {
                    maze[nx][ny] = '+';
                    pending.push({nx, ny, level+1});
                }
            }
        }   

        return -1;
    }
};