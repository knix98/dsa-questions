/*
https://leetcode.com/problems/maximum-product-subarray/description/
*/

/*
at each index we can calculate max subarray product with current elem included and compare everytime with global ans
*/
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int prev_min = nums[n-1], prev_max = nums[n-1], temp1, temp2;
        int ans = prev_max;

        for(int i=n-2; i>=0; i--) {
            temp1 = nums[i] * prev_min;
            temp2 = nums[i] * prev_max;

            prev_min = min({temp1, temp2, nums[i]});
            prev_max = max({temp1, temp2, nums[i]});
            ans = max(ans, prev_max);
        }

        return ans;
    }
};