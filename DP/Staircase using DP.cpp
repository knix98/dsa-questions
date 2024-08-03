/*
A child runs up a staircase with 'n' steps and can hop either 1 step, 2 steps or 3 steps at a time.
Implement a method to count and return all possible ways in which the child can run-up to the stairs.

Sample Input 1:
4
Sample Output 1:
7

Sample Input 2:
10
Sample Output 2:
274
*/

long staircase(int n)
{
    long *arr = new long[n + 1]{0}; // we need to make long type arr because if n is large then arr[n] or number of ways to climb n would be larger than int capacity
    arr[0] = 1;                     // calculate the value of arr[0] (base case), by dry running your code for small cases like for arr[2]
    arr[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        arr[i] += arr[i - 1];
        arr[i] += arr[i - 2];
        if (i - 3 >= 0)
        {
            arr[i] += arr[i - 3];
        }
    }

    long output = arr[n];
    delete[] arr;
    return output;
}