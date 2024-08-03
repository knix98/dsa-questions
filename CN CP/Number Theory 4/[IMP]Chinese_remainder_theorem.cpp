/*
Numbers and Remainders

Ninja is learning about the mathematical division and remainders. So in curiosity, he forms two lists of numbers ‘ARR’ and ‘REM’ both having ‘N’ numbers. Now Ninja is interested in finding the minimum positive number ‘X’ such that ‘X’ satisfies the following condition for all ‘N’ values:
X % ‘ARR’[i] = ‘REM’[i] (Remainder of X / ARR[i] should be equal to  ‘REM’[i]).
You are given two arrays ‘ARR’ and ‘REM’ both having ‘N’ values corresponding to the numbers and remainders. Your task is to find the smallest positive integer ‘X’ fulfilling the given conditions.

Note:
All numbers in ‘ARR’ are pairwise co-prime.

For Example
For the given if N = ‘3’, ‘ARR’ = [4,5,7] and ‘REM’ = [3,2,2].
The answer will be 107.

Input Format:
The first line of the input contains an integer, 'T,’ denoting the number of test cases.

The first line of each test case contains an integer ‘N’ denoting the size of both arrays. 
The second line of each test case contains ‘ARR’ array.
The third line contains the ‘REM’ array.

Output Format:
For each test case, print a single integer denoting the smallest integer satisfying the given conditions.

Note:
You do not need to print anything. It has already been taken care of. Just implement the given function.

Constraints:
1 <= T <= 10
1 <= N <= 1000.
1 <= ARR[i] , REM[i] <= 10^5.
For each i,  ARR[i] > REM[i]. 
Time limit: 1 sec

Sample Input 1:
2
3
4 5 7
3 2 2 
3
3 4 5
2 3 1
Sample Output 1:
107
11
Explanation of sample input 1:
For the first test case,
107 is the smallest integer satisfying the condition as :
107 % 4 = 3
107 % 5 = 2
107 % 7 = 2  

For the second test case:
11 is the smallest integer satisfying the condition as :
11 % 3 = 2
11 % 4 = 3
11 % 5 = 1  
Sample Input 2:
2
2
2 13 
0 7 
2
3 17 
1 15
Sample Output 2:
20
49
*/



// explaination and proof on CRT is written in hand notes Number theory 4 chapter
#define ll long long

ll extended_euclid(ll a, ll b, ll &x, ll &y){
    if(b == 0){
        x = 1;
        y = 0;
        return a;
    }

    ll x1, y1;
    ll gcd = extended_euclid(b, a%b, x1, y1);

    x = y1;
    y = x1 - ((a/b)*y1);

    return gcd;
}

// here we would have to use extended_euclid way of finding modulo_inverse, since m here can be non_prime in some iterations
ll modulo_inv(ll a, ll m){
    ll x, y;
    ll gcd = extended_euclid(a, m, x, y);

    if(gcd != 1) return -1;
    else return ((x % m) + m) % m;
}

long long numbersAndRemainders(int n, vector<int> &arr, vector<int> &rem)
{
    ll N = 1;
    for(auto i : arr) N *= i;

    ll ans = 0;
    for(int i=0; i<n; i++){
        ll add = ( ((rem[i] * (N / arr[i])) % N) * (modulo_inv(N/arr[i], arr[i])) ) % N; // modulo_inverse would always exist because all arr[i] are relatively coprime
        ans = (ans + add) % N;
    }

    return ans;
}