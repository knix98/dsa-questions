/*
https://leetcode.com/problems/rotate-image/description/
*/

/*
    Transpose + reflect (rev on diag then rev top to bottom)

    Time: O(n^2)
    Space: O(1)
*/

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};