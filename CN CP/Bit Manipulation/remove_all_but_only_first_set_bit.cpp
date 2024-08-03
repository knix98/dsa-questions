/*
Find First Set Bit

You are given an integer N. You need to return an integer M, in which only one bit is set which at the position of a lowest set bit of N (from right to left).
Input Format :
The first line of input will contain T(number of the test case), each test case follows as.
The only line of each test case contains an integer N.
Output Format:
Integer M for each test case in a new line.
Constraints:
1 <= T <= 10^5
1 <= N <= 10^9
Sample Input 1 :
1
7
Sample Output 1 :
1
Sample Input 2 :
1
12
Sample Output 2 :
4
*/




// 2 APPROACHES :
/*
solve1 =>  suppose n = 1101000
n = 1101000
n & n-1 = 1100000

n ^ (n & n-1) = 0001000

solve2 => suppose n = 1101000
-n = 0011000 (generated after following the procedure of storing -ve nums (i.e, first flip the bits and then add 1 to it))

n & (-n) = 0001000
*/

#include<bits/stdc++.h>
using namespace std;

int solve1(int n){
    return (n ^ (n & (n-1)));
}

int solve2(int n){
    return (n & (-n));
}

int main(){
    int t;
    cin >> t;

    vector<int> ans;

    while(t--){
        int n;
        cin >> n;

        ans.push_back(solve1(n));
    }    

    for(auto i : ans) cout << i << endl;
    
    return 0;
}