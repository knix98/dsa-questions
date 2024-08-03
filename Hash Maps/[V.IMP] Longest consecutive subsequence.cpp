/*
You are given an array of unique integers that contain numbers in random order.
You have to find the longest possible sequence of consecutive numbers using the numbers from given array.
You need to return the output array which contains starting and ending element.
If the length of the longest possible sequence is one, then the output array must contain only single element.
Note:
1. Best solution takes O(n) time.
2. If two sequences are of equal length, then return the sequence starting with the number whose occurrence is earlier in the array.

Sample Input 1 :
13
2 12 9 16 10 5 3 20 25 11 1 8 6
Sample Output 1 :
8 12
Sample Input 2 :
7
3 7 2 1 9 8 41
Sample Output 2 :
7 9
Explanation: Sequence should be of consecutive numbers. Here we have 2 sequences with same length i.e. [1, 2, 3] and [7, 8, 9], but we should select [7, 8, 9] because the starting point of [7, 8, 9] comes first in input array and therefore, the output will be 7 9, as we have to print starting and ending element of the longest consecutive sequence.
*/

#include <vector>
#include <unordered_map>
using namespace std;

vector<int> longestConsecutiveIncreasingSequence(int *arr, int n)
{
    unordered_map<int, int> seq;

    for (int i = 0; i < n; i++) // first store all the elements in the map
    {
        seq[arr[i]]++;
    }

    int maxSeq = 0; // length of maxSequence
    for (int i = 0; i < n; i++)
    {
        if (seq.count(arr[i]) > 0) // means arr[i] has not yet been counted/analysed
        {
            int j = 1;
            while (seq.count(arr[i] + j) > 0) // first finding the length of sequence ahead of arr[i]
            {
                seq[arr[i]]++;
                seq.erase(arr[i] + j); // when counted in a sequence, then erase the element, so that we don't count it again in future
                j++;
            }

            j = 1;
            while (seq.count(arr[i] - j) > 0) // now finding the length of sequence before arr[i]
            {
                seq.erase(arr[i] - j); // when counted in a sequence, then erase the element, so that we don't count it again in future
                j++;
            }
            if (j > 1) // means we did find some elements in a sequence before arr[i]
            {
                int seqLength = seq[arr[i]] + (j - 1);
                seq[arr[i] - (j - 1)] = seqLength; // store the length of the whole sequence, keeping the starting point of seq as key
                seq.erase(arr[i]);                 // since arr[i] is not the starting point so remove it
                if (seqLength > maxSeq)
                {
                    maxSeq = seqLength;
                }
            }
            else // means we didn't find any elements before arr[i], so arr[i] only is the starting point of the seq
            {
                if (seq[arr[i]] > maxSeq)
                {
                    maxSeq = seq[arr[i]];
                }
            }
        }
    }

    vector<int> output;
    for (int i = 0; i < n; i++)
    {
        if (seq.count(arr[i]) > 0) // means arr[i] is the starting point of some sequence, since now the map only contains the starting points with seqLength as their value
        {
            if (seq[arr[i]] == maxSeq)
            {
                output.push_back(arr[i]);
                if (maxSeq > 1)
                {
                    output.push_back(arr[i] + (seq[arr[i]] - 1)); // ending point = starting point + length of sequence
                }

                return output;
            }
        }
    }
}