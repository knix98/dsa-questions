/*
You are given an array of size N with all elements with even frequency except one and you are supposed to find this element.
Input Format:
The first line of input will contain T(number of test cases), each test case follows as.
Line 1: contain an integer N (number of elements in the array)
Line 2: contain N space-separated integers (elements of the array).
Output Format:
For each test case print the element with the odd frequency in a new line.
Constraints:
1 <= T <= 50
1 <= N <= 10^5
1 <= arr[i] <= 10^9
Sample Input:
1 
5
2 2 2 3 3 
Sample Output:
2 
*/



#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    
    int t;
    cin >> t;

    vector<ll> answers;

    while(t--){
        int n;
        cin >> n;

        ll ans = 0;
        for(int i=0; i<n; i++){
            ll temp;
            cin >> temp;
            ans ^= temp;
        }

        answers.push_back(ans);
    }

    for(auto i : answers) cout << i << endl;
    return 0;
}