/*
https://classroom.codingninjas.com/app/classroom/me/22205/content/575413/offering/8882740/problem/8826
*/


// intuition and approach is written in CN CP hand notes of Combinatorics 1 chapter
#include<bits/stdc++.h>
using namespace std;

#define ll long long

int mod = 1e9 + 7;

ll fact[200001];

ll mod_pow(ll a, ll b){
    ll res = 1;
    while(b) {
        if(b&1) res = (res*a) % mod;

        a = (a*a) % mod;
        b /= 2;
    }

    return res;
}

int main(){
    fact[0] = 1;
    for(int i=1; i<=200000; i++) fact[i] = (i * fact[i-1]) % mod;

    int t;
    cin >> t;

    ll n, m, res;
    while(t--){
        cin >> n >> m;
        ll temp = (fact[2*m] * fact[n-1]) % mod;
        res = (fact[(2*m) + n - 1] * mod_pow(temp, mod-2)) % mod;

        cout << res << endl;
    }

    return 0;
}