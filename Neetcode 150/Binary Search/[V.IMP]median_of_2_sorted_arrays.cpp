/*
https://leetcode.com/problems/median-of-two-sorted-arrays/
*/

/*
    Given 2 sorted arrays of size m & n, return the median of these arrays
    Ex. nums1 = [1,3] nums2 = [2] -> 2, nums1 = [1,2] nums2 = [3,4] -> 2.5

    Binary search, partition each array until partitions are correct, get median
    [1,2,3,4,5]
    |  a|b    |
    [1,2,3,4,5,6,7,8]    -->    a <= d ? yes, c <= b ? no, so need to fix
    |      c|d      |

    Time: O(log min(m, n))
    Space: O(1)
*/
class Solution {
private:
    double helper(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        int half = (n+m)/2;
        bool partitionFound = false;

        // end point of left partition on nums1 = le1 , start point of right partition on nums1 = rs1
        // similarly le2 and rs2 on nums2
        int i = 0, j = n-1, le1, rs1, le2, rs2;
        while(i <= j) {
            le1 = (i+j)/2;
            le2 = half - le1 - 2;
            rs1 = le1 + 1;
            rs2 = le2 + 1;

            if(nums1[le1] > nums2[rs2]) {  // we didnt apply any index checks here because, le1 is always valid and le2 can minimum be -1 so rs2 is atleast 0
                                            // and le2 can maximum cannot be the last index of nums2 because nums2 is bigger array, so "half - le1 - 2" would never come out to be that much large
                // move left
                j = le1 - 1;
            }
            else if(le2 >= 0 && rs1 < n && nums2[le2] > nums1[rs1]) {
                // move right
                i = le1 + 1;
            }
            else {
                // we found the perfect partition in both the vectors
                partitionFound = true;
                break;
            }
        }

        if(!partitionFound) {
            // means all elems in the left partition of combined array would belong to nums2 only (means we dont have to take any elems from nums1 for left partition)
            le2 = half - 1;
            le1 = -1;
            rs1 = 0;
            rs2 = le2 + 1;
        }

        double ans;
        if((n+m) % 2) {
            int tempAns = INT_MAX;
            if(rs1 < n) tempAns = nums1[rs1];
            if(rs2 < m) tempAns = min(tempAns, nums2[rs2]);
            ans = tempAns;
        }
        else {
            int leftPart = INT_MIN;
            if(le1 >= 0) leftPart = nums1[le1];
            if(le2 >= 0) leftPart = max(leftPart, nums2[le2]);

            int rightPart = INT_MAX;
            if(rs1 < n) rightPart = nums1[rs1];
            if(rs2 < m) rightPart = min(rightPart, nums2[rs2]);

            ans = ((double)(leftPart) + rightPart) / 2;
        }

        return ans;
    }

public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // we want to do binary search on the smaller array only...
        return (nums1.size() < nums2.size() ? helper(nums1, nums2) : helper(nums2, nums1));
    }
};





/*
the below solution was written by me. it works perfectly on cases where there are unique elems in both the arrays combined
time : O(log(m+n))
intuition : do a binary search on 1 array and for each middle element found, find out how many elems from both the arrays are bigger than this middle elem
for finding the bigger elems in the other array, you can use upper bound
if the middle elem is smaller than more than half the total elems then move right, otherwise move left
and when moving right or left in the first array, also move right/left correspondingly of the upper bound found in the second array, to reduce the search area with each iteration
if not able to find the correct median in first array then repeat the above process for finding the median in second array
*/
class Solution {
private:
    int findMedianIndex(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        int i = 0, j = n-1, mid;
        auto lit = nums2.begin();
        auto rit = nums2.end();

        int halfNumbers = (n+m)/2, greaterNumbers;

        while(i <= j) {
            mid = (i+j)/2;
            auto midit = upper_bound(lit, rit, nums1[mid]);
            greaterNumbers = (n-1 - mid) + distance(midit, nums2.end());

            if(greaterNumbers == halfNumbers) return mid;
            else if(greaterNumbers < halfNumbers) {
                // move left
                j = mid-1;
                rit = midit;
            }
            else {
                i = mid+1;
                lit = midit;
            }
        }

        return -1;
    }

    double returnAns(int medianIndex, vector<int>& nums1, vector<int>& nums2) {
        if((nums1.size() + nums2.size()) % 2) {
            return (double)(nums1[medianIndex]);
        }
        else {
            auto it = upper_bound(nums2.begin(), nums2.end(), nums1[medianIndex]);
            int secondMedian = INT_MAX;
            if(it != nums2.end()) secondMedian = *it;
            if(medianIndex + 1 < nums1.size()) secondMedian = min(nums1[medianIndex+1], secondMedian);

            return ((double)(nums1[medianIndex]) + secondMedian) / 2;
        }
    }

public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int medianIndex = findMedianIndex(nums1, nums2);
        if(medianIndex != -1) {
            return returnAns(medianIndex, nums1, nums2);
        }

        medianIndex = findMedianIndex(nums2, nums1);
        return returnAns(medianIndex, nums2, nums1);
    }
};