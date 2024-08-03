/*
leetcode => https://leetcode.com/problems/predict-the-winner/description/

You are given an integer array nums. Two players are playing a game with this array: player 1 and player 2.

Player 1 and player 2 take turns, with player 1 starting first. Both players start the game with a score of 0. At each turn, the player takes one of the numbers from either end of the array (i.e., nums[0] or nums[nums.length - 1]) which reduces the size of the array by 1. The player adds the chosen number to their score. The game ends when there are no more elements in the array.

Return true if Player 1 can win the game. If the scores of both players are equal, then player 1 is still the winner, and you should also return true. You may assume that both players are playing optimally.

 

Example 1:

Input: nums = [1,5,2]
Output: false
Explanation: Initially, player 1 can choose between 1 and 2. 
If he chooses 2 (or 1), then player 2 can choose from 1 (or 2) and 5. If player 2 chooses 5, then player 1 will be left with 1 (or 2). 
So, final score of player 1 is 1 + 2 = 3, and player 2 is 5. 
Hence, player 1 will never be the winner and you need to return false.
Example 2:

Input: nums = [1,5,233,7]
Output: true
Explanation: Player 1 first chooses 1. Then player 2 has to choose between 5 and 7. No matter which number player 2 choose, player 1 can choose 233.
Finally, player 1 has more score (234) than player 2 (12), so you need to return True representing player1 can win.
 

Constraints:

1 <= nums.length <= 20
0 <= nums[i] <= 107
*/



class Solution {
public:
    void fillCell(vector<vector<pair<int,int>>> &dp, int x, int y, vector<int> &nums){
        if(x == y) { // means only 1 coin is there , so player1 would pick it and player2 score will be 0
            dp[x][y] = {nums[x], 0};
            return;
        }

        if(x < y){
            pair<int,int> sol1, sol2;
            if(dp[x+1][y].first == -1) {     // in sol1 => when player1 picks coin at i=x
                fillCell(dp, x+1, y, nums);
            }
            sol1 = dp[x+1][y];
            sol1 = {nums[x] + sol1.second, sol1.first};  // in dp[x+1][y], first would signify points earned by player2 from (x+1,y) position and second would signify points by player1 from that position
                                                         // thats why adding nums[x] + second == player1 points and 0 + first == player2 points

            if(dp[x][y-1].first == -1) {     // in sol2 => when player1 picks coin at i=y
                fillCell(dp, x, y-1, nums);
            }
            sol2 = dp[x][y-1];
            sol2 = {nums[y] + sol2.second, sol2.first};

            if(sol1.first - sol1.second > sol2.first - sol2.second) dp[x][y] = sol1;  // we will pick the coin which results into more difference between player1 and player2 points
            else dp[x][y] = sol2;                                                     
            // if sol1 = {3,5} and sol2 = {5,9}... so in both cases player1 looses but still we will pick sol1, because loss margin is less 
        }
    }

    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();

        // this 2D dp, dp[x][y] = {a,b} where a = points accumulated by player 1 if game started with coins present in i = [x,y], and b accumulated by player 2
        vector<vector<pair<int,int>>> dp(n, vector<pair<int,int>>(n, {-1,-1}));

        fillCell(dp, 0, n-1, nums);
        if(dp[0][n-1].first >= dp[0][n-1].second) return true;  // means player 1 would win
        else return false;
    }
};