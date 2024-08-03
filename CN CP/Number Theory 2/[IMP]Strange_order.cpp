/*
Strange order

Given an integer n . Initially you have permutation p of size n : p[i] = i . To build new array a from p following steps are done while permutation p is not empty:
Choose maximum existing element in p and define it as x ; Choose all such y in p that gcd ( x , y ) ≠ 1 ; Add all chosen numbers into array a in decreasing order and remove them from permutation. Your task is to find a after p became empty.

Note: gcd ( a , b ) is the greatest common divisor of integers a and b .

Input format
Input contains single integer n — the size of permutation p p.
Output format
Print n integers — array a .

Constraints:
1 <= N <= 10^5

Sample Input:
5
Sample Output:
5 4 2 3 1
Explanation
It's needed 4 iterations to create array a:
Add 5
Add 4 and 2
Add 3
Add 1
*/



// Dry run and explantion of the approach is written in CN CP hand number-theory-2 notes
#include<bits/stdc++.h>
using namespace std;

void sieveForFindingSmallestPrimeFactorOfEachIndex(vector<int>& spf, int n){
    for(int i=2; i*i <= n; i++){
        if(spf[i] == i){ // means i is a prime number
            for(int j = i*i; j<=n; j+=i){
                if(spf[j] > i) spf[j] = i;
            }
        }
    }
}

int main(){
    int n;
    cin >> n;

    vector<int> spf(n+1);
    for(int i=0; i<=n; i++) spf[i] = i;

    // first prepare the smallest prime factors of all the elems [1,n] in the spf array
    sieveForFindingSmallestPrimeFactorOfEachIndex(spf, n);

    // this vector would tell us the group number of a particular prime factor
    vector<int> primeFactorGroup(n+1, INT_MAX);

    // these are the groups in which we will be collecting elements of each group
    vector<vector<int>> groups;

    for(int i=n; i>=1; i--){
        int temp = i;
        vector<int> primeFactorsOfI; // for storing all distinct prime factors of i, (might be needed in case all prime factors are new prime factors and hence we would need to mark these new prime factors with new group number)
        int earliestGroupForI = INT_MAX;  // this var will store the earliest group number found for the current i , amongst the group numbers of prime factors of i

        // for going thru each of the prime factors of i we will use the spf array, and hence we will traverse all the prime factors of i in log(i) time
        while(temp > 1){
            // spf[temp] means the current prime factor of i in consideration
            if(primeFactorGroup[spf[temp]] < earliestGroupForI) earliestGroupForI = primeFactorGroup[spf[temp]];

            if (primeFactorsOfI.empty() || primeFactorsOfI.back() != spf[temp]) primeFactorsOfI.push_back(spf[temp]);

            temp /= spf[temp];
        }

        if(earliestGroupForI == INT_MAX){ // means all the prime factors of i do not belong to any previous group
            // so make a new group for prime factors of i
            vector<int> newGroup;
            newGroup.push_back(i);

            int newGroupIndex = groups.size();

            for(auto it : primeFactorsOfI) primeFactorGroup[it] = newGroupIndex;

            groups.push_back(newGroup);
        }
        else{
            // else push i in the earliest group number found amongst the prime factors of i
            groups[earliestGroupForI].push_back(i);
        }
    }

    for(auto i : groups){
        for(auto j : i){
            cout << j << " ";
        }
    }
    
    return 0;
}
