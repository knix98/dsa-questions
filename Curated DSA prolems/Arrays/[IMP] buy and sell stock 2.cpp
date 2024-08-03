/*
https://classroom.codingninjas.com/app/classroom/me/11692/content/204216/offering/2653314/problem/13746?leftPanelTabValue=PROBLEM&customSource=studio_nav

You have been given the prices of 'N' stocks in an array where each array element represents the stock price for that day. 
You need to find the maximum profit which you can make by buying and selling the stocks. 
You may make as many transactions as you want but can not have more than one transaction at a time i.e, 
if you have the stock, you need to sell it first, and then only you can buy it again.

Detailed explanation ( Input/output format, Notes, Images )
Constraints :
1 <= t <= 10^2
0 <= N <= 10^5
Time Limit: 1 sec
Sample Input 1 :
1
7
1 2 3 4 5 6 7
Sample Output 1 :
6
Explanation :
We can make the maximum profit by buying the stock on the first day and selling it on the last day.
Sample Input 2 :
1
7
7 6 5 4 3 2 1
Sample Output 2 :
0
Explanation :
We can make the maximum profit by not buying the stock.

*/


// METHOD 1 : Time O(n), space O(1)
// NOTE : this method 1 technique is applicable only when infinite transactions can be done, and not when finite transactions only to be done
// in case of finite transactions, we have to use DP
// APPROACH : if we plot all the prices on a graph, then it will be clearly visible that...
// maxProfit = summation of all the (height of any positive slope between 2 consecutive prices)
long getMaximumProfit(long *values, int n)
{
    if(n < 2){
        return 0;
    }

    long profit = 0;
    for(int i=1; i<n; i++){
        if(values[i] - values[i-1] > 0){
            profit += values[i] - values[i-1];
        }
    }

    return profit;
}


// METHOD 2 : DP approach. Time O(n), space O(1)
long getMaximumProfit(long *values, int n) {
    if(n < 2) return 0;

    // case 1 : we can buy current price
    long prevbuy, currbuy;  // max profit possible in this case

    // case 2 : we can sell current price
    long prevsell, currsell;  // max profit possible in this case

    // considering only the last price
    prevbuy = 0;
    prevsell = values[n-1];

    for(int i=n-2; i>=0; i--){
        // case 1 : we can buy current price
        // case 1a : we buy it
        currbuy = prevsell - values[i];

        // case 1b : we dont buy it
        currbuy = max(currbuy, prevbuy);

        // case 2 : we can sell current price
        // case 2a : we sell it
        currsell = prevbuy + values[i];

        // case 2b : we dont sell it
        currsell = max(currsell, prevsell);

        prevsell = currsell;
        prevbuy = currbuy;
    }

    return currbuy;  // ans = max profit when we can buy at i==0
}