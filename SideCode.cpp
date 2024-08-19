#include <bits/stdc++.h>
using namespace std;

// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         int n = prices.size();
//         if(n == 0) return 0;

//         int bought_state_profit = prices[n-1];
//         int sold_state_profit = 0;

//         int curr_bsp, curr_ssp;
//         for(int i=n-2; i>=0; i--) {
//             curr_bsp = max(prices[i] + sold_state_profit, bought_state_profit);
//             curr_ssp = max(bought_state_profit - prices[i], sold_state_profit);
//             bought_state_profit = curr_bsp;
//             sold_state_profit = curr_ssp;
//         }

//         return sold_state_profit;
//     }
// };

// bool isAnagram(string s1, string s2) {

//     int fq[256] = {0};

//     int ascii;
//     for(char c : s1) {
//         ascii = (int)c;
//         if(ascii <= 90) ascii = ascii - 65 + 97;
//         // cout << ascii << endl;
//         fq[ascii]++;
//     }
//     for(char c : s2) {
//         ascii = (int)c;
//         if(ascii <= 90) ascii = ascii - 65 + 97;
//         // cout << ascii << endl;
//         fq[ascii]--;
//     }

//     for(int i=0; i<256; i++) if(fq[i] != 0) return false;

//     return true;
// }

// void maxProfit(vector<int> &prices, int profit, int i, int &ans, char state) {
//     if(i == prices.size()) {
//         ans = max(ans, profit);
//         return;
//     }

//     if(state == 'B') {
//         maxProfit(prices, profit + prices[i], i+1, ans, 'S');
//         maxProfit(prices, profit, i+1, ans, 'B');
//     }
//     else {
//         maxProfit(prices, profit - prices[i], i+1, ans, 'B');
//         maxProfit(prices, profit, i+1, ans, 'S');
//     }
// }

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& v, int k) {
        deque<int> dq;
        vector<int> ans;

        for(int i=0; i < v.size(); i++){
            while(!dq.empty() && v[dq.back()] <= v[i]) dq.pop_back();

            dq.push_back(i);

            while(dq.front() <= i-k) dq.pop_front();

            if(i >= k-1)  ans.push_back(v[dq.front()]);
        }

        return ans;
    }
};

int main() {
    vector<int> fq(256, 0);
    string s = "abcde";
    // for(char c : s) fq[c]++;
    // for(int i=0; i<256; i++) {
    //     if(fq[i] > 0) cout << i << " " << fq[i] << endl;
    // }
    cout << s.substr(1, 2);
}

// 7 1 6 5 4 3


class Solution {
public:
    // string minWindow(string s, string t) {
    //     unordered_map<char, int> fr; // will store chars which appear in string t

    //     // storing chars from string t in map
    //     for(int i=0; i<t.size(); i++){
    //         fr[t[i]]--;
    //     }

    //     string ans = "";
    //     int everyCharPresent = 0; 
    //     string sw = "";
    //     int minLength = INT_MAX;
    //     for(int i=0; i<s.size(); i++){
    //         if(sw.size() == 0 && fr.count(s[i]) == 0){
    //             continue;
    //         }
            
    //         sw += s[i];

    //         if(fr.count(s[i]) > 0){
    //             fr[s[i]]++;
    //             if(fr[s[i]] == 0){
    //                 everyCharPresent++;
    //             }

    //             if(fr[s[i]] > 0){
    //                 while(fr.count(sw[0]) == 0 || fr[sw[0]] > 0){
    //                     if(fr.count(sw[0]) > 0){
    //                         fr[sw[0]]--;
    //                     }
    //                     sw = sw.substr(1);
    //                 }
    //             }
    //         }

    //         if(everyCharPresent == fr.size()){
    //             if(minLength > sw.size()){
    //                 minLength = sw.size();
    //                 ans = sw;
    //             }
    //         }
    //     }

    //     return ans;
    // }

    string minWindow(string s, string t) {
        unordered_map<char, int> fr; // will store chars which appear in string t
        
        // storing chars from string t in map
        for(int i=0; i<t.size(); i++){
            fr[t[i]]++;
        }

        int st = 0, en = 0; // 2 pointers for traversing on string s
        int tCounter = 0; // will be updated when chars of t encountered in s

        // this 2 variables are for string the answer string starting index and length
        int minLength = INT_MAX;
        int minSt = 0;

        while(en < s.size()){
            // fr[s[en]]--; // decrease in map

            // if(fr[s[en]] >= 0){ // if this char was part of string t then it would have been a positive number before decrementing
            //     tCounter++;
            // }

            if(--fr[s[en]] >= 0){ // above 2 commented steps in 1 step
                tCounter++;
            }

            while(tCounter == t.size()){  // means en have reached a position from st in between which we have found all chars of t
                if(minLength > en - st + 1) { // checking the dimensions of current window
                    minLength = en - st + 1;
                    minSt = st;
                }

                // if(++fr[s[st]] > 0){ // increasing the count of char at st because we are going to move st forward
                //     tCounter--; // if the char recently removed from window was part of t 
                // }

                // st++; // reduce the size of window by moving st forward

                if(++fr[s[st++]] > 0){ // above 2 commented steps in 1 step
                    tCounter--;
                }
            }

            en++;
        }

        return minLength == INT_MAX ? "" : s.substr(minSt, minLength);
    }
};