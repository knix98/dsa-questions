// https://leetcode.com/problems/jump-game/description/

/*
Approach : if from any index i, we can jump to the nearest canJumpIndex on the right, then this index i is also a canJumpIndex
Time = O(n), Space = O(1)
*/

class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int lastCanJumpIndex = nums.size() - 1;
        for (int i = nums.size() - 2; i >= 0; i--)
        {
            if (nums[i] >= lastCanJumpIndex - i)
                lastCanJumpIndex = i;
        }
        return lastCanJumpIndex == 0;
    }
};