/*
Problem name -> SPOJ -> EKO
*/

#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
 
// APPROACH 1 : binary search approach for finding the answer height. Because we know if amount of wood at some height of cut (W) is lesser than move height down
// and if W is more than move height upwards
int main() {
    int n;
    ll m;
 
    cin >> n >> m;
 
    vector<ll> trees(n);
    ll maxTree = 0;
    for(int i=0; i<n; i++){
        cin >> trees[i];
        maxTree = maxTree > trees[i] ? maxTree : trees[i];
    }
 
    ll ans = 0;
    ll i = 0, j = maxTree;
    while(i <= j){
        ll cut = (i+j)/2;
 
        ll wood = 0;
        for(int k=0; k<n; k++){
            ll check = trees[k] - cut;
            wood += check >= 0 ? check : 0;
        }
 
        // following the template code for binary search algo
        if(wood >= m) {
            ans = cut;
            i = cut + 1;
        }
        else {
            j = cut - 1;
        }
    }
 
    cout << ans;
} 


// APPROACH 2 : Suppose the sorted tree heights are => [1, 4, 7, 9]
// start cutting from the last tree in this way , and in each step keep checking the amount of wood is enough for the answer or not
// cut 1 : at H = 7  =>  w cut in this step = (9-7)*1   (1 is the multiplier here, which will keep on incrementing in each step)
// cut 2 : at H = 4  =>  w cut in this step = (7-4)*2   (since, now 2 trees are getting cut => the last and second-last trees)
// continue in this manner until wood is enough
int main() {
    int n;
    ll m;
 
    cin >> n >> m;
 
    vector<ll> trees(n);
    for(int i=0; i<n; i++){
        cin >> trees[i];
    }
 
    sort(trees.begin(), trees.end());
 
    ll cut = 0;
    int i = n-1;  // starting from last tree
    ll multiplier = 1;
 
    while(m > 0 && i >= 0){
        ll diff = i == 0 ? trees[i] : trees[i] - trees[i-1];
        ll maxWood = diff * multiplier;
 
        if(maxWood < m){
            m -= maxWood;  // remove the amount of wood , which has been cut in this step
            cut += diff;
        } 
        else{  // if maxwood is crossing the limit , then we need to cut at some greater height in this step, and stop our loop after this step
            ll tempDiff = m / multiplier;  // this would give us the floor value for the amount of wood needed to be cut from 1 tree in this step
            if(tempDiff * multiplier < m) tempDiff++;  // if floor value is lesser , than increase floor value by 1
 
            m -= (tempDiff * multiplier);  // now m would have become <= 0 , therefore loop will stop after this iteration
            cut += tempDiff; 
        }
 
        i--;
        multiplier++;
    }
 
    cout << trees[n-1] - cut;
} 