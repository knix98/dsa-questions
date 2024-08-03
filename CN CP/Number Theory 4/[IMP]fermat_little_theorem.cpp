/*
Fermat Little Theorem

You are given two integers 'n' and 'r' and a prime number 'p'. Your task is to find (nCr) % p where nCr can be calculated as n! / (r! * (n - r)!).

Note :
N!  =  1 * 2 * 3 *... N

Input format :
The first line of input contains a single integer 'T', representing the number of test cases. 

The first line of each test case contains three space-separated integers 'n', 'r', and 'p'.
Output format :
For each test case, print a single line containing an integer representing the value of (nCr) % p.

The output of each test case will be printed on a separate line.

Note:
You don't need to input or print anything, it has already been taken care of. Just implement the given function.

Constraints :
1 <= T <= 5 
1 <= n, r, p <= 5 * 10 ^ 2
p is prime number.

Time limit: 1 sec.
Sample Input 1 :
2 
5 2 11
4 3 13
Sample Output 1 :
10
4
Explanation for Sample Output 1:
In test case 1, 
n = 5, r = 2, and p = 11
n C r = 5 C 2 = (5 * 4) / (2!) = 10
n C r % p = 10 % 11 = 10. 
So the answer will be 10.

In test case 2,
n = 4, r = 3, and p = 13 
n C r = 4 C 3 = 4 C 1 = 4 
n C r % p = 4 % 13 = 4. 
So the answer will be 4.
Sample Input 2 :
2
5 2 17
10 2 13
Sample Output 2 :
10
6
*/




// notes about fermat little theorem and calculating modular inverse of a number is written in CN CP hand notes in Number theory-4
#define ll long long

// this func wud return (a^b) % m
ll mod_pow(int a, int b, int m){
    ll res = 1;
    while(b > 0){
        if(b & 1){
            res = (res * a) % m;
            b--;
        }

        if(b > 0){
            a = (a*a) % m;
            b /= 2;
        }
    }

    return (ll)res;
}

unsigned long long  fermatLittle(int n, int r, int p)
{
    if(r > n) return 0;

    ll nFactorial = 1;
    ll nMinusRFactorial = 1;
    ll rFactorial = 1;

    ll temp = 1;
    for(int i=1; i<=n; i++){
        temp = (temp * i) % p;

        if(i==r) rFactorial = temp;
        if(i == n) nFactorial = temp;
        if(i == n-r) nMinusRFactorial = temp;
    }

    ll ans = ( (( nFactorial * mod_pow(rFactorial, p-2, p) ) % p) * mod_pow(nMinusRFactorial, p-2, p) ) % p;
    return ans;
}