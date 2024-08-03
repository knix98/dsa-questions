#include<bits/stdc++.h>
using namespace std;

// 1. Print all prime nos. between 1 and n
// Time Complexity: O(n*(log(log n)))
// Space Complexity: O(n)
void printPrimes(int n){
    vector<int> sieve(n+1, 0);  // 0 signifies that this number (index) is a prime number, 1 wud signify that this number is not prime

    for(int i=2; i<n+1; i++){
        if(sieve[i] == 0){
            cout << i << " ";

            for(int j=i*i; j<n+1; j += i){ // if i is a prime number than marking all multiples of i as non prime, starting from j = i*i (because every multiple of i before i*i wud have been marked as non prime by previous iterations)
                sieve[j] = 1;
            }
        }
    }
}

// 1. Print all prime factors of n
// Time Complexity: O(n*(log(log n)))
// Space Complexity: O(n)
void printPrimeFactors(int n){
    // will use an array of size n+1, where value will signify the smallest prime factor(spf) of that index
    vector<int> spf(n+1, 0);

    // filling the spf array with spf values of all indexes
    for(int i=2; i<n+1; i++){
        if(spf[i] == 0){ // means this index is a prime number, hence spf of this would be the index itself
            spf[i] = i;
        }

        // marking spf of all multiples of this prime number(i) as i
        for(int j=i*i; j<n+1; j += i){
            if(spf[j] == 0){
                spf[j] = i;
            }
        }
    }

    int i = n;
    while(i != 1){
        cout << spf[i] << " ";
        i = i/spf[i];
    } 
}

int main(){
    printPrimes(47);
    cout << endl;
    printPrimeFactors(50);
}