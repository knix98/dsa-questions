/*
https://leetcode.com/problems/spiral-matrix/
*/


/*
we will keep moving forward in a direction, and keep marking cells as visited. when we reach a dead-end or a visited cell, then we change direction
*/
class Solution {
private:
    vector<char> dirs = {'R', 'D', 'L', 'U'};
    unordered_map<char, vector<int>> move;

public:
    Solution() {
        move['R'] = {0, 1};
        move['D'] = {1, 0};
        move['L'] = {0, -1};
        move['U'] = {-1, 0};
    }

    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<int> ans;
        int x = 0, y = 0, nx, ny;
        int currMoveIndex = 0;
        char currMove = dirs[currMoveIndex];
        
        while(x >= 0 && x < n && y >= 0 && y < m && matrix[x][y] != 200) {   // since elem range is till 100 only, so 200 means visited cell
            ans.push_back(matrix[x][y]);
            matrix[x][y] = 200;

            nx = x + move[currMove][0];
            ny = y + move[currMove][1];

            if(nx >= 0 && nx < n && ny >= 0 && ny < m && matrix[nx][ny] != 200) {
                x = nx;
                y = ny;
            }
            else {
                currMoveIndex = (currMoveIndex + 1) % 4;
                currMove = dirs[currMoveIndex];
                x = x + move[currMove][0];
                y = y + move[currMove][1];
            }
        }

        return ans;
    }
};