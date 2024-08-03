/*
Segmented Sieve Problem

In this problem you have to print all primes from given interval.
Input Format:
First line of input will contain T(number of test cases), each test case follows as.

On each line are written two integers L and U separated by a blank. L - lower bound of 
interval, U - upper bound of interval.
Output Format:
For each test case output must contain all primes from interval [L; U] in increasing order.
Constraints:
1  <= T <= 100
1 <= L <= U <= 10^9
0 <= U - L <= 10^5
Sample Input:
2
2 10
3 7
Sample Output:
2 3 5 7
3 5 7 
*/



// Approach : since l,u can be as hish as 10^9 , we cant make that big array
// So we will make array of size (u-l+1) with index starting from 0 
// And we know (from sieve of eratosthenes) we have to check all prime numbers till sqrt(u) only and cancel their multiples which lie within the given range
// So we will get all the prime numbers till 10^5 first hand only, and use them for all the test cases
// Time : we are implementing basically sieve algo only here , so time comp. same as sieve = O(n*loglog(n)), (where log is base 2)

#include<bits/stdc++.h>
using namespace std;

#define ll long long

vector<int> primes(100000, 1);

void preparePrimes(){ // one time function
    primes[0] = primes[1] = 0;
    
    for(ll i=2; i<100000; i++){
        if(primes[i]){
            for(ll j=i*i; j<100000; j+=i){
                primes[j] = 0;
            }
        }
    }
}

vector<ll> sieve(ll l, ll u){
    vector<ll> currPrimes((u-l)+1, 1);
    
    if(l == 1) currPrimes[0] = 0; // since 1 is obviously not a prime number

    for(ll i=2; (i*i)<=u; i++){ // we want to check primes till sqrt(u) only
        if(primes[i]){
            ll firstMultipleOfIWithinRange = i*i;  // trying to find => first multiple of i within the range [l, u]
            if(firstMultipleOfIWithinRange < l){
                firstMultipleOfIWithinRange = (l/i)*i;
                if(firstMultipleOfIWithinRange < l){
                    firstMultipleOfIWithinRange += i;
                }
            }

            for(ll j = firstMultipleOfIWithinRange; j<= u; j+=i){
                currPrimes[j-l] = 0;
            }
        }
    }

    vector<ll> ans;
    for(ll i=0; i<currPrimes.size(); i++){
        if(currPrimes[i]) ans.push_back(i+l);
    }

    return ans;
}

int main(){
    int t;
    cin >> t;

    vector<pair<ll, ll>> cases; // collecting all the lower (l) and upper (u) values first
    while(t--){
        pair<ll, ll> temp;
        cin >> temp.first >> temp.second;

        cases.push_back(temp);
    }

    preparePrimes(); // since max value of upper can be 10^9 , so lets first hand , get all the primes uptill 10^5 (since sqrt(u) < 10^5)

    for(auto i : cases){
        vector<ll> primes = sieve(i.first, i.second);
        for(auto j : primes) cout << j << " ";
        cout << endl;
    }

    return 0;
}