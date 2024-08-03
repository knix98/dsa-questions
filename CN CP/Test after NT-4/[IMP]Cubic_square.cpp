/*
Cubic Square

Varun is learning method of successive squaring so that he can calculate a^b mod m quickly. To give himself practice he wrote many tuples of a, b and m and went to school thinking that he will do it after school.
After school he found that tuples he wrote are modified by his little sister. His sister converted each b into base 3. Varun wrote everything in base 10.
Help Varun to do his exercise.

Input Format:
First line of input contains a number T(number of test case). Each test case contains an integer a(base 10) followed by a string b (base 3) followed by integer m (base 10). All are space-separated.
Output Format;
Output a number for each test case a^b mod m in base 10 in new line.

Constraints:
1 <= T <= 1000
1 <= a, m <= 10^9
Number of digits in b will be less than 250.

Sample Input:
2
2 10 10
3 21101 19
Sample Output:
8
3
*/



// First read the explanation written in hand notes , then read this code
#include<bits/stdc++.h>
using namespace std;

#define ll long long

int cubicSquare(int m, int a, string &b) {
    long long ans = 1;
    // Converting base and mod to long long to avoid overflow.
    long long base = a, mod = m;
    int n = b.length();

    // Traverse 'b' from 'n'-1 to 0 as first we need to go to the least significant bit.
    for (int i = n - 1; i >= 0; i--) {
        // If current bit is equal to 2, that means 2 times 'a' needs to be multiplied to the answer.
        if (b[i] == '2') {
            ans = (((ans * base) % mod) * base) % mod;
        }
        // If the current bit is '1', that means 1 times 'a' needs to be multiplied to the answer.
        else if (b[i] == '1') {
            ans = (ans * base) % mod;
        }
        // Every increase in bit position is significant of rise by 3 in a's power.
        base = (((base * base) % mod) * base) % mod;
    }

    // Return the final answer.
    return ans;
}

int main(){
    int t;
    cin >> t;

    vector<int> answers;
    while(t--){
        int a,m;
        string b;

        cin >> a >> b >> m;

        

        answers.push_back(cubicSquare(m, a, b));
    }

    for(auto i : answers) cout << i << endl;

    return 0;
}