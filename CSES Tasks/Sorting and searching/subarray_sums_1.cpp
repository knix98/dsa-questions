/*
https://cses.fi/problemset/task/1660
*/


// sliding window solution
#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    ll n, t;
    cin >> n >> t;
    
    vector<ll> v(n);
    for(int i=0; i<n; i++) cin >> v[i];

    ll sum = 0;
    ll ans = 0;
    int i=0, j=0;
    bool addJ = true;
    while(i<n && j<n){
        if(addJ) sum += v[j];

        if(sum == t) {
            ans++; 
            sum -= v[i]; 
            i++;
            addJ = false; // whenever i advances, addJ = false, and doing sum -= v[i] already done
            if(j<i) j++, addJ = true; // whenever j advances, addJ = true
        }
        else if(sum < t) j++, addJ = true; // whenever j advances, addJ = true
        else{
            sum -= v[i]; 
            i++;
            addJ = false; // whenever i advances, addJ = false, and doing sum -= v[i] already done
            if(j<i) j++, addJ = true; // whenever j advances, addJ = true
        } 
    }

    cout << ans;

    return 0;
}