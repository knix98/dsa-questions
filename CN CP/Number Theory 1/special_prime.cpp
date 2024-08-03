/*
Special Prime

Special Prime is a prime number that can be written as the sum of two neighbouring primes and 1.
You are given an integer N and you are supposed to find the number special prime in the range: [1, N].
Example of special prime 19 = 7 + 11 + 1
Neighbouring primes are prime number such that there is no other prime number between them.

Input Format:
An integer N.
Output Format:
Print the number of special primes

Constraints:
1 <= N <= 2*10^5

Sample Input:
27
Sample Output:
2
*/



#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    int n;
    cin >> n;

    vector<int> isPrime(n+1, 1);
    isPrime[0] = isPrime[1] = 0;

    vector<int> primes;  // this will store all the prime numbers that are within the range [2,n]

    for(ll i=2; i<=n; i++){
        if(isPrime[i]){
            primes.push_back(i);

            for(ll j = i*i; j<=n; j+=i){
                isPrime[j] = 0;
            }
        }
    }

    int ans = 0;
    for(int i=1; i<primes.size(); i++){
        int check = primes[i] + primes[i-1] + 1;
        if(check > n) break;  // because now no point of going forward in loop , since every time check would be > n
        if(isPrime[check]) ans++;
    }

    cout << ans;
    
    return 0;
}