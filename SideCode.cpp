#include <bits/stdc++.h>
using namespace std;

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

class Solutions {
private:
    double helper(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        int half = (n+m)/2;
        bool partitionFound = false;

        int i = 0, j = n-1, le1, rs1, le2, rs2;
        while(i < j) {
            le1 = (i+j)/2;
            le2 = half - le1 - 2;
            rs1 = le1 + 1;
            rs2 = le2 + 1;

            if(nums1[le1] > nums2[rs2]) {
                // move left
                j = le1 - 1;
            }
            else if(le2 >= 0 && nums2[le2] > nums1[rs1]) {
                // move right
                i = le1 + 1;
            }
            else {
                // we found the perfect partition in both the vectors
                partitionFound = true;
                break;
            }
        }

        cout << le1 << " " << rs1 << " " << le2 << " " << rs2 << " " << partitionFound << endl;
 
        if(!partitionFound) {
            // means all elems in the left partition of combined array would belong to nums2 only
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
        return (nums1.size() < nums2.size() ? helper(nums1, nums2) : helper(nums2, nums1));
    }
};

int main() {
    // vector<int> v = {1,2,3,4,5};
    // auto lit = v.begin();
    // auto rit = v.end();

    // // auto it = upper_bound(lit, rit, 3);
    // // cout << *it << " " << *lit << " " << *rit << endl;
    // // rit = lit;
    // // lit = it;
    // // it = upper_bound(lit, rit, 2);
    // // cout << *it << " " << *lit << " " << *rit << endl;
    // cout << distance(rit, lit) << endl;
    // int num = 2;
    // // double d = static_cast<double>(num); // Convert integer to double

    // cout << fixed << setprecision(5) << (double)num << endl;

    vector<int> v1 = {1};
    vector<int> v2 = {2,3};

    Solutions s;
    cout << s.findMedianSortedArrays(v1, v2);
}

class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0]; 

        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(4, 0));

        dp[n-1][0] = dp[n-2][3] = nums[n-1];
        dp[n-2][0] = dp[n-2][2] = nums[n-2];

        for(int i=n-3; i>=0; i--) {
            dp[i][0] = nums[i] + max(dp[i+2][0], dp[i+2][3]);
            dp[i][1] = max(dp[i+1][1], dp[i+1][2]);
            dp[i][2] = nums[i] + max(dp[i+2][1], dp[i+2][2]);
            dp[i][3] = max(dp[i+1][0], dp[i+1][3]);
        }

        return max({dp[0][1], dp[0][2], dp[0][3]});
    }
};