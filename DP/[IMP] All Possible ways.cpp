/*
Given two integers a and b. You need to find and return the count of possible ways in which we can represent
the number a as the sum of unique integers raise to the power b.
For example: if a = 10 and b = 2, only way to represent 10 as sum of unique integers raised to power 2 is-
10 = 1^2 + 3^2
Hence, answer is 1.
Note : x^y represents x raise to the power y

Sample Input 2 :
100 2
Sample Output 2 :
3
Explanation:
Following are the three ways:
1. 100 = 10^2
2. 100 = 8^2 + 6^2
3. 100 = 7^2+5^2+4^2+3^2+1^2
*/

// SOLUTION APPROACH: Sometimes it is not possible to convert a recursive code into DP, because either there are no repeating cases or,
// it's difficult to finalise the size of the DP array because of the ambiguity about the number of cases we need to calculate
// So in such cases we simply write a recursive/backtracking solution

#include <math.h>

// st is the first value that should be taken to determine the possible number of ways
int helper(int a, int b, int st)
{
    int num = pow(st, b);
    if (num > a)
    {
        return 0;
    }

    int possibleWays = 0;
    while (num <= a)
    {
        if (a - num == 0) // if the start value only is enough to sum up to 'a' then we got 1 solution
        {
            possibleWays++;
        }
        else
        {
            int smallAns = helper(a - num, b, st + 1);
            possibleWays += smallAns;
        }

        // after checking for the possible ways with the initial st value, we check with the next st value
        st++;
        num = pow(st, b);
    }

    return possibleWays;
}

int getAllWays(int a, int b)
{
    return helper(a, b, 1);
}