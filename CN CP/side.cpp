#include <bits/stdc++.h>
using namespace std;

// class Solution {
// private:
//     int k;
//     int target;

//     bool helper(vector<int>& nums, int i, vector<bool> &available, int bucketNo, int bucketSum) {
//         if(bucketSum == target) {
//             // start filling a new bucket from the first index of nums
//             bucketNo++;
//             bucketSum = 0;
//             i=0;
//         }
//         if(bucketNo == k) return true; // means we have filled k-1 buckets with targetSum, so we are done
//         if(i == nums.size()) {
//             // means we have reached end of nums without successfully making up targetSum in the current bucket (i.e bucketSum < target)
//             return false;
//         }

//         if(available[i]) {
//             // case 1 try taking curr elem
//             if(bucketSum + nums[i] <= target) {
//                 available[i] = false;
//                 if(helper(nums, i+1, available, bucketNo, bucketSum + nums[i])) return true;
//                 available[i] = true;
//             }
//         }

//         // case 2 leave curr elem
//         return helper(nums, i+1, available, bucketNo, bucketSum);    
//     }

// public:
//     bool canPartitionKSubsets(vector<int>& nums, int k) {
//         vector<bool> available(nums.size(), true);
//         this->k = k;

//         target = accumulate(nums.begin(), nums.end(), 0);
//         if(target % k) return false;
//         target /= k;

//         sort(nums.begin(), nums.end(), greater<int>());
//         return helper(nums, 0, available, 1, 0);
//     }
// };

class Solution {
private:
    int side;

    bool helper(vector<int> &matchsticks, int i, vector<int> &sides) {
        if(i == matchsticks.size()) return true;

        bool putIntoEmptySide = false;
        for(int j=0; j<sides.size(); j++) {
            if((matchsticks[i] + sides[j] <= side) && !(putIntoEmptySide && sides[j] == 0)) {
                sides[j] += matchsticks[i];
                if(helper(matchsticks, i+1, sides)) return true;
                sides[j] -= matchsticks[i];

                if(sides[j] == 0) putIntoEmptySide = true;
            }
        }

        return false;
    }

public:
    bool makesquare(vector<int> &matchsticks) {
        side = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        if(side % 4) return false;
        side /= 4;

        vector<int> sides(4, 0);
        return helper(matchsticks, 0, sides);
    }
};

int main() {
    Solution s;
    vector<int> nums = {2,2,2,2,3,4,5};
    cout << s.canPartitionKSubsets(nums, 4);
}