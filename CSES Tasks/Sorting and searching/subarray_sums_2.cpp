/*
https://cses.fi/problemset/task/1661/
*/

#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    ll n, t;
    cin >> n >> t;
    
    vector<ll> v(n);
    for(int i=0; i<n; i++) cin >> v[i];

    unordered_map<ll, ll> fq;  // will contain frequencies of prefix sums of indexes
    fq[0]++;  // for 0 sum (considering no elems from v)

    ll sum = 0;
    ll ans = 0;
    for(int i=0; i<n; i++){
        sum += v[i];

        if(fq.count(sum - t) > 0) ans += fq[sum-t];

        fq[sum]++;
    }

    cout << ans;

    return 0;
}