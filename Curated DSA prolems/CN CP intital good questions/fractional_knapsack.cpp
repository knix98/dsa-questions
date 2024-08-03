/*
https://classroom.codingninjas.com/app/classroom/me/22205/content/575394/offering/8882372/problem/8314?leftPanelTabValue=PROBLEM

You are given weights and values of N items. You have to select and put these selected items in a knapsack of capacity W. Select the items in such a way that selected items give the maximum total value possible with given capacity of the knapsack.

Note: You are allowed to break the items in parts.

Detailed explanation ( Input/output format, Notes, Images )
Constraints:
1 <= N = 2*10^5
1 <= W <= 10^9
1 <= value, weight <= 10^5
Time Limit: 1 sec
Output Format:
Print the maximum total value upto six decimal places.
Sample Input 1:
4 22
6 4
6 4
4 4
4 4
Sample Output 1:
20.000000
Explanation:
The total weight of all the items is 16 units, which is less than the total capacity of knapsack, i.e 22 units. Hence, we will add all the items in the knapsack and total value will be 20 units.
*/




#include<bits/stdc++.h>
using namespace std;

bool cmp(pair<int, double> &a, pair<int, double> &b){
    return a.second > b.second; // for descending order
}

int main(){
    int w, n;
    cin >> n >> w;

    vector<int> wt(n);
    vector<int> pr(n);

    for(int i=0; i<n; i++){
        cin >> pr[i] >> wt[i];
    }

    // solution begins here...

    // approach is simple => calculate unitPrices of all the n bags, and then sort them in decreasing order
    // so that we can use the highest unitPrice value first for filling up the knapsack
    vector<pair<int, double>> up(n);
    for(int i=0; i<n; i++){
        double temp = (double)(pr[i]) / wt[i]; 
        pair<int, double> p(i, temp);
        up[i]  = p;
    }

    sort(up.begin(), up.end(), cmp);

    int i=0;
    double ans = 0;
    while(i < n && w > 0){
        int index = up[i].first;
        double unitPrice = up[i].second;

        if(wt[index] <= w){ // then substract the whole weight of the bag from the remaining knapsack weight capacity
            w -= wt[index];
            ans += pr[index];
        }
        else{ // else take only that much price of the current bag whose weight value is just able to fill the remaining knapsack weight
            double addToAns = unitPrice*w;
            ans += addToAns;
            w = 0;
        }

        i++;
    }

    // this is how to use fixed along with setprecision to get upto 6 decimal places for a double value
    cout << fixed << setprecision(6) << ans; 

    return 0;
}