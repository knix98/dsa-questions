/*
https://www.spoj.com/problems/HALLOW/

Every year there is the same problem at Halloween: Each neighbor is only willing to give a certain total number of sweets on that day, no matter how many children call on him, so it may happen that a child will get nothing if it is too late. To avoid conflicts, the children have decided they will put all sweets together and then divide them evenly among themselves. From last year's experience of Halloween they know how many sweets they get from each neighbour. Since they care more about justice than about the number of sweets they get, they want to select a subset of the neighbours to visit, so that in sharing every child receives the same number of sweets. They will not be satisfied if they have any sweets left which cannot be divided.

Your job is to help the children and present a solution.

Input
The input contains several test cases.
The first line of each test case contains two integers c and n (1 ≤ c ≤ n ≤ 100000), the number of children and the number of neighbours, respectively. The next line contains n space separated integers a1, ... an (1 ≤ ai ≤ 100000), where ai represents the number of sweets the children get if they visit neighbour i.

The last test case is followed by two zeros.

Output
For each test case output one line with the indices of the neighbours the children should select (here, index i corresponds to neighbour i who gives a total number of ai sweets). If there is no solution where each child gets at least one sweet, print "no sweets" instead. Note that if there are several solutions where each child gets at least one sweet, you may print any of them.

Example
Input:
4 5
1 2 3 7 5
3 6
7 11 2 5 13 17
0 0

Output:
3 5
2 3 4
*/



// explanation and proof written in CN CP hand notes
#include<bits/stdc++.h>
using namespace std;

int nums[100001];

void solve(int c, int n, vector<int> &ans) {
    int prefixSum[n] = {0};
    prefixSum[0] = nums[0];

    int prefSumModulos[c]; // ith index of this array will contain "index" of nums array at which i was obtained when we do prefixSum[index] % c
    for(int i=0; i<c; i++) prefSumModulos[i] = -1;
    prefSumModulos[prefixSum[0] % c] = 0;  // prefixSum[0] % c  is obtained at 0th index in nums array

    int ansStIndex, ansEndIndex; // would store the st and end indices of the answer subarray
    for(int i=1; i<n; i++){
        prefixSum[i] = (prefixSum[i-1] + nums[i]) % c;
        if(prefixSum[i] == 0) {
            ansStIndex = 0;
            ansEndIndex = i;
            break;
        } 
        else if(prefSumModulos[prefixSum[i]] != -1) {
            // means this value has been encuntered previously at some earlier index also
            ansStIndex = prefSumModulos[prefixSum[i]] + 1;
            ansEndIndex = i;
            break;
        }
        else {
            prefSumModulos[prefixSum[i]] = i;
        }
    }

    for(int i=ansStIndex; i<=ansEndIndex; i++) ans.push_back(i+1);  // since we have to print 1 based indexes
}

int main(){
    int c, n;
    while(1){
        cin >> c >> n;
        if(c == 0 && n == 0) break;

        for(int i=0; i<n; i++) cin >> nums[i];

        vector<int> ans;
        solve(c, n, ans);
        for(auto i : ans) cout << i << " ";
        cout << endl;
    }

    return 0;
}