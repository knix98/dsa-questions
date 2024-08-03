/*
You are given an array of integers and a target K. You have to find the count of subsets of the given array that sum up to K.
Note:
1. Subset can have duplicate values.
2. Empty subset is a valid subset and has sum equal to zero.

Constraints
1 <= T <= 50
2 <= N <= 15
0 <= array[i] <= 10^9
0 <= K <= 10^9
Time Limit: 1 second

Sample Input 1:
1
5 6
2 4 4 3 1
Sample Output 1:
3
Explanation:
Following are the three subsets, that sum upto K=6:
1. [2, 4], Element 4 in this subset is the one at index 1
2. [2, 4], Element 4 in this subset is the one at index 2
3. [2, 3, 1]
*/

#include <bits/stdc++.h>
using namespace std;

int subsets(int *arr, int n, int sum)
{
    if (n == 0)
    {
        if (sum == 0)
        {
            // means the numbers collected up untill now is 1 correct subset
            return 1;
        }
        else
        {
            return 0;
        }
    }

    int x = subsets(arr + 1, n - 1, sum);
    int y = subsets(arr + 1, n - 1, sum - arr[0]);
    return x + y;
}

int main()
{
    int t; // test cases
    vector<int> output;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int n, k;
        cin >> n >> k;
        int *arr = new int[n];
        for (int j = 0; j < n; j++)
        {
            cin >> arr[j];
        }
        output.push_back(subsets(arr, n, k));
        delete[] arr;
    }

    for (int x = 0; x < output.size(); x++)
    {
        cout << output[x] << endl;
    }
    return 0;
}