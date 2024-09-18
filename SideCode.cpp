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
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<vector<int>> pq;

        int dist;
        for(auto v : points) {
            dist = (v[0]*v[0]) + (v[1]*v[1]);
            if(pq.size() < k) {
                pq.push({dist, v[0], v[1]});
            }
            else if(pq.top()[0] > dist) {
                pq.pop();
                pq.push({dist, v[0], v[1]});
            }
        }

        vector<vector<int>> ans;
        vector<int> v;
        while(!pq.empty()) {
            v = pq.top();
            pq.pop();
            ans.push_back({v[1], v[2]});
        }

        return ans;
    }
};

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> prev(amount + 1, -1);
        prev[0] = 0;
        vector<int> curr(amount + 1);

        int ans = -1;

        for(int coin : coins) {
            curr[0] = 0;
            for(int i=1; i<=amount; i++) {
                curr[i] = -1;
                if(i - coin >= 0 && curr[i-coin] >= 0) curr[i] = 1 + curr[i-coin];
                if(prev[i] >= 0) {
                    if(curr[i] == -1) curr[i] = prev[i];
                    else curr[i] = min(prev[i], curr[i]);
                }
            }

            if(curr[amount] != -1) {
                if(ans == -1) ans = curr[amount];
                else ans = min(ans, curr[amount]);
            }
            prev = curr;
        }

        return ans;
    }
};




/*
In our problem statement we have arrays that represents a number. 
Array a = [2, 0, 1, 6] 
The above array represents the number 2016. 
Write a function that takes two arrays, and returns an integer which represents the addition of the numbers represented by the two arrays. output should be an array, not an integer. 
Example: 
a = [1, 0, 6] 
b = [8, 9, 9] 
The output should be 
[1, 0, 0, 5]
*/

vector<int> solve(vector<int> &a, vector<int> &b) {
    if(b.size() > a.size()) return solve(b, a);
    int m = a.size(), n = b.size();

    vector<int> ans;

    int i = m-1;
    int j = n-1;

    int carry = 0, sum;
    while(j >= 0) {
        sum = a[i] + b[j] + carry;
        if(sum >= 10) {
            carry = 1;
            sum = sum % 10;
        }
        else carry = 0;

        ans.push_back(sum);
        i--, j--;
    }

    while(i >= 0) {
        sum = a[i] + carry;
        if(sum >= 10) {
            carry = 1;
            sum = sum % 10;
        }
        else carry = 0;

        ans.push_back(sum);
        i--;
    }

    if(carry) ans.push_back(carry);

    // i=0, j = ans.size() - 1;

    // while(i < j) {
    //     int temp = ans[i];
    //     ans[i] = ans[j];
    //     ans[j] = temp;
    //     i++, j--;
    // }

    reverse(ans.begin(), ans.end());

    return ans;
}

vector<int> mul_helper(vector<int> &a, int b, int zeroes) {
    vector<int> ans;

    int carry = 0, mul;
    for(int i=a.size()-1; i>=0; i--) {
        mul = (a[i] * b) + carry;
        if(mul >= 10) {
            carry = mul/10;
            mul = mul % 10;
        }
        else carry = 0;

        ans.push_back(mul);
    }

    if(carry) ans.push_back(carry);
    reverse(ans.begin(), ans.end());
    while(zeroes--) ans.push_back(0);

    return ans;
}

vector<int> multiply(vector<int> &a, vector<int> &b) {
    if(a.size() == 0 || b.size() == 0) return {};
    if(a.size() < b.size()) return multiply(b, a);

    vector<int> prev, curr;
    int zeroes = 0;
    prev = mul_helper(a, b.back(), zeroes++);

    for(int i=b.size()-2; i>=0 ; i--) {
        curr = mul_helper(a, b[i], zeroes++);
        prev = solve(prev, curr);
    }

    return prev;
}

int main() {
    /*
    1.  
a = [1, 2, 3]
b = [4, 5, 6]
ans: [5, 7, 9]

2.  
a = [9, 9, 9]
b = [1]
ans: [1, 0, 0, 0]

3.  
a = []
b = [2, 3, 4]
ans: [2, 3, 4]


4.  
a = [0, 1, 2]
b = [0, 9, 9]
ans: [1, 1, 1]


5.  
a= [4, 1, 8, 9, 9, 0]
b= [2, 2, 3, 3]
ans: [4, 2, 1, 2, 2, 3]


6.  
a= [1, 0, 6]
b = [8, 9, 9]
ans: [1, 0, 0, 5]
    */
    vector<int> a = {1,0,6};    
    vector<int> b = {8,9,9};   

    vector<int> ans = multiply(a, b);

    for(int i : ans) cout << i << " "; 
}

// 7 1 6 5 4 3

/*
Input: nums = [0,1,0,3,12]
Output: [1,3,12,0,0]
*/
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int zs = -1, ze, n = nums.size();
        for(int i = 0; i<n; i++) {
            if(nums[i] == 0) {
                if(zs == -1) zs = ze = i;
                else ze = i;
            }
            else {
                if(zs != -1) {
                    swap(nums[zs], nums[i]);
                    zs++;
                    ze++;
                }
            }
        }
    }
};