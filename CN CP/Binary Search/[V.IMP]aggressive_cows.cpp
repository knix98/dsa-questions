/*
You are given an array 'arr' consisting of 'n' integers which denote the position of a stall.


You are also given an integer 'k' which denotes the number of aggressive cows.


You are given the task of assigning stalls to 'k' cows such that the minimum distance between any two of them is the maximum possible.


Print the maximum possible minimum distance.


Example:
Input: 'n' = 3, 'k' = 2 and 'arr' = {1, 2, 3}

Output: 2

Explanation: The maximum possible minimum distance will be 2 when 2 cows are placed at positions {1, 3}. Here distance between cows is 2.
Input format :
The first line contains two integers ‘n’ and ‘k’ denoting the number of elements in the array and the number of aggressive cows.

The second line contains ‘n’ single space-separated integers denoting the position of the stalls.


Output format :
Return the largest possible minimum distance between cows.


Note :
You do not need to print anything; it has already been handled.
Sample Input 1 :
6 4
0 3 4 7 10 9


Sample Output 1 :
3


Explanation to Sample Input 1 :
The maximum possible minimum distance between any two cows will be 3 when 4 cows are placed at positions {0, 3, 7, 10}. Here distance between cows are 3, 4 and 3 respectively.


Sample Input 2 :
5 2
4 2 1 3 6


Sample Output 2 :
5


Expected time complexity:
Can you solve this in O(n * log(n)) time complexity?


Constraints :
2 <= 'n' <= 10 ^ 5
2 <= 'k' <= n
0 <= 'arr[i]' <= 10 ^ 9
Time Limit: 1 sec.
*/


#include<bits/stdc++.h>
using namespace std;

// APPROACH explanation is written in CN CP notes
int aggressiveCows(vector<int> &stalls, int k)
{
    int n = stalls.size();
    sort(stalls.begin(), stalls.end()); // sorting is required because we would be finding index of next cow using lower_bound
    int i = 1;  // binary search min range value, because stalls will be atleast 1 dist apart, and taking i=0 will lead to infinite loop when dist value((i+j)/2) becomes 0
    int j = stalls[n-1] - stalls[0];   // binary search max range value

    int ans = 1;
    while(i <= j){
        int dist = (i+j)/2;

        // m = index at which last cow was placed, cows = number of cows that have been placed already
        int m=0; // because first cow is always placed at 0th stall
        int cows = 1; // since first cow is always placed at 0th stall
        while(m<n){
            auto it = lower_bound(stalls.begin() + m, stalls.end(), stalls[m] + dist);
            if(it != stalls.end()){
                cows++;
                // m = distance(stalls.begin(), it);
                m = it - stalls.begin();
            }
            else{
                m = n;  // reached end of stalls arr
            }
        }

        if(cows < k){ // means with current dist value we cound not place k cows , so we need to search for a lower dist value
            j = dist-1;
        }
        else{
            // means with current dist value we >= k cows , so we need to search for a higher dist value
            // if we were able to place >k cows , that means we surely will be able to place k cows as well, so this is also an ans
            ans = dist;
            i = dist+1;
        }
    }

    return ans;
}