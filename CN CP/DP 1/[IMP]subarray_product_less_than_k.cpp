/*
https://leetcode.com/problems/subarray-product-less-than-k/description/

Given an array of integers nums and an integer k, return the number of contiguous subarrays where the product of all the elements 
in the subarray is strictly less than k.

Example 1:

Input: nums = [10,5,2,6], k = 100
Output: 8
Explanation: The 8 subarrays that have product less than 100 are:
[10], [5], [2], [6], [10, 5], [5, 2], [2, 6], [5, 2, 6]
Note that [10, 5, 2] is not included as the product of 100 is not strictly less than k.

Example 2:

Input: nums = [1,2,3], k = 0
Output: 0
 

Constraints:

1 <= nums.length <= 3 * 104
1 <= nums[i] <= 1000
0 <= k <= 106
*/



/*
Approach : Sliding Window [Accepted]

Intuition
For each right, call opt(right) the smallest left so that the product of the subarray nums[left] * nums[left + 1] * ... * nums[right] is less than k. opt is a monotone increasing function, so we can use a sliding window.

Algorithm
Our loop invariant is that left is the smallest value so that the product in the window prod = nums[left] * nums[left + 1] * ... * nums[right] is less than k.
For every right, we update left and prod to maintain this invariant. Then, the number of intervals with subarray product less than k and with right-most coordinate right, is right - left + 1. We'll count all of these for each value of right.

Complexity Analysis
Time Complexity: O(N), where N is the length of nums. left can only be incremented at most N times.
Space Complexity: O(1), the space used by prod, left, and ans.
*/
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int ans = 0;
        int prod = 1;
        int j = 0;  // j == left
        for(int i=0; i<nums.size(); i++){  // i == right
            prod *= nums[i];
            while(prod >= k && j<=i){
                prod /= nums[j];
                j++;
            }

            // if j > i , that means prod == 1, and no subarrays possible which are ending at i, so dont add anything to ans 
            if(j<=i){
                ans += (i-j+1);
            }
        }

        return ans;
    }
};