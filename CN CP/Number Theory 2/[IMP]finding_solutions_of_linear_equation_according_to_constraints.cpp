/*
Sachin and Varun Problem

Varun and you are talking about a movie that you have recently watched while Sachin is busy teaching Number Theory. Sadly, Sachin caught Varun talking to you and asked him to answer his question in order to save himself from punishment. The question says:
Given two weights of a and b units, in how many different ways you can achieve a weight of d units using only the given weights? Any of the given weights can be used any number of times (including 0 number of times).
Since Varun is not able to answer the question, he asked you to help him otherwise he will get punished.

Note: Two ways are considered different if either the number of times a is used or a number of times b is used is different in the two ways.

Input Format:
The first line of input consists of an integer 
T denoting the number of test cases.
Each test case consists of only one line containing three space-separated integers a, b and d.

Output Format:
For each test case, print the answer in a separate line.

Constraints:
1 ≤ T ≤ 10 ^ 5

1 ≤ a < b ≤ 10 ^ 9

0 ≤ d ≤ 10 ^ 9
Sample Input 1
4
2 3 7
4 10 6
6 14 0
2 3 6
Sample Output 1
1
0
1
2
Explanation
Test case 1: 7 can only be achieved by using 2 two times and 3 one time.

Test case 2: 6 can't be achieved by using 4 and 10. So, 0 ways are there.
*/



// study this code after looking at the explanation about approach written in hand CN CP notes
#include<bits/stdc++.h>
using namespace std;

#define ll long long

ll extendedEuclid(ll a, ll b, ll &x, ll &y){
    if(b == 0){  // base case
        x = 1;
        y = 0;
        return a;
    }

    ll x1, y1;

    ll gcd = extendedEuclid(b, a%b, x1, y1);

    x = y1;
    y = x1 - ((a/b)*y1);

    return gcd;
}

int main(){
    int t;
    cin >> t;

    vector<ll> ans;

    while(t--){
        ll a,b,d;
        cin >> a >> b >> d;

        if(d == 0){
            ans.push_back(1);   // since only 1 solution can exist to ax + by = 0, where a,b >= 1, ... that is (x,y) = (0,0)
            continue;
        } 

        ll x, y;
        ll gcd = extendedEuclid(a, b, x, y);

        if(d % gcd != 0) {  // means no integer solution possible for this eqn
            ans.push_back(0);
            continue;
        }

        // create actual solution of our eqn : ax+by=d
        x = (x*d) / gcd;
        y = (y*d) / gcd;

        // getting the possible number of values of (x,y) , satisfying the condition : x >= 0 && y >= 0
        ll lowerRangeValue = ceil(((-1.0) * x * gcd) / b);
        ll upperRangeValue = floor((1.0 * y * gcd) / a);

        if(lowerRangeValue > upperRangeValue){   // means no solutions exist, satisfying the conditions
            ans.push_back(0);
        }
        else{
            ans.push_back(upperRangeValue - lowerRangeValue + 1);
        }
    }

    for(auto i : ans) cout << i << endl;
    
    return 0;
}