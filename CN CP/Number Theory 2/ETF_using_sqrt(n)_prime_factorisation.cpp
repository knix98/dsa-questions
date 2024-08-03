/*
Totient function

You are given an integer N and are supposed to find the value of Euler toient function for N phi(N)

Input Format:
First line of input will contain T(number of test case), each test case follows as.
An integer N in new line.
Output Format:
For each test case print the answer in new line

Constraints:
1 <= T <= 100
1 <= N <= 10^9

Sample Input:
2
20
21
Sample Output:
8 
12
*/


// regarding formula of ETF... refer CN CP number-theory-2 hand notes 
// IMP : please look at the method of doing prime factorisation of n in sqrt(n) time code below
#include<bits/stdc++.h>
using namespace std;

#define ll long long

ll eulerTotientFunc(ll n){
    ll ans = n;

    // we are going to do something similar to prime factorisation of n in the below for loop
    ll temp = n;
    for(ll i = 2; i*i <= n; i++){   // here each i signifies a possible divisor of n, and we will go till sqrt(n) only
        if(temp == 1) break;  // means prime factorisation of n is complete 
        
        if((temp % i) == 0){
            // that means i is one of the prime factors of n

            ans = (ans/i) * (i-1);  // euler totient formula

            while((temp % i) == 0){   // removing all the powers of i from temp, just like we do in prime factorisation
                temp /= i;
            }
        }
    }

    // after the above loop temp == 1 || temp == (some prime number)
    // hence if temp != 1, then temp is the last remaining prime divisor of n
    if(temp != 1) ans = (ans/temp) * (temp-1);

    return ans;
}

int main(){
    int t;
    cin >> t;

    vector<ll> ans;
    while(t--){
        ll n;
        cin >> n;
        ans.push_back(eulerTotientFunc(n));
    }

    for(auto i : ans) cout << i << endl;
    
    return 0;
}