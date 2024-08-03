/*
https://classroom.codingninjas.com/app/classroom/me/22205/content/575414/offering/8882759/problem/8582
*/


// theory about catalan numbers written in CN CP notes
#include<bits/stdc++.h>
using namespace std;

#define ll long long

const ll mod = 1e9 + 7;

ll catalan_mod[1001] = {0};

int main(){
    catalan_mod[0] = 1;
    for(int i=1; i<1001; i++){
        for(int j=0; j<i; j++){
            // important and dont forget to do mod after each multiplication, since overflow can occur if we miss any 1 intermediate mod
            catalan_mod[i] = (catalan_mod[i] + (catalan_mod[j] * catalan_mod[i-1-j])%mod) % mod;
        }
    }

    int t, n;
    cin >> t;
    while(t--){
        cin >> n;
        cout << catalan_mod[n] << endl;
    }
    
    return 0;
}