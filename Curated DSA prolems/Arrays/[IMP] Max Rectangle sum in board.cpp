/*
Ninja is feeling bored today. So he went for a walk and thought of a problem. Can you help him in solving it?
He has a 2D board ‘ARR’ with ‘N’ rows and ‘M’ columns. He wants to find a rectangle having the maximum sum on the board.
Rectangle sum is the sum of values of integers present within its boundary.

Ex : -2 -1
      2  2   then, the rectangle consisting of the bottom row only is the rectangle with maximum sum
*/

// APPROACH 1 : my approach : calculating the sum of all rectangles whose bottom right vertex is (i,j)
// and determining the maxSum from among these, and doing the same procedure for all the (i,j) in the arr
// and then returning the maximum sum from amongst all the O(n2m2) sums

// Time complexity : O(n2m2)
// Space complexity : O(nm)
// int maxSumRectangle(vector<vector<int>>& arr, int n, int m)
// {
//     int ans = INT_MIN;
//     for(int x = n-1; x>=0; x--){
//         for(int y = m-1; y>=0; y--){
//             vector<vector<int>> dp(x+1, vector<int>(y+1, 0));
//             for(int i=x; i>=0; i--){
//                 for(int j=y; j>=0; j--){
//                     int sum = 0;
//                     if(j+1 <= y){
//                         sum += dp[i][j+1];
//                     }
//                     if(i+1 <= x){
//                         sum += dp[i+1][j];
//                     }
//                     if(i+1 <= x && j+1 <= y){
//                         sum -= dp[i+1][j+1];
//                     }
//                     dp[i][j] = sum + arr[i][j];

//                     ans = ans < dp[i][j] ? dp[i][j] : ans;
//                 }
//             }
//         }
//     }

//     return ans;
// }

// SOLUTION APPROACH : combining some rows together and then determining the max subArr sum of that
// combined row using kadane algo
// Time: O(n2m)
// Space : O(n)

int kadane(vector<int> &v, int m)
{
    int maxSum = INT_MIN;
    int sum = 0;

    for (int i = 0; i < m; i++)
    {
        sum += v[i];

        maxSum = sum > maxSum ? sum : maxSum;

        sum = sum < 0 ? 0 : sum;
    }

    return maxSum;
}

int maxSumRectangle(vector<vector<int>> &arr, int n, int m)
{
    int maxSum = INT_MIN;

    // topRow = first row amongst the combined rows
    for (int topRow = 0; topRow < n; topRow++)
    {

        // temp vector will contain the sum of the cobined columns of the cobined rows
        vector<int> temp(m, 0);

        // combining rows, starting with the topRow alone and then adding new rows to the topRow
        for (int i = topRow; i < n; i++)
        {
            // adding the columns of the new row to be combined
            for (int j = 0; j < m; j++)
            {
                temp[j] += arr[i][j];
            }

            // sending the updated combined row for kadane
            int subArrMaxSum = kadane(temp, m);

            if (subArrMaxSum > maxSum)
            {
                maxSum = subArrMaxSum;
            }
        }
    }

    return maxSum;
}