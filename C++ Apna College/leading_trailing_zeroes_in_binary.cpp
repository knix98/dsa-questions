/*
Find number of leading and trailing zeroes in binary representation of a number.
*/

#include<bits/stdc++.h>
using namespace std;

int leadingZeroes(int n){
    int x = 1 << 31; // shifting 1 to leftmost end of int , i.e at 32nd position
    int ans = 0;
    while((n & x) == 0){
        ans++;
        x = x >> 1;
    }

    return ans;
}

int trailingZeroes(int n){
    int x = 1;
    int ans = 0;
    while((n & x) == 0){
        ans++;
        x = x << 1;
    }

    return ans;
}

int main() {
    // int n = 1;
    // unsigned int x = 1 << 31;

    // cout << x << " " << (x >> 31);

    cout << leadingZeroes(1) << endl;
    cout << trailingZeroes(4);
}