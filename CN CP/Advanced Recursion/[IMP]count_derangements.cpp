/*
A Derangement is a permutation of ‘N’ elements, such that no element appears in its original position. For example, an instance of derangement of {0, 1, 2, 3} is {2, 3, 1, 0}, because 2 present at index 0 is not at its initial position which is 2 and similarly for other elements of the sequence.
Given a number ‘N’, find the total number of derangements possible of a set of 'N’ elements.
Note:
The answer could be very large, output answer %(10 ^ 9 + 7).
Input format:
The first line of input contains an integer ‘T’ denoting the number of test cases.

The first line and the only line of each test case contains an integer ‘N’ denoting the number of elements whose derangements are to be counted.
Output Format:
For each test case, return the total number of derangements of a set of ‘N’ elements. 
Note:
You don't need to print anything, it has been already taken care of. Just implement the given function. 
Constraints:
1 <= T <= 100
1 <= N <= 3000

Time limit: 1 sec
Sample Input 1:
2
2
3
Sample Output 1:
1
2
Explanation of Sample Output 1:
In test case 1, For two elements say {0, 1}, there is only one possible derangement {1, 0}. 1 is present at index 0 and not at its actual position, that is, 1. Similarly, 0 is present at index 1 and not at its actual position, that is, 0.

In test case 2, For three elements say {0, 1, 2}, there are two possible derangements {2, 0, 1} and {1, 2, 0}. In both the derangements, no element is present at its actual position.


Sample Input 2:
2
1
4
Sample Output 2:
0
9
Explanation of Sample Output 2:
In test case 1, For the array = {0}, there is no possible derrangements. Hence the answer is 0 (zero).

In test case 2, For the array elements = {0, 1, 2, 3}, total 9 derrangements are possible. One of them is: { 3, 2, 1, 0}.
*/




#define ll long long

// Explanation for both approaches written in CN CP notes

// APPROACH 1 : 
long long int countDerangements(int n) {
    if(n < 3) return n-1;  // D(2) = 1  and   D(1) = 0

    ll mod = 1e9 + 7;

    ll prevPrev = 0;  // D(1)
    ll prev = 1; // D(2)

    for(int i=3; i<=n; i++){
        ll currAns = ((i-1) * ((prev + prevPrev) % mod)) % mod;
        prevPrev = prev;
        prev = currAns;
    }

    return prev;
}


// SECOND APPROACH

ll fact(int n){  // func for calculating factorial of a number
    ll mod = 1e9 + 7;

    ll ans = 1;
    for(int i=1; i<=n; i++){
        ans = (ans*i) % mod;
    }

    return ans;
}

long long int countDerangements(int n) {
    ll mod = 1e9 + 7;
    ll dp[n+1] = {0}; 
    dp[1] = 0;  // IMP to keep dp[1] = 0 as n would be multipied with dp[1]. But we want to count only 1 for both dp[0] and dp[1] (look at notes)
    dp[0] = 1;

    ll facts[n+1] = {0};  // array for storing factorials of numbers , so that we dont have to recalculate them
    facts[0] = 1;
    facts[1] = 1;

    for(int i=2; i<=n; i++){
        facts[i] = fact(i);

        dp[i] = facts[i];  // first adding i! to answer, then will start individual deductions

        for(int j=i-1; j>=0; j--){
            ll deduct = (((facts[i] / facts[j]) / facts[i-j]) * dp[j]) % mod;   // this equation is the notes equation only => iC(i-j) * D(j)
            dp[i] = dp[i] - deduct;
        }

        dp[i] = dp[i] % mod;
    }

    return dp[n];
}