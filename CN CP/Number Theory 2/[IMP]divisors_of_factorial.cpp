/*
Divisors of Factorial

Given a number, find the total number of divisors of the factorial of the number.
Since the answer can be very large, print answer modulo 10^9+7.

Input Format:
The first line contains T, number of test cases.
T lines follow each containing the number N.
Output Format:
Print T lines of output each containing the answer.

Constraints
1 <= T <= 500
0 <= N <= 50000

Sample Input:
3
2
3
4
Sample Output:
2
4
8
*/



// solution approach is simple and along with approach, formula for power of prime number k in n! is also written in hand CN CP notes 
#include<bits/stdc++.h>
using namespace std;

#define ll long long

// precompute all prime numbers till max value of n given in question...using sieve algorithm
vector<int> primes;

void findPrimes(){
    vector<int> isPrime(50001, 1);
    isPrime[0] = isPrime[1] = 0;

    for(int i=2; i<= 50000; i++){
        if(isPrime[i]){
            primes.push_back(i);

            for(ll j = (ll)(i) * i; j<=50000; j+=i){
                isPrime[j] = 0;
            }
        }
    }
}

int main(){
    findPrimes();

    int t;
    cin >> t;

    ll mod = 1e9 + 7;
    vector<ll> answers;

    while(t--){
        ll n;
        cin >> n;

        ll divisors = 1;
        for(auto i : primes){
            if(i > n) break;

            ll prime = i;
            ll primePower = 0;
            while(n/prime > 0){  // this loop is based on the formula for (power of prime number k in n!, written in hand CN CP notes)
                primePower += (n/prime);
                prime *= i;
            }

            divisors = ( (divisors % mod) * ((primePower + 1) % mod) ) % mod;
        }

        answers.push_back(divisors);
    }

    for(auto i : answers) cout << i << endl;
    
    return 0;
}