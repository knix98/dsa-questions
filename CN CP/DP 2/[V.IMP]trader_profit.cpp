/*
https://classroom.codingninjas.com/app/classroom/me/22205/content/575428/offering/8883035/problem/7790?leftPanelTabValue=PROBLEM
*/





// a similar problem to this is alyona_and_strings which also utilises 3D DP and the concept of state variable in dp : 
// like in this problem, the state variable can have 2 values : whether you can buy current price or not (not means you can only sell the current price)
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--){
        int k, n;
        cin >> k >> n;

        vector<int> prices(n);
        for(int i=0; i<n; i++) cin >> prices[i];

        vector<vector<int>> prev(2, vector<int>(k+1, 0));
        vector<vector<int>> curr(2, vector<int>(k+1, 0));

        // we will reduce the k count only when we sell (signifying the end of a transaction)
        // when k==0, we cant buy/sell . So at k==0 , profit ==0

        for(int i=n-1; i>=0; i--){
            for(int j=1; j<=k; j++){ // starting from k=1, because k=0, base case is already set
                // first lets fill: we cannot buy at curr index, means we can only sell
                // case 1 : we sell at curr index
                curr[0][j] = prev[1][j-1] + prices[i];

                // case 2 : we dont sell at curr index
                curr[0][j] = max(curr[0][j], prev[0][j]);

                // now lets fill: we cannot sell at curr index, means we can only buy
                // case 1 : we buy at curr index
                curr[1][j] = prev[0][j] - prices[i];

                // case 2 : we dont buy at curr index
                curr[1][j] = max(curr[1][j], prev[1][j]);
            }

            prev = curr;
        }

        cout << curr[1][k] << endl;  // ans = profit when you can buy and you have all k transactions remaining at 0th index
    }
    
    return 0;
}