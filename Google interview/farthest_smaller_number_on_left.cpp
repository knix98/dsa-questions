/*
Find leftmost smaller number in an array.
Suppose you are given an array [2, 1, 3, 2, 1, 3]
output should be [-1, -1, 2, 1, -1, 2]?

Constraints are each element of array must be in range 1 <= arr[i] <= m ?
Expected time complexity O(n + m).
*/


// Method 1 : my approach : since we need to find the farthest number on left which is smaller, lets start considering numbers 1 by 1 from i=0
// and then lets also store the pairs of all nums and their indices in a set/priority_queue arranged in descending order
// now when we consider 1 number from the left (suppose x) then start iterating over the set: ignore/erase the pairs whose index is <= x's index
// for pairs whose num is greater than x, the answer for these nums is x. And we can set the answer for these nums using their indices stored 
// in the pair
// Time = O(nlogn) since we add and erase elems in the set only once
int main() {
    vector<int> v = {2, 1, 3, 2, 1, 3};
    set<pair<int,int>> s;
    for(int i = 0; i<v.size(); i++) s.insert({v[i], i});

    vector<int> ans(v.size(), -1); // initially all ans are -1

    for(int i = 0; i<v.size(); i++) {
        bool stop = false;
        while(!stop && !s.empty()) {
            auto it = s.rbegin();

            // since we cannot directly pass the rbegin it to erase function, we need to first convert it into a forward iterator like shown below
            // i.e to convert a reverse it to a forward it : forward it = --(it.base())  (since it.base() would return a forward it pointing to the next elem to previous elem pointed by reverse it)
            if(it->second <= i) s.erase(--(it.base())); // ignore/erase the pairs whose index is <= x's index
            else if(it->first > v[i]) { // for pairs whose num is greater than x, the answer for these nums is x
                ans[it->second] = v[i]; // And we can set the answer for these nums using their indices stored in the pair
                s.erase(--(it.base()));
            }
            else stop = true;
        }
    }

    for(int i : ans) cout << i << " ";
}

// the same code above can be written in an easy manner using a decreasing set
int main() {
    vector<int> v = {2, 1, 3, 2, 1, 3};
    set<pair<int,int>, greater<pair<int,int>>> s;
    for(int i = 0; i<v.size(); i++) s.insert({v[i], i});

    vector<int> ans(v.size(), -1);

    for(int i = 0; i<v.size(); i++) {
        bool stop = false;
        while(!stop && !s.empty()) {
            auto it = s.begin();
            if(it->second <= i) s.erase(it);
            else if(it->first > v[i]) {
                ans[it->second] = v[i];
                s.erase(it);
            }
            else stop = true;
        }
    }

    for(int i : ans) cout << i << " ";
}



// Method 2 : 
/*
GFG approach : https://www.geeksforgeeks.org/find-the-farthest-smaller-number-in-the-right-side/
An efficient approach is to create a suffix_min[] array where suffix_min[i] stores the minimum element from the subarray arr[i … N – 1]. 
Now for any element arr[i], binary search can be used on the subarray suffix_min[i + 1 … N – 1] 
to find the farthest smallest element to the right of arr[i].
If you think about the suffix_min array then you would see that it would be montonically decreasing from right to left in this problem
and hence binary search can be easily applied in this case
Time : O(nlogn) or if you think carefully it is log1 + log2 + ... + logn = O(log(n!))
And log(n!) is more efficient than nlogn = log(n^n)
Below is the implementation of the above approach: 
*/
// C++ implementation of the approach
#include <bits/stdc++.h>
using namespace std;

// Function to find the farthest
// smaller number in the right side
void farthest_min(int a[], int n)
{
	// To store minimum element
	// in the range i to n
	int suffix_min[n];
	suffix_min[n - 1] = a[n - 1];
	for (int i = n - 2; i >= 0; i--) {
		suffix_min[i] = min(suffix_min[i + 1], a[i]);
	}

	for (int i = 0; i < n; i++) {
		int low = i + 1, high = n - 1, ans = -1;

		while (low <= high) {
			int mid = (low + high) / 2;

			// If current element in the suffix_min
			// is less than a[i] then move right
			if (suffix_min[mid] < a[i]) {
				ans = mid;
				low = mid + 1;
			}
			else
				high = mid - 1;
		}

		// Print the required answer
		cout << ans << " ";
	}
}

// Driver code
int main()
{
	int a[] = { 3, 1, 5, 2, 4 };
	int n = sizeof(a) / sizeof(a[0]);

	farthest_min(a, n);

	return 0;
}
