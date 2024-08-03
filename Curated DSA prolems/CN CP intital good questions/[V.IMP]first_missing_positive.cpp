/*
https://leetcode.com/problems/first-missing-positive/
*/



/*
Intuition
The problem requires finding the smallest positive integer that is not present in an unsorted integer array. 
To achieve this efficiently, we can utilize the fact that the answer lies within the range [1, n+1], 
where n is the size of the array. By rearranging the elements of the array, we can position each positive integer i at index i-1. 
Then, we iterate through the array to find the first index i where nums[i] != i+1, indicating the missing positive integer is i+1.

Approach
Iterate through the array and place each positive integer i at index i-1 if possible. This ensures that the element nums[i] == i+1 if it exists in the array.
Iterate through the array again to find the first index i where nums[i] != i+1. Return i+1 as the smallest missing positive integer.
If all numbers from 1 to n are present in the array, return n+1 as the result.
*/

class Solution {
public:
    // intuition : the answer lies within the range [1, n+1]
    void swaps(vector<int>& nums, int i, int j){
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
    
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        
        for(int i=0; i<n; i++){
            while(nums[i] >= 1 && nums[i] <= n && nums[i] != i+1){
                int j = nums[i] - 1;
                if(nums[i] == nums[j]) break;  // means nums[j] == j+1 already, so need to swap duplicate values and get into infinite loop
                swaps(nums, i, j);
            }
        }

        for(int i=0; i<n; i++){
            if(nums[i] != i+1){
                return i+1;
            }
        }

        return n+1;
    }
};