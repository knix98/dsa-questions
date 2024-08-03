/*
XOR of Natural Numbers

You are given an integer N and asked to find the Xor of first N natural numbers.
Input Format:
The first line of input will contain T(number of test cases), each test case follows as.
The only line of input contains an integer N.
Output Format:
For each test case print the Xor of first N natural number in a new line.
Constraints:
1 <= T <= 10^5
1 <= N <= 10^9
Sample Input:
1 
8
Sample Output:
8
*/


// approach is based on a property of XOR of first n natural numbers , which you can find in CN CP bit manipulation chapter notes
#include<bits/stdc++.h>
using namespace std;

#define ll long long

ll solve(ll &n){
    int check = n % 4;
    if(check == 0) return n;
    if(check == 1) return 1;
    if(check == 2) return n+1;
    if(check == 3) return 0;
}

int main(){
    int t;
    cin >> t;

    vector<ll> ans;

    while(t--){
        ll n;
        cin >> n;

        ans.push_back(solve(n));
    }    

    for(auto i : ans) cout << i << endl;

    return 0;
}