/*
https://leetcode.com/problems/detect-squares/description/
*/


class DetectSquares {
private:
    unordered_map<int, unordered_map<int, int>> grid;  // x,y,count  (count = number of coinciding points at x,y)

public:
    DetectSquares() {
        
    }
    
    void add(vector<int> point) {
        grid[point[0]][point[1]]++;
    }
    
    int count(vector<int> point) {
        int i = point[0], j = point[1];
        int side_length;
        int y;   // y coordinates of all points that have x == i
        int ans = 0;
        
        if(grid.count(i) > 0) {    // checking for the points lying on the vertical line : x = i
            for(auto it : grid[i]) {
                y = it.first;
                if(y == j) continue;  // same/coinciding point

                side_length = abs(y - j);

                ans += (grid[i][y] * grid[i + side_length][j] * grid[i + side_length][y]);  // checking for the other 2 square points on the right side
                ans += (grid[i][y] * grid[i - side_length][j] * grid[i - side_length][y]);  // checking for the other 2 square points on the left side
            }
        }

        return ans;
    }
};