/*
Count the inversions in the given array.
2 elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j

Example : for array => 3,5,6,9,1,2,7,8
Inversions = 10 = (3,1);(3,2);(5,1) and so on...
*/

#include<bits/stdc++.h>
using namespace std;

// Approach: we would write merge-sort algo and in between merge-sort we will keep counting the inversions
// this func would return inversions inside [st,en]
int inversions(vector<int> &v, int st, int en){
    if(st == en){ // base case
        return 0;
    }

    int mid = (st+en)/2;
    int leftAns = inversions(v, st, mid);
    int rightAns = inversions(v, mid+1, en);

    // We have found inversions internally inside left and right subarrays
    // Now we need to find inversions between left and right sub array
    vector<int> sorted; 
    int inv = 0; // count of inversions till now

    int i = st, j = mid+1; // iterators over the 2 subarrays
    while(i <= mid && j <= en){
        if(v[i] > v[j]){ 
            sorted.push_back(v[j++]);
        }
        else{ 
            sorted.push_back(v[i++]);
            // whenever an element from left subarray is pushed,
            // we check => how many right subarray elements have already been pushed before this
            // beacuse this would give us the count of inversions of v[i] with the elements of right subarray
            inv += j - (mid+1); // j = index of 1st non-pushed right array element and mid+1 is the initial starting index of right subarray
        }
    }

    if(i > mid){
        while(j <= en){
            sorted.push_back(v[j++]);
        }
    }
    if(j > en){
        while(i <= mid){
            sorted.push_back(v[i++]);
            inv += j - (mid+1);
        }
    }

    // storing the sorted order in the original vector
    for(int x = 0, k = st; x < sorted.size(); x++, k++){
        v[k] = sorted[x];
    }

    return leftAns + rightAns + inv;
}

int main(){
    vector<int> v{3,5,6,9,1,2,7,8};
    cout << inversions(v, 0, v.size()-1) << endl;
}