/*
Problem link : https://leetcode.com/problems/trapping-rain-water-ii/description/
Solution video : pepcoding
*/


bool check(int &x, int &y, int &rows, int &cols) {
    return (x >= 0 && x < rows && y >= 0 && y < cols);
}

int neix[4] = {-1, 0, 1, 0}; 
int neiy[4] = {0, 1, 0, -1}; 

class Solution {
public:
    int trapRainWater(vector<vector<int>>& height) {
        int rows = height.size(), cols = height[0].size();
        vector<vector<int>> dp(rows, vector<int>(cols, -1));
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq; // min pq

        for(int i=0; i<rows; i++) {   // pushing left and right boundary cells
            dp[i][0] = height[i][0];
            pq.push({height[i][0], i, 0});
            
            dp[i][cols-1] = height[i][cols-1];
            pq.push({height[i][cols-1], i, cols-1});
        }
        for(int j=1; j<cols-1; j++) {   // pushing top and bottom boundary cells
            dp[0][j] = height[0][j];
            pq.push({height[0][j], 0, j});

            dp[rows-1][j] = height[rows-1][j];
            pq.push({height[rows-1][j], rows-1, j});
        }

        int ans = 0;
        vector<int> top;
        int block, i, j, ni, nj;
        while(!pq.empty()) {
            top = pq.top();
            pq.pop();

            i = top[1], j = top[2];
            block = dp[i][j];
            if(height[i][j] < block) ans += (block - height[i][j]);

            for(int k = 0; k<4; k++) {
                ni = i + neix[k];
                nj = j + neiy[k];

                if(check(ni, nj, rows, cols) && dp[ni][nj] == -1) {
                    dp[ni][nj] = max(dp[i][j], height[ni][nj]);
                    pq.push({dp[ni][nj], ni, nj});
                }
            }
        }

        return ans;
    }
};