/*
Find The Cube Free Number

A cube free number is a number who’s none of the divisor is a cube number (A cube number is a cube of a integer like 8 (2 * 2 * 2) , 
27 (3 * 3 * 3) ). So cube free numbers are 1, 2, 3, 4, 5, 6, 7, 9, 10, 11, 12, 13, 14, 15, 17, 18 etc (we will consider 1 as cube free). 
8, 16, 24, 27, 32 etc are not cube free number. So the position of 1 among the cube free numbers is 1, position of 2 is 2, 3 is 3 and 
position of 10 is 9. Given a positive number you have to say if its a cube free number and if yes then tell its position 
among cube free numbers.

Note: we will consider 1 as the 1st cube free number

Input Format:
First line of the test case will be the number of test case T 
Each test case contain an integer N
Output Format:
For each test case print the position of N in cube free numbers and if its not a cube free number print "Not Cube Free" in a newline.

Constraints:
1 <= T <= 10^5
1 <= N <= 10^6

Sample Input:
10
1
2
3
4
5
6
7
8
9
10

Sample Output:
1
2
3
4
5
6
7
Not Cube Free
8
9
*/


// approach : we would pre compute all cube free numbers before only, before taking in test cases
// for that, we would use sieve algo : basically when we find any prime number, then we would start marking its multiples as non-prime
// but if that multiple is divible by this prime-number's cube , then we would mark this cubic multiple differently
#include<bits/stdc++.h>
using namespace std;

#define ll long long

// pre-computation for getting all the cube-free numbers before hand only
void sieveAlgo(vector<int> &sieve){
    int n = 1000000;

    for(int i=2; i*i <= n; i++){  // similar to sieve algo for finding prime numbers
        if(sieve[i] == 1){  // means i is a prime number
            ll cubeOfI = (ll)(i)*i*i;

            for(ll j=i*i; j<=n; j+=i){
                if((j % cubeOfI) == 0){
                    // means this is a cube number
                    sieve[j] = 0;
                }
                else{
                    // if this number is not already marked a cube number of some previous prime number iteration, then mark it as composite-cube-free number
                    if(sieve[j] != 0) sieve[j] = 2;   // if j actually contains cube of another prime number, it would be encountered in that prime num's iteration in future
                }
            }
        }
    }
}

int main(){
    // pre-computation...
    vector<int> sieve(1000001, 1);  // in this sieve, 1 means prime num, 2 means composite-cube-free number,  0 means cube-number
    sieve[0] = 0;
    sieve[1] = 2;  // since 1 is cube-free number according to question

    sieveAlgo(sieve);

    vector<int> isCubeFree(1000001, 0);
    int cubeCounter = 1;

    for(int i=1; i<=1000000; i++){
        if(sieve[i]){
            isCubeFree[i] = cubeCounter++;
        }
    }


    // pre-computaion done, now just return answers simply
    int t;
    cin >> t;

    vector<int> answers;
    while(t--){
        int n;
        cin >> n;

        answers.push_back(isCubeFree[n]);
    }

    for(auto i : answers){
        if(i) cout << i << endl;
        else cout << "Not Cube Free" << endl;
    }
    
    return 0;
}