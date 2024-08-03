/*
https://classroom.codingninjas.com/app/classroom/me/22205/content/575427/offering/8883000/problem/8271
*/



#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        vector<vector<int>> likes(n, vector<int>(n));
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cin >> likes[i][j];
            }
        }

        // dp[i][j] = number of ways to distribute "candies remaining" (denoted by j) amongst i students
        // j can be equal to 1001 or 0011 or 1111 , denoting that that numbered candy is present or not
        vector<vector<int>> dp(n+1, vector<int>(1<<n, 0));  
        dp[0][0] = 1;  // count 1 when we want to distribute 0 candies amongst o students
        // dp[0][1] = dp[0][2] = ... = dp[0][1<<n] = 0 , because more than 0 candies cant be given to 0 students

        for(int i=1; i<=n; i++){
            for(int mask = 0; mask < (1<<n); mask++){
                // so mask denotes the candies that are remaining with us
                // so we need to check the mask for the remaining candies 
                for(int j=0; j<n; j++){
                    if((mask & (1<<j)) && likes[i-1][j]){
                        // means jth candy is available and also our first student (ith student) likes this jth candy
                        // then we will give this jth candy to this ith student and call recursion for 
                        // distribution amongst rest i-1 students with the remaining candies
                        // for getting the remaining candies, remove the jth candy from the mask
                        dp[i][mask] += dp[i-1][mask ^ (1<<j)];
                    }
                }
            }
        }

        cout << dp[n][(1<<n) - 1] << endl;  // ans would be = when all n students and all candies available (i.e 1111)
    }

    return 0;
}