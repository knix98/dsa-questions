/*
https://classroom.codingninjas.com/app/classroom/me/22205/content/575394/offering/8882379/problem/8950

You are given N jobs where every job is represented as:

1. Start Time

2. Finish Time

3. Profit Associated

Find the maximum profit subset of jobs such that no two jobs in the subset overlap.

Detailed explanation ( Input/output format, Notes, Images )
Constraints:
1 ≤ N ≤ 10^6
1 ≤ ai, di, p ≤ 10^6
Output Format:
Output one integer, the maximum profit that can be achieved.
Sample Input 1
4
3 10 20
1 2 50
6 19 100
2 100 200
Sample Output 1
250
*/


// APPROACH : have used DP here. first sort the jobs according to start times and then start from the last job(end of array).
// at any given index we have to calculate 2 things : max profit in the array starting from current index when : 1. job[i] is included
// 2. job[i] is not included

// Code 1 : using custom lowerBound
#include<bits/stdc++.h>
using namespace std;

#define ll long long

struct job{
    int st;
    int en;
    int p;
};

bool cmp(job &a, job &b){
    return a.st < b.st;
}

// this func would return the index i such that v[i].st is equal or just greater than the val passed as argument
// if more than 1 v[i].st match val, then this func would return the first of those indexes
int lowerBound(vector<job> &v, int i, int j, int val){
    int mid, ans = -1;
    while(i<=j){
        mid = (i+j)/2;

        if(v[mid].st >= val) ans = mid, j = mid-1;
        else i = mid+1; 
    }

    return ans;
}

int main(){
    int n;
    cin >> n;

    vector<job> v(n);
    for(int i=0; i<n; i++){
        cin >> v[i].st >> v[i].en >> v[i].p;
    } 

    sort(v.begin(), v.end(), cmp);

    ll dp[n];
    dp[n-1] = v[n-1].p;
    for(int i=n-2; i>=0; i--){
        // case 1 : taking the current job v[i]
        int idx = lowerBound(v, i+1, n-1, v[i].en);
        if(idx == -1) dp[i] = v[i].p;
        else dp[i] = v[i].p + dp[idx];

        // case 2 : not taking v[i], so case 2 ans = dp[i+1]
        dp[i] = max(dp[i], dp[i+1]);
    }

    cout << dp[0];

    return 0;
}




// code 2 : using STL lower_bound, but in this case we would have to use a separate vector for storing start times, 
// then only using lower_bound on start times is possible
#include<bits/stdc++.h>
using namespace std;

struct obj{
    int st;
    int en;
    int p;
};

bool cmp(obj &a, obj &b){
    return a.st < b.st;
}

int main(){
    int n;
    cin >> n;

    vector<obj> v(n);
    vector<int> st(n);

    for(int i=0; i<n; i++){
        obj o;
        cin >> o.st >> o.en  >> o.p;
        v[i] = o;
        st[i] = o.st;
    }

    sort(v.begin(), v.end(), cmp);
    sort(st.begin(), st.end());

    int dp[n] = {0};

    dp[n-1] = v[n-1].p;

    for(int i=n-2; i>=0; i--){
        auto it = lower_bound(st.begin() + i + 1, st.end(), v[i].en);

        dp[i] = dp[i+1] > v[i].p ? dp[i+1] : v[i].p;

        if (it != st.end()) {
          int index = it - st.begin();
          int check = dp[index] + v[i].p;
          dp[i] = dp[i] > check ? dp[i] : check;
        }
    }

    cout << dp[0];

    return 0;
}