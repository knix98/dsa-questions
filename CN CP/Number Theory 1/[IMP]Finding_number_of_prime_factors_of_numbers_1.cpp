/*
Super Prime

A number is called super-prime if it has exactly two distinct prime divisors
Example 10 , 6
You are supposed to find the count of super-prime numbers between 1 and N (inclusive).
Input Format:
Contain an integer N
Output Format:
Print the number of super prime between [1, N]
Constraints:
1 <= N <= 10^6
Sample Input 1:
10
Sample Output 1:
2
Sample Input 2:
25
Sample Output 2:
10
Explanation:
The super-primes are: 6, 10, 12, 14, 15, 18, 20, 21, 22, 24.
*/



// for finding number of prime factors , we can use sieve algo, since in sieve algo we basically visit every multiple of prime numbers in the range 
// so by visiting numbers in this way we can keep increasing their count to signify that they are multiples of how many prime numbers
#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    int n;
    cin >> n;

    // a vector for storing prime factors of i
    vector<int> primeFactors(n+1, 0);  // intially we mark every index with having 0 prime factors, we will count them

    for(int i=2; i*2<=n; i++){
        if(!primeFactors[i]){  // means a prime number has been encountered
            primeFactors[i] = 1;  // since prime number only have 1 prime factor (that is itself)
            for(int j = i*2; j<=n; j+=i){  // also we starting from 2*i instead of i*i because for example otherwise 10 wouldnt be marked by 5
                primeFactors[j]++; // increasing a prime factor in every multiple of the current prime number
            }
        }
    }   

    int ans = 0;
    for(int i=4; i<=n; i++){   // starting from i=4, since obviously 2 and 3 doesnt have 2 prime factors
        if(primeFactors[i] == 2) ans++;
    } 

    cout << ans;
    
    return 0;
}