/*
You are given a stream of 'N' integers. For every 'i-th' integer added to the running list of integers, print the resulting median.
Print only the integer part of the median.

Sample Input 1 :
6
6 2 1 3 7 5
Sample Output 1 :
6 4 2 2 3 4
Explanation of Sample Output 1 :
S = {6}, median = 6
S = {6, 2} -> {2, 6}, median = 4
S = {6, 2, 1} -> {1, 2, 6}, median = 2
S = {6, 2, 1, 3} -> {1, 2, 3, 6}, median = 2
S = {6, 2, 1, 3, 7} -> {1, 2, 3, 6, 7}, median = 3
S = {6, 2, 1, 3, 7, 5} -> {1, 2, 3, 5, 6, 7}, median = 4
*/

#include <cstdlib>
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

void findMedian(int *arr, int n)
{
    if (n <= 1)
    {
        if (arr[0]) // if n==1, then just cout << arr[0]
            cout << arr[0];
        return;
    }

    priority_queue<int, vector<int>, greater<int>> minpq;
    priority_queue<int> maxpq;

    // need to handle the first 2 elements manually so that the algo written ahead could work well for the rest of the array
    // because we need to make sure that both maxpq, minpq are not empty before going into the algo
    cout << arr[0] << " ";
    maxpq.push(min(arr[0], arr[1]));
    minpq.push(max(arr[0], arr[1]));
    cout << (maxpq.top() + minpq.top()) / 2 << " ";

    for (int i = 2; i < n; i++)
    {
        if (minpq.top() > arr[i])
            maxpq.push(arr[i]);
        else
            minpq.push(arr[i]);

        int diff = minpq.size() - maxpq.size();
        if (abs(diff) == 1)
        {
            cout << (maxpq.size() > minpq.size() ? maxpq.top() : minpq.top()) << " ";
        }
        else if (diff == 0)
        {
            cout << (maxpq.top() + minpq.top()) / 2 << " ";
        }
        else // means in one of the pq there are 2 more elements than the other pq
        {
            // so first make elements equal in both pq
            if (maxpq.size() > minpq.size())
            {
                minpq.push(maxpq.top());
                maxpq.pop();
            }
            else
            {
                maxpq.push(minpq.top());
                minpq.pop();
            }
            cout << (maxpq.top() + minpq.top()) / 2 << " ";
        }
    }
}