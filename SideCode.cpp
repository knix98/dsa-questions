#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n == 0) return 0;

        int bought_state_profit = prices[n-1];
        int sold_state_profit = 0;

        int curr_bsp, curr_ssp;
        for(int i=n-2; i>=0; i--) {
            curr_bsp = max(prices[i] + sold_state_profit, bought_state_profit);
            curr_ssp = max(bought_state_profit - prices[i], sold_state_profit);
            bought_state_profit = curr_bsp;
            sold_state_profit = curr_ssp;
        }

        return sold_state_profit;
    }
};

bool isAnagram(string s1, string s2) {

    int fq[256] = {0};

    int ascii;
    for(char c : s1) {
        ascii = (int)c;
        if(ascii <= 90) ascii = ascii - 65 + 97;
        // cout << ascii << endl;
        fq[ascii]++;
    }
    for(char c : s2) {
        ascii = (int)c;
        if(ascii <= 90) ascii = ascii - 65 + 97;
        // cout << ascii << endl;
        fq[ascii]--;
    }

    for(int i=0; i<256; i++) if(fq[i] != 0) return false;

    return true;
}

void maxProfit(vector<int> &prices, int profit, int i, int &ans, char state) {
    if(i == prices.size()) {
        ans = max(ans, profit);
        return;
    }

    if(state == 'B') {
        maxProfit(prices, profit + prices[i], i+1, ans, 'S');
        maxProfit(prices, profit, i+1, ans, 'B');
    }
    else {
        maxProfit(prices, profit - prices[i], i+1, ans, 'B');
        maxProfit(prices, profit, i+1, ans, 'S');
    }
}

int main() {
    vector<int> prices = {6,4,5,3};
    int ans = 0;
    maxProfit(prices, 0, 0, ans, 'S');
    cout << ans;
}

// 7 1 6 5 4 3
