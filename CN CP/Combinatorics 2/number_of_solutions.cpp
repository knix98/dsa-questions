/*
https://classroom.codingninjas.com/app/classroom/me/22205/content/575414/offering/8882758/problem/8788
*/


// beggar's formula
#include<bits/stdc++.h>
using namespace std;

#define ll long long

const ll mod = 1e9 + 7;

ll fact[200001];

ll mod_pow(ll a, ll b) {
    ll res = 1;

    while(b){
        if(b&1) res = (res*a)%mod;

        a = (a*a)%mod;
        b /= 2;
    }

    return res;
}

int main(){
    fact[0] = 1;
    for(ll i=1; i<200001; i++) fact[i] = (fact[i-1] * i) % mod;

    ll t;
    cin >> t;

    ll n, k;
    ll ans;
    while(t--){
        cin >> n >> k;

        ll temp = (fact[k-1] * fact[n]) % mod;
        ans = (fact[n+k-1] * mod_pow(temp, mod-2)) % mod;
        // ans = (ans * mod_pow(fact[k-1], mod-2)) % mod;
        cout << ans << endl;
    }

    return 0;
}