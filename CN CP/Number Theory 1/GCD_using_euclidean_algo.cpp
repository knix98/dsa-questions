/*
GCD

Calculate and return GCD of two given numbers x and y. Numbers are within range of Integer.
Input format :
First line of Input will contain T(number of test cases), each test case follows as.
x and y (separated by space)
Output format :
Print GCD of x and y for each test case in newline
Constraints:
1 <= T <= 10^5
1 <= x, y <= 10^9
Sample Input 1:
1
20 5
Sample Output 1:
5
Sample Input 2:
1
96 14
Sample Output 2:
2
*/

// Time : O(log(min(a,b)))
// Explanation written in CN cp hand notes
#include<bits/stdc++.h>
using namespace std;

// keep doing (a,b) => (b, a%b), till a%b becomes 0
int GCD(int a, int b){
    while(b > 0){
        int temp = b;
        b = a%b;
        a = temp;
    }

    return a;
}

int main(){
    int t;
    cin >> t;

    vector<pair<int,int>> cases;
    while(t--){
        pair<int,int> temp;
        cin >> temp.first >> temp.second;

        cases.push_back(temp);
    }

    for(auto i : cases){
        cout << GCD(max(i.first, i.second), min(i.first, i.second)) << endl;
    }

    return 0;
}