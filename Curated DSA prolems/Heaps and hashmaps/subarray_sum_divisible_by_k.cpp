/*
https://classroom.codingninjas.com/app/classroom/me/11692/content/204440/offering/2653311/problem/14264?leftPanelTabValue=PROBLEM
*/


#define ll long long

int subArrayCount(vector<int> &arr, int k) {
    unordered_map<int,int> mp;  // mp[i] = this would store count of prefixSums having remainder i when divided by k
    ll prefixSum = 0;
    mp[0] = 1;  // empty subarray

    int ans = 0;
    for(int i : arr){
        prefixSum += i;
        int remainder = ((prefixSum % k) + k) % k;
        ans += mp[remainder];
        mp[remainder]++;
    }

    return ans;
}