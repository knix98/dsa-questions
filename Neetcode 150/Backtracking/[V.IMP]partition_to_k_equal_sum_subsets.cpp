/*
this problem : https://leetcode.com/problems/partition-to-k-equal-sum-subsets/

another similar problem to this : https://leetcode.com/problems/matchsticks-to-square/

and problem with a slight variation is pasted below the above problem
*/


// solution for partition k equal sum subsets ...
/*
Approach : every element can go in any 1 of the k buckets. we will simulate this process only using backtracking

Great question! The line if(buckets[j] == 0) putIntoEmptyBucket = true; is indeed a crucial optimization that can significantly reduce the time complexity in many cases. Let's break down why this is so effective:

Avoiding Duplicate Work:
When we backtrack and remove a number from a subset, if that subset becomes empty (sum becomes 0), it means we're back to the starting point for that subset. 
If we continue to the next iteration of the loop, we'd be trying to add the current number to another empty subset. 
This would lead to exploring the same combinations we've already explored or will explore in future recursive calls.
Symmetry Breaking:
All empty subsets are identical from the perspective of our algorithm. Once we've tried adding the current number to one empty subset and it didn't lead to a solution, there's no point in trying to add it to other empty subsets.
Pruning the Search Tree:
By breaking the loop when we encounter an empty subset, we're effectively pruning a large portion of the search tree. This can drastically reduce the number of recursive calls and iterations.
Reducing Permutations:
Without this break, the algorithm would consider all permutations of the subsets, which is unnecessary since we only care about the content of the subsets, not their order.

Time Complexity Impact:

In the worst case (when no valid partition exists), the time complexity without this optimization could be O(k^n), where k is the number of subsets and n is the number of elements.
With this optimization, many redundant paths are eliminated, potentially reducing the time complexity significantly, although it remains exponential in the worst case.

why are we sorting the array in descending order in the beginning ?
so that the obvious wrong recursive paths in which all the biggest elements are put into the same buckets are eliminated earlier in the recursive path
means if nums = [1,2,3,4,5,6,7,8,9]
then, we would be saved from the exploring of wrong paths such as [1,2,3] [7,8,9] (biggest elements put into same bucket later in the recursive path)
because all such paths would be eliminated initially only when we eliminate the [9,8,7] path (biggest elements put into same bucket initially in the recursive path)
*/
class Solution {
private:
    int target;

    bool helper(vector<int> &nums, int i, vector<int> &buckets) {
        if(i == nums.size()) return true;

        bool putIntoEmptyBucket = false;
        for(int j=0; j<buckets.size(); j++) {
            if((nums[i] + buckets[j] <= target) && !(putIntoEmptyBucket && buckets[j] == 0)) {
                buckets[j] += nums[i];
                if(helper(nums, i+1, buckets)) return true;
                buckets[j] -= nums[i];

                if(buckets[j] == 0) putIntoEmptyBucket = true;  // explanation for this written above
                // putIntoEmptyBucket means that the curr element (nums[i]) has been tried by putting into an empty bucket, so we will ignore the future cases in this loop
                // where we will again put nums[i] into another empty bucket. (since all buckets are similar and there is no significance of the ordering of the buckets)
            }
        }

        return false;
    }

public:
    bool canPartitionKSubsets(vector<int> &nums, int k) {
        target = accumulate(nums.begin(), nums.end(), 0);
        if(target % k) return false;
        target /= k;

        vector<int> buckets(k, 0);  // signifying k buckets and the sum of all nums inside each bucket
        sort(nums.begin(), nums.end(), greater<int>());
        return helper(nums, 0, buckets);
    }
};




/*
a slight variation problem
https://leetcode.com/problems/fair-distribution-of-cookies/description/

similar problem to the above : https://leetcode.com/problems/find-minimum-time-to-finish-all-jobs/
*/

/*
approach is same way as the above problem code.
only thought is that we calculate a fairMark value which gives us a line (for the sum of cookies in 1 bucket) which can be just crossed in all the buckets
*/
class Solution {
private:
    int ans;
    int fairMark;

    void helper(vector<int> &cookies, int i, vector<int> &buckets, int maxBucketSum) {
        if(i == cookies.size()) {
            ans = min(ans, maxBucketSum);
            return;
        }

        bool putIntoEmptyBucket = false;
        for(int j=0; j<buckets.size(); j++) {
            if(buckets[j] <= fairMark && !(putIntoEmptyBucket && buckets[j] == 0)) {
                // so we can put cookies[i] inside buckets[j]
                buckets[j] += cookies[i];
                helper(cookies, i+1, buckets, max(maxBucketSum, buckets[j]));
                buckets[j] -= cookies[i];

                if(buckets[j] == 0) putIntoEmptyBucket = true;
            }
        }
    }

public:
    int distributeCookies(vector<int> &cookies, int k) {
        sort(cookies.begin(), cookies.end(), greater<int>());
        vector<int> buckets(k, 0);
        fairMark = accumulate(cookies.begin(), cookies.end(), 0);
        ans = fairMark;
        fairMark /= k;

        helper(cookies, 0, buckets, 0);

        return ans;
    }
};