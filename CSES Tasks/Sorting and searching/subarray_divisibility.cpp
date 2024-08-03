/*
https://cses.fi/problemset/task/1662
*/

#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    ll n;
    cin >> n;
    
    vector<ll> v(n);
    for(int i=0; i<n; i++) cin >> v[i];

    vector<int> fq(n, 0);  // will contain frequencies of (prefix sum of index % n)
    fq[0]++;  // for 0 sum (considering no elems from v)

    ll sum = 0;
    ll ans = 0;
    int rem;
    for(int i=0; i<n; i++){
        sum += v[i];
        rem = ((sum % n) + n) % n;

        ans += fq[rem];

        fq[rem]++;
    }

    cout << ans;

    return 0;
}