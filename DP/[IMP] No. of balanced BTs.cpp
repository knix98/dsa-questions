/*
Given an integer h, find the possible number of balanced binary trees of height h.
You just need to return the count of possible binary trees which are balanced.
This number can be huge, so, return output modulus 10^9 + 7.
Time complexity should be O(h).

Constraints :
1 <= h <= 10^6
Time Limit: 1 sec

Sample Input 1:
3
Sample Output 1:
15

Sample Input 2:
4
Sample Output 2:
315
*/

// APPROACH: If the height of the
// complete binary tree is h, that means the height of its left and right subtrees
// individually is at most h-1. So if the height of the left subtree is h-1, then the height
// of the right subtree could be any among {h-1, h-2} and vise versa. Initially, we were given the problem of finding the output for height h. Now we have
// reduced the same to tell the output of height h-1 and h-2. Finally, we just need to
// figure out these counts, add them, and return.

int balancedBTs(int n)
{
    int *dp = new int[n + 1];

    dp[0] = 1;
    dp[1] = 1;

    int mod = 1e9 + 7;

    for (int i = 2; i < n + 1; i++)
    {
        int x = dp[i - 1] % mod;
        int y = dp[i - 2] % mod;

        int a = ((long)x * x) % mod;
        int b = ((long)x * y * 2) % mod;

        dp[i] = ((long)a + b) % mod;
    }

    int ans = dp[n];
    delete[] dp;
    return ans;
}