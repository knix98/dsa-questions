/*
Vanya and GCD

Vanya has been studying all day long about sequences and other Complex Mathematical Terms. She thinks she has now become really good at it. 
So, her friend Vasya decides to test her knowledge and keeps the following challenge it front of her:
Vanya has been given an integer array A of size N. Now, she needs to find the number of increasing sub-sequences of this array with 
length ≥1 and GCD=1. A sub-sequence of an array is obtained by deleting some (or none) elements and maintaining the relative order of 
the rest of the elements. As the answer may be large, print it Modulo 109+7
She finds this task really easy, and thinks that you can do it too. Can you?

Input Format:
The first line contains a single integer N denoting size of array A. The next line contains N space separated integers denoting the elements of array A
Output Format:
Print the required answer Modulo 10^9+7 on a single line.

Constraints:
1≤N≤500
1≤A[i]≤100

Sample Input
3
1 2 3
Sample Output
5
Explanation
Here, the increasing sequences with GCD=1 are:
(1), (1,2), (1,3), (2,3), (1,2,3).
*/



// some explanation written in CN CP hand notes of DP-1 chapter
#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int GCD(int a, int b){
    if(a==1 || b==1) return 1;

    while(b > 0){
        int temp = a%b;
        a = b;
        b = temp;
    }

    return a;
}

int main()
{
    int n;
    cin >> n;

    vector<int> nums(n);
    for(int i=0; i<n; i++) cin >> nums[i];

    // in the below vector => gcds[i] would give us a vector (lets say gcd), which for nums[i], would tell us :
    // how many such sets which have nums[i] as its starting elem and have gcd of those sets as : 1, 2, 3, 4, 5....upto 100
    // why upto 100? => because the maximum possible value of num = 100, so max GCD possible also = 100
    vector<vector<int>> gcds(n, vector<int>(101, 0));

    int ans = 0; // we will keep on counting for the sets whose gcd comes out to be 1
    for(int i=n-1; i>=0; i--){
        // case 1 : only 1 elem in the set : that is the current elem (nums[i]) itself
        gcds[i][nums[i]] = 1;  // if only 1 element in our subsequence, then it itself is the gcd of this singleton set
        if(nums[i] == 1) ans = (ans + 1) % mod;
        
        // case 2 : now moving forward and finding such nums, which are bigger than our current nums[i]
        for(int j = i+1; j<n; j++){
            if(nums[j] > nums[i]){
                // that means nums[i] can form an increasing set with nums[j]
                // so find the gcds of the new sets, which would form by attaching nums[i] with all the sets of nums[j]
                for(int g=1; g<=100; g++){
                    int jGcd = g;
                    int jGcdFreq = gcds[j][g];

                    if(jGcdFreq > 0){
                        int tempGCD = GCD(nums[i], jGcd);
                        gcds[i][tempGCD] = (gcds[i][tempGCD] + jGcdFreq) % mod;
                        if(tempGCD == 1) ans = (ans + jGcdFreq) % mod;
                    }
                }
            }
        }
    }

    cout << ans;

    return 0;
}
