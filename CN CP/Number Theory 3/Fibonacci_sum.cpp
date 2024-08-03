/*
Fibonacci Sum

The fibonacci sequence is defined by the following relation:
 F(0) = 0
 F(1) = 1
 F(N) = F(N - 1) + F(N - 2), N >= 2
Your task is very simple. Given two non-negative integers N and M (N <= M), you have to calculate and return the sum (F(N) + F(N + 1) + ... + F(M)) mod 1000000007.

Input Format :
First line of input will contain T(number of test cases), each test case follows as.
Two non-negative space-separated integers N and M. (N <= M)
Output Format :
A new line containing the answer for the each test case.

Constraints:
1 <= T <= 10^3
1 <= N <= M <= 10^18

Sample Input :
1 
10 19 
Sample Output :
10857
*/



// Explanation and approach and formula has been written in hand notes
// plz look at this code to understand the codes for matrix multiplication, matrix exponentiation
#include<bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;

// this func would multiply matrix a with matrix b (both having nxn dimensions) and store the resultant matrix in matrix b and return
void matrixMultiply(vector<vector<ll>> &a, vector<vector<ll>> &b, int n){
    vector<vector<ll>> temp(n, vector<ll>(n, 0));

    for(int i=0; i<n; i++){ // traverse over rows of A
        for(int j=0; j<n; j++){ // traverse over cols of B
            for(int k=0; k<n; k++){  // need to multiply each of the n numbers from the selected row (i) and col (j)
                temp[i][j] = ( temp[i][j] + (( a[i][k] * b[k][j] ) % mod) ) % mod;
            }
        }
    }

    for(int i=0; i<n; i++){
        for (int j = 0; j < n; j++) {
            b[i][j] = temp[i][j];
        }
    }
}

int fibo(ll n){
    if(n < 3) return 1;  // f(1) = f(2) = 1;

    vector<vector<ll>> t{{1, 1}, {1, 0}};  // fibonacci transition matrix
    vector<vector<ll>> res{{1, 0}, {0, 1}}; // identity matrix for calculating T^(n-2)

    ll pow = n-2;
    while(pow > 0){
        if((pow % 2) == 1){
            matrixMultiply(t, res, 2);
            pow--;
        }

        if(pow > 0){
            matrixMultiply(t, t, 2);
            pow /= 2;
        }
    }

    int ans = ( res[0][0] + res[0][1] ) % mod;  // written in hand notes
    return ans;
}

int main(){
    int t;
    cin >> t;

    vector<int> answers;
    while(t--){
        ll n,m;
        cin >> n >> m; 

        int ans = (fibo(m+2) - fibo(n+1)) % mod; // since formula is => ans = f(m+2) - f(n+1)
        if(ans < 0) ans = ans + mod; // since whenever dealing with (a-b)%m , always check if ans is negative , then add mod to it
        answers.push_back(ans);  
    }

    for(auto i : answers) cout << i << endl;
    
    return 0;
}