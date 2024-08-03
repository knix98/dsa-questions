/*
https://leetcode.com/problems/find-the-duplicate-number/description/
*/


/*
It can be solved easily using method 2 code, but the question said to solve it without modifying the input array
and in constant space. Hence this neetcode approach of solving using start point of cycle in LL approach
*/
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // starting with the respective second positions of slow and fast, because if I start from the same slow and fast
        // then the while loop would not run only because of the condition while(slow != fast)
        int slow = nums[nums[0]], fast = nums[nums[nums[0]]];
        while(slow != fast) {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }

        slow = nums[0];
        while(slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;
   }
};



// Method 2
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int idx;
        for(int i : nums) {
            idx = abs(i);
            if(nums[idx] < 0) return idx;
            else nums[idx] *= -1;
        }

        return idx;
    }
};