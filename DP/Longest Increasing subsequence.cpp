/*
Given an array with N elements, you need to find the length of the longest subsequence in the given array
such that all elements of the subsequence are sorted in strictly increasing order.

Constraints
1 <= N <= 10^3
Time Limit: 1 second

Sample Input 1 :
6
5 4 11 1 16 8
Sample Output 1 :
3
Sample Output Explanation
Length of longest subsequence is 3 i.e. (5,11,16) or (4,11,16).
*/

#include <algorithm>
#include <climits>
using namespace std;

int longestIncreasingSubsequence(int *arr, int n)
{
    int **dp = new int *[n + 1];
    for (int i = 0; i < n + 1; i++)
    {
        dp[i] = new int[n + 1]{0};
    }

    // let i (rows) signify arr_start_index and j signify the index of the min value in arr
    //  so dp[i][j] = longest subsequence length in an arr starting from index 'i' and every number in the sequence is greater than arr[j]
    //  so if i==n means no elements in the array, so no subsequence possible, so last row already filled with 0
    //  start from second last row...
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 0; j < n + 1; j++)
        {
            int a = dp[i + 1][j]; // means the longest sub-seq from smaller array with same min-value

            int b = INT_MIN;
            int minValue = (j == n) ? INT_MIN : arr[j];
            if (arr[i] > minValue)
            { // checking whether the starting value of current input arr is greater than the min-value for this input arr
                // if yes, then find the longest subsequence in the input arr with the first element as the starting element of the subsequence
                b = 1 + dp[i + 1][i]; // means the longest sub-seq from smaller array with min-value as the starting element of current input array
                                      //  so we have done +1 to include the starting element in the sub-seq also...
            }
            dp[i][j] = max(a, b);
        }
    }

    return dp[0][n];
}