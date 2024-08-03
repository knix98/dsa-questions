/*
Given a random integer array A of size N. Find and print the count of pair of elements in the array which sum up to 0.
Note: Array A can contain duplicate elements as well.

Sample Input 1:
5
2 1 -2 2 3
Sample Output 1:
2
*/

// BETTER APPROACH : to complete the task in only 1 iteration of the array
#include <unordered_map>
int pairSum(int *arr, int n)
{
    int pairs = 0;
    unordered_map<int, int> freq;
    for (int i = 0; i < n; i++)
    {
        if (freq.count(-arr[i]) != 0)
        {                           // if -arr[i] has been encountered before (i.e on left of arr[i]) then arr[i] wud form pairs
            pairs += freq[-arr[i]]; // with all those -arr[i] values so increase pairs by freq[-arr[i]]
        }
        freq[arr[i]]++;
    }

    return pairs;
}
