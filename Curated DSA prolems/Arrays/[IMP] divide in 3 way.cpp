/*
https://classroom.codingninjas.com/app/classroom/me/11692/content/204216/offering/2653314/problem/13748?leftPanelTabValue=PROBLEM

You are given an array/list of N positive integers and a range [X, Y], where 'X' and 'Y' are two integers. 
You are supposed to modify the given array/list such that the following conditions will be satisfied:

1. All the elements of the array strictly smaller than ‘X’ should come first.
2. All the elements of the array between the range [X, Y] should come next.
3. All the elements of the array strictly greater than ‘Y’ should come last.
Detailed explanation ( Input/output format, Notes, Images )
Constraints :
1 <= T <= 5
1 <= N <= 5000
0 <= arr[i] <= 10^9
0 <= a, b <= 10^9
Sample Input 1 :
1
5 2 3
2 0 1 3 4
Sample Output 1 :
Correct
Explanation for Sample Output 1:
After modifying the array according to the given condition, we will get 0 1 2 3 4 .
Since this element array satisfies the required properties, so we will get output as Correct.
Sample Input 2 :
1
5 4 6
1 3 5 7 9
Sample Output 2 :
Correct
    
*/

// always revise this way of doing three way in-place partitioning of any array
// this is the best way of wrtting code for this approach
#include <algorithm>

vector<int> threeWayPartition(vector<int> &arr, int n, int a, int b) {
  if (n < 2) {
    return arr;
  }

  int s = 0, m = 0, e = n - 1;

  while (m <= e) {
    if (arr[m] < a) {
      swap(arr[s], arr[m]);
      // now since we know that s is always <= m, only 2 cases are possible => 
      // 1. s==m => so we do s++, m++;
      // 2. s < m => since we know that before swapping everything in the index range [s, m) would have been the middle numbers only,
      //             so we can be assured that a middle number would always come to m after swapping. so here also we do s++, m++;
      s++;
      m++;
    } else if (arr[m] > b) {
      swap(arr[m], arr[e]);
      e--;
      if (arr[m] >= a && arr[m] <= b) {
        m++;
      }
    } else { 
      m++;
    }
  }

  return arr;
}