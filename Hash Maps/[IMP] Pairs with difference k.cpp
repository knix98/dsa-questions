/*
You are given with an array of integers and an integer K.
You have to find and print the count of all such pairs which have difference K.
Note: Take absolute difference between the elements of the array.

Sample Input 1 :
4
5 1 2 4
3
Sample Output 1 :
2
Sample Input 2 :
4
4 4 4 4
0
Sample Output 2 :
6
*/

// same approach as 'pair sum to 0' question

#include <unordered_map>
using namespace std;

int getPairsWithDifferenceK(int *arr, int n, int k)
{
    unordered_map<int, int> freq; // will keep on storing and updating the frequencies of the elements found in the array while traversing

    int pairs = 0;
    for (int i = 0; i < n; i++)
    {
        if (freq.count(arr[i] - k) > 0)
        {
            pairs += freq[arr[i] - k];
        }
        else if (freq.count(arr[i] + k) > 0)
        {
            pairs += freq[arr[i] + k];
        }

        freq[arr[i]]++;
    }

    return pairs;
}