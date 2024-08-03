/*
Number Of Factors

A number is called n-factorful if it has exactly n distinct prime factors. 
Given positive integers a, b, and n, your task is to find the number of integers between a and b, inclusive, that are n-factorful. 
We consider 1 to be 0-factorful.

Input Format:
First line of input will contain T(number of test cases), each test case follows as.
Each test cases consists of a single line containing integers a, b, and n as described above.
Output Format:
Output for each test case one line containing the number of n-factorful integers in [a, b].

Constraints:
1 <= T <= 10000
1 ≤ a ≤ b ≤ 10^6
0 <= b - a <= 100
0 ≤ n ≤ 10

Sample Input
4
1 3 1
1 10 2
1 10 3
1 100 3

Sample Output
2 
2
0
8
*/


// similar approach as previous problem : [IMP]Finding_number_of_prime_factors_of_numbers_1.cpp
include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;

    // since max value of b can be 1000000, lets calculate prime factors of all numbers till 1000000 in pre-processing only
    // instead of calculating same things again and again for all test cases
    vector<int> primeFactors(1000001, 0);

    for(int i = 2; i<=1000000; i++){ // in prev problem we had gone till : i*2 <= n, but here going all the way, because here we have to mark all the prime numbers with 1 till 1000000
                                     // because if in some test case it is asking all such numbers having one factor only, then those later prime numbers with 0 marked would n't be counted (but they should be counted)
        if(primeFactors[i] == 0){
            primeFactors[i] = 1;   // since that means this number is a prime number, so this has only 1 primeFactor

            for(int j = i*2; j<=1000000; j+=i){
                primeFactors[j]++;
            }
        }
    }


    vector<int> ans;

    while(t--){
        int a,b,n;
        cin >> a >> b >> n;

        int currAns = 0;
        for(int i=a; i<=b; i++){
            if(primeFactors[i] == n) currAns++;
        }

        ans.push_back(currAns);
    }
    
    for(auto i : ans) cout << i << endl;

    return 0;
}