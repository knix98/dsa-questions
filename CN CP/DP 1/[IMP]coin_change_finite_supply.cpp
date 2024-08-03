/*
Coin Change(Finite Supply)

You are given an array of integers ‘coins’ denoting the denomination of coins and another array of integers ‘freq’ denoting the number of 
coins of each denomination.
You have to find the number of ways to make the sum ‘V’ by selecting some(or all) coins from the array.
The answer can be very large. So, return the answer modulo 1000000007.

For Example :
‘N’ = 3, ‘coins’ = {1, 2, 3}, ‘freq’ = {1, 1, 3}, ‘V’ = 6

For the given example, we can make six by using the following coins:
{1, 2, 3}
{3. 3}
Hence, the answer is 2.

Input Format :
The first line contains a single integer ‘T’ denoting the number of test cases, then each test case follows:

The first line of each test case contains a single integer ‘N’ denoting the total number of coins.

The second line of the test case contains ‘N’ integers denoting the elements of the array ‘coins’.

The third line of the test case contains ‘N’ integers denoting the elements of the array ‘freq’.

The fourth line of the test case contains the integer ‘V’ denoting the change we want. 

Output Format :
For each test case, print a single integer denoting the total number of possible ways to get change ‘V’.

Output for each test case will be printed in a separate line.

Note :
You are not required to print anything; it has already been taken care of. Just implement the function.

Constraints :
1 <= T <= 10    
1 <= N <= 100
1 <= coins[i] <= 100
1 <= freq[i] <= 100
1 <= V <= 100

Time limit: 1 sec
Sample Input 1 :
2
3
1 2 4
1 1 1
7
3
1 2 4
2 3 2
7
Sample Output 1 :
1
2
Explanation For Sample Input 1 :
In the first test case, there is only one possible way to make the sum equal to 7 i.e., taking all the coins. Hence answer is 1.

In the second test case, You can make the sum seven by using the following coins:
{1, 2, 4}, {1, 2, 2, 2}. Hence the answer is 2.
Sample Input 2 :
2
4
1 11 7 6
1 2 3 1
10
3
5 1 2
1 1 3
6
Sample Output 2 :
0
2
*/


// explanation written in hand CN CP notes of DP-1 chapter and then read this code 
const int mod = 1e9 + 7;

int coinChange(int n, vector<int> &coins, vector<int> &freq, int k)
{
    vector<int> next(k+1, 0);
    next[0] = 1;

    for(int i=n-1; i>=0; i--){
        int coin = coins[i];
        vector<int> curr(k+1, 0);

        for(int j=0; j<=k; j++){
            int excludedValue = j;
            curr[j] = ((long long)curr[j] + next[excludedValue]) % mod;

            int coinTotalValue = 0;
            int coinFreq = freq[i];
            while(coinFreq--){
                coinTotalValue += coin;

                int includedValue = j - coinTotalValue;
                if(includedValue >= 0) curr[j] = ((long long)curr[j] + next[includedValue]) % mod;
            }
        }

        next = curr;
    }

    return curr[k];
}