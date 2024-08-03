/*
https://leetcode.com/problems/subarrays-with-k-different-integers/description/
*/


// Method 1 : better intuitive : from striver youtube
int subarraysWithAtMaxKDistinct(vector<int>& nums, int k) {
    unordered_map<int,int> fq;

    int ans = 0;
    int l = 0; // left pointer
    int distinct_ints = 0;
    for(int r=0; r<nums.size(); r++){
        fq[nums[r]]++;
        if(fq[nums[r]] == 1) distinct_ints++;

        while(distinct_ints > k) {
            fq[nums[l]]--;
            if(fq[nums[l]] == 0) distinct_ints--;
            l++;
        }

        ans += (r-l+1);
    }

    return ans;
}

int subarraysWithKDistinct(vector<int>& nums, int k) {
    // ans = (subarrays with <=k distinct ints) - (subarrays with <=(k-1) ints)
    // we are doing this because getting for <=k is much easier with sliding window
    // then getting for ==k

    return subarraysWithAtMaxKDistinct(nums, k) - subarraysWithAtMaxKDistinct(nums, k-1);
}



// Method 2 : using 3 pointer approach : l_far, l_near and r pointers
// from neetcode youtube
int goodSubarrays(vector<int> &arr ,int n, int k)
{
    int ans = 0;
    unordered_map<int,int> fq;
    int l_near = 0, l_far = 0;
    int distinct_elems = 0;

    for(int r=0; r<n; r++){
        fq[arr[r]]++;
        if(fq[arr[r]] == 1) distinct_elems++;

        while(distinct_elems > k){
            fq[arr[l_near]]--;
            if(fq[arr[l_near]] == 0) distinct_elems--;
            l_near++;
            l_far = l_near; 
        }

        while(fq[arr[l_near]] > 1){
            fq[arr[l_near++]]--;
        }

        if(distinct_elems == k) ans += (l_near - l_far + 1);
    }

    return ans;
}