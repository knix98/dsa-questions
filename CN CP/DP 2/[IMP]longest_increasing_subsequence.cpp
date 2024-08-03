/*
https://classroom.codingninjas.com/app/classroom/me/22205/content/575428/offering/8883019/problem/7226
*/



#include<bits/stdc++.h>
using namespace std;

// METHOD 1 : using segment tree (I have used iterative segment tree here, which is easier and faster to write)
class SegmentTree{
    int n = 200000;
    vector<int> st;

    public: 
    SegmentTree(){
        st = vector<int>(4*n, 0);
    }

    void update(int idx, int v){
        int st_idx = idx + n;
        st[st_idx] = v;

        while(st_idx > 1){
            st_idx /= 2;
            st[st_idx] = max(st[2*st_idx], st[2*st_idx + 1]);
        }
    }

    int max_range_query(int l, int r){
        l += n;
        r += n;
        int ans = 0;
        
        while(l<=r){
            if(l&1){  // means l is left end of range, but right child of its parent
                // so instead of taking l's parent contribution in ans, we take only l's contribution in ans
                ans = max(st[l], ans);
                l++;
            }
            if(!(r&1)){  // means r is right end of range, but left child of its parent
                // so instead of taking r's parent contribution in ans, we take only r's contribution in ans
                ans = max(st[r], ans);
                r--;
            }

            l /= 2;
            r /= 2;
        }

        return ans;
    }
};

// approach is : dp[i] = LIS starting with arr[i] being the last(or largest) element in sequence
// so for finding dp[i], we need to find a dp[x] such that x < i and also arr[x] < arr[i] => for this we would use segment tree (because we want to do a range query in the range [0, arr[i]))
int longestIncreasingSubsequence(int arr[], int n)
{
    int ans = 0;
    int dp[n];

    SegmentTree st; // the array from which we would build the segment tree would contain arr[i] as indices and dp[i] as values
    int SCALE_UP = 100000;  // this is required because, -1e5 <= arr[i] <= 1e5, but the array used for building the segment tree should contain indices >=0
                            // so we will shift the arr[i] by 1e5
                            

    for(int i=0; i<n; i++){
        int idx = arr[i] + SCALE_UP;
        dp[i] = st.max_range_query(0, idx-1) + 1;  // (o, idx-1) because as we discussed earlier that we want the max_query in the range [0, arr[i])
        st.update(idx, dp[i]);
        ans = max(ans, dp[i]);
    }

    return ans;
}



// METHOD 2 : striver method, binary search
// this method just works. there is no intuition/logic to this. So I would say use METHOD 1 only which has some logic to it 
int longestIncreasingSubsequence(int arr[], int n){
    vector<int> ans;
    // ans.push_back(arr[0]);
    for(int i=0; i<n; i++){
        auto it = lower_bound(ans.begin(), ans.end(), arr[i]);
        if(it == ans.end()){
            ans.push_back(arr[i]);
        }
        else{
            *it = arr[i];
        }
    }

    return ans.size();
}