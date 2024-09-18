/*
    HOUSE ROBBER 1
    https://leetcode.com/problems/house-robber/description/
*/

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int prev_included = nums[n-1], prev_excluded = 0;
        int curr_included, curr_excluded;

        for(int i=n-2; i>=0; i--){
            curr_included = nums[i] + prev_excluded;
            curr_excluded = max(prev_excluded, prev_included);
            prev_excluded = curr_excluded;
            prev_included = curr_included;
        }

        return max(prev_excluded, prev_included);
    }
};




/*
    HOUSE ROBBER 2
    https://leetcode.com/problems/house-robber-ii/description/
*/

/*
Method 1 : my approach : we would have to calculate 4 values at each index :
    ans when : 1. both curr and last elem included
               2. when only curr included
               3. when only last included
               4. when none of curr and last included

How I arrived at this : I thought from nums[0] p.o.v => 
case 1 : If nums[0] taken then we cant take the next and the last elem => case 4 from above at next index
 to calculate case 4 of none taken , we need the other three cases values, that's why we need to calculate these 4 cases at all indexes
*/
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];

        // cl = current and last both taken, c = only curr taken, l = only last taken, none = none taken
        int prev_cl = nums[n-1], prev_c = 0, prev_l = 0, prev_none = 0;  
        int curr_cl, curr_c, curr_l, curr_none;  

        for(int i=n-2; i>=0; i--) {
            curr_cl = nums[i] + prev_l;
            curr_c = nums[i] + prev_none;
            curr_l = max(prev_cl, prev_l);
            curr_none = max(prev_c, prev_none);

            prev_cl = curr_cl;
            prev_c = curr_c;
            prev_l = curr_l;
            prev_none = curr_none;
        }

        return max({prev_c, prev_l, prev_none});
    }
};


/*
    METHOD 2 : neetcode
    approach : since we dont want nums[0] and nums[n-1] to be selected together, we can calculate 
    house robber 1 answer for 2 cases and take their max : 
    case 1 : house robber 1 ans for arr[0] to arr[n-2]
    case 2 : house robber 1 ans for arr[1] to arr[n-1]
*/
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        
        if (n == 1) {
            return nums[0];
        }
        
        int range1 = robber(nums, 0, n - 2);
        int range2 = robber(nums, 1, n - 1);
        
        return max(range1, range2);
    }
private:
    int robber(vector<int>& nums, int start, int end) {
        int prev = 0;
        int curr = 0;
        int next = 0;
        
        for (int i = start; i <= end; i++) {
            next = max(prev + nums[i], curr);
            prev = curr;
            curr = next;
        }
        
        return curr;
    }
};