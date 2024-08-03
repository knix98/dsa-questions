/*
question told to do it without division operator and without using extra space apart from the return ans vector
*/


class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans(nums.size());

        // first doing left to right traversal and calculating prefix products at each index and store them in ans array at index+1
        int prod = 1;
        ans[0] = prod;
        for(int i = 0; i<nums.size()-1; i++){
            prod *= nums[i];
            ans[i+1] = prod;
        }

        // now do right to left traversal and calculate postfix products and multiply them with corresponding prefix product to get product except self
        prod = 1;
        for(int i = nums.size()-1; i>=1; i--) {
            prod *= nums[i];
            ans[i-1] *= prod;
        }

        return ans;
    }
};