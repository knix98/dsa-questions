/*
Return Subsets Sum to K

Given an integer array 'ARR' of size 'N' and an integer 'K', return all the subsets of 'ARR' which sum to 'K'.
Subset of an array 'ARR' is a tuple that can be obtained from 'ARR' by removing some (possibly all) elements of 'ARR'.
Note :
The order of subsets is not important. 

The order of elements in a particular subset should be in increasing order of the index.
*/




// IMP : Algo for generating all subsets from a given array using bit manipulation
// Time : (n * 2^n)
vector<vector<int>> findSubsetsThatSumToK(vector<int> arr, int n, int k) {
    vector<vector<int>> ans;

    int maxValue = pow(2, n);

    for(int i=0; i<maxValue; i++){  // we want bit representations of numbers in range [0, 2^n - 1]
        vector<int> check;
        int sum = 0;
        
        for(int j=n-1; j>=0; j--){
            if(i & 1 << j){  // checking whether element at (n-1 - j) has to be pushed in the array , according to bit representation of i
                check.push_back(arr[(n-1) - j]);
                sum += arr[(n-1) - j];
            }
        }

        if(sum == k) ans.push_back(check);
    }

    return ans;
}