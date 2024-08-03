/*
leetcode link : https://leetcode.com/problems/minimize-the-maximum-difference-of-pairs/
*/


// APPROACH 1 : DP solution
// Time : O(nlogn + n*p), Space : O(n*p)
int minimizeMax(vector<int> &nums, int p) {
    int n = nums.size();
    sort(nums.begin(), nums.end());  // since obviously the smallest difference pairs would be the ones, which are adjacent to each other after sorting

    int dp[n+1][p+1];  // dp[i][j] = ans when last i elems only are considered and j pairs needs to be made
    for(int i=0; i<n+1; i++){
        for(int j=0; j<p+1; j++){
            dp[i][j] = INT_MAX;
        }
    }

    for(int i=2; i<=n; i++){  // starting from 2 , since only 1 or 0 elems can not form pairs
        for(int j=1; j<=(i/2); j++){  // since its not possible to form more than i/2 pairs when only i elems available
            if(j == 1) dp[i][j] = nums[(n-i)+1] - nums[n-i]; // case 1 : taking only the first pair(first 2 nums of the arr) as the 1 pair required
            else if(dp[i-2][j-1] < INT_MAX) {  // case 2 : taking the first pair when >1 pairs are required (but only when dp[i-2][j-1] is possible)
                dp[i][j] = max(dp[i-2][j-1], nums[(n-i)+1] - nums[n-i]);
            }
            
            // case 3 : not taking the first elem
            dp[i][j] = min(dp[i][j], dp[i-1][j]);
        }
    }

    return dp[n][p];
}



// APPROACH 2 : greedy and binary search
// Time : O(nlogn + logm) , where m = diff between min and max num in the arr
// for intuition can read this editorial -> https://leetcode.com/problems/minimize-the-maximum-difference-of-pairs/editorial/
// or can refer to youtube video also. The main imp intuition is for why the greedy approach works here instead of dp
int minimizeMax(vector<int>& nums, int p) {
    int n = nums.size();
    sort(nums.begin(), nums.end());

    int i = 0, j = nums[n-1] - nums[0];  // binary search range

    int mid, maxDiff, ans=j;
    while(i<=j){
        mid = (i+j)/2;
        maxDiff = mid;

        int k=0;
        int pairsFound = 0;
        while(k < n-1){
            if(nums[k+1] - nums[k] <= maxDiff) pairsFound++, k+=2;
            else k+=1;
        }

        if(pairsFound >= p) ans = mid, j=mid-1;
        else i=mid+1;
    }

    return ans;
}