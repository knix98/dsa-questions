/*
GCD Sum

Consider all numbers from 1 to ‘N’, your task is to find the sum of gcd of all pairs (i, j) such that 1 <= i < j <= N.
For example for N = 3, all pairs are { (1, 2), (1, 3), (2, 3) }.
Note :
Gcd of two numbers (X, Y) is defined as the largest integer that divides both ‘X’ and ‘Y’. 
Input Format :
The first line contains an integer 'T' which denotes the number of test cases to be run. The 'T' test cases follow.

The first line of each test case contains an integer ‘N’ representing the given integer.
Output Format :
For each test case, print an integer representing the sum of gcd of all pairs of numbers from 1 to ‘N’.

The output of each test case will be printed in a separate line.
Note :
You do not need to input or print anything, and it has already been taken care of. Just implement the given function.
Constraints :
1 <= 'T' <= 5
1 <= 'N' <= 5000

Time Limit: 1sec
Sample Input 1 :
2
3
5
Sample Output 1 :
3
11
Explanation Of Sample Input 1 :
Test case 1:
gcd(1, 2) + gcd(1, 3) +  gcd(2, 3) = 1 + 1 + 1 = 3.

Test case 2:
gcd(1, 2) + gcd(1, 3) +  gcd(1, 4) + gcd(1, 5) +
gcd(2, 3) + gcd(2, 4) + gcd(2, 5) +
gcd(3, 4) + gcd(3, 5) +
gcd(4, 5)  = 11.
Sample Input 2 :
1
1
Sample Output 2 :
0
Explanation Of Sample Input 2 :
Test case 1:
As there is no possible Paris, so the gcd sum is 0.
*/



// IN question it is asking : for n , find ans = gcd_sum(2) + gcd_sum(3) + .... + gcd_sum(n)
// I have written hand notes regarding how to calculate gcd_sum(i)
// then I have just used arrays for storing precomputed values of gcd_sum(i) and using them for adding up the final answer
#include<bits/stdc++.h>
#define ll long long

bool sieveForPhiDone = false;  // a bool flag, since we have to precompute phi values only once till question contraint for n

int phi[5001];  // array would contain phi values for each index 

ll gcdSumTillN[5001] = {0}; 

ll individualGCDSum[5001] = {0};  // would contain individual gcd sum values for each index

void sieveForPhi(){
    for(int i=0; i<5001; i++) phi[i] = i;

    for(int i=2; i<5001; i++){
        if(phi[i] == i){
            // this means i is a prime number
            // so multiply (i-1)/i in all multiples of this prime number including i itself

            for(int j=i; j<5001; j+=i){
                phi[j] = (phi[j] / i) * (i-1);
            }
        }
    }

    sieveForPhiDone = true;
}

ll calculateIndividualGCDSum(ll n){
    vector<ll> divisors;

    for(int i = 2; i*i <= n; i++){  // starting from i=2, because we dont want 1 and n itself to be counted as divisors in this loop
        if(n % i == 0){
            divisors.push_back(i);
            if(i*i != n) divisors.push_back(n/i);
        }
    }

    // now just push 1 also as divisor, preventing just n itself from being in the divisors, because ques says we have to find sum
    // for n = 5 => (1,5) + (2,5) + (3,5) + (4,5)    only and not include (5,5)
    divisors.push_back(1);

    ll ans = 0;
    for(auto i : divisors){
        ans += (i * phi[n/i]);
    }

    individualGCDSum[n] = ans;

    return ans;
}

long long gcdSum(int n)
{
    if(!sieveForPhiDone) sieveForPhi();

    if(gcdSumTillN[n]) return gcdSumTillN[n];

    ll ans = 0;
    for(int i=2; i<=n; i++){
        if(individualGCDSum[i]){
            ans += individualGCDSum[i];
        }
        else{
            ans += calculateIndividualGCDSum(i);
        }

        gcdSumTillN[i] = ans;
    }

    gcdSumTillN[n] = ans;
    return gcdSumTillN[n];
}