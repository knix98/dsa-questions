/*
LCM SUM - SPOJ

Given n, calculate the sum LCM(1,n) + LCM(2,n) + .. + LCM(n,n), where LCM(i,n) denotes the Least Common Multiple of the integers i and n.

Input
The first line contains T the number of test cases. Each of the next T lines contain an integer n.

Output
Output T lines, one for each test case, containing the required sum.

Example
Sample Input:
3
1
2
5

Sample Output:
1
4
55
Constraints
1 <= T <= 300000
1 <= n <= 1000000
*/




// this can be simply solved using formula for LCM SUM written in hand notes
// But we need to calculate divisorPhiSum (sigma in the LCMSUM formula) values for all n initially only to avoid TLE
#include<bits/stdc++.h>
using namespace std;

#define ll long long

vector<int> phi(1000001);
vector<ll> divisorPhiSum(1000001, 1); // pre-adding 1 as divisor of every number, since obviously 1 is divisor of every number

void sieveForPhi(){
    for(int i=0; i<=1000000; i++) phi[i] = i;

    for(int i=2; i<=1000000; i++){
        if(phi[i] == i) { // means i is a prime number
            for(int j=i; j<=1000000; j+=i){
                phi[j] -= (phi[j] / i);
            }
        }
    }
}

void sieveForDivisorPhiSum(){
    for(ll i=2; i<=1000000; i++){  
        for(ll j=i; j<=1000000; j+=i){  // for every j whose divisor is i...
            divisorPhiSum[j] += (i * phi[i]);
        }
    }
}

int main() {
    sieveForPhi();
    sieveForDivisorPhiSum();

    int t;
    cin >> t;

    vector<ll> answers;
    while(t--){
        int n;
        cin >> n;

        ll ans = ((divisorPhiSum[n] + 1) * n) / 2; // based on the formula for LCM SUM written in hand notes
        answers.push_back(ans);
    }

    for(auto answer : answers) cout << answer << endl;
}