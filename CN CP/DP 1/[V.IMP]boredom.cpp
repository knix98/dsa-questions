/*
Boredom

Gary is bored and wants to play an interesting but tough game . So he figured out a new board game called "destroy the neighbours" . 
In this game there are N integers on a board. In one move, he can pick any integer x from the board and then all the integers 
with value x+1 or x-1 gets destroyed .This move will give him x points.
He plays the game until the board becomes empty . But as he want show this game to his friend Steven, he wants to learn techniques to 
maximise the points to show off . Can you help Gary in finding out the maximum points he receive grab from the game ?

Input Format :
First line will contain T (number of test case), each test case is consists of two line.
Line 1: Integer N 
Line 2: A list of N integers
Output Format :
For each test case print maximum points, Gary can receive from the Game setup in a newline.

Constraints :
 1 <= T <= 50
 1 <= N <= 10^5
 1 <= A[i] <= 1000

Sample Input :
1
2
1 2
Sample Output :
2
Explanation:
Gary can receive a maximum of 2 points, by picking the integer 2. 
*/



/*
Approach : if we are given arr = [1,2,1,2,1,2] , I would rearrange this into a vector<pair<int,int>> => {{1,3}, {2,3}} , that is freq of 1 is 3 and of 2 is 3
And then in the code below I have arranged them in decresing order of the number, but increasing order of the number can also be dealt with
*/
#include<bits/stdc++.h>
using namespace std;

int solve(vector<pair<int,int>> &f){
    int n = f.size();
    vector<int> dp(n, 0); // here dp[i] signifies => what would be the maximum profit if the "f array" in consideration starts from this i
    dp[n-1] = f[n-1].first * f[n-1].second;

    for(int i=n-2; i>=0; i--){
        if(f[i+1].first == (f[i].first - 1)){  
            int option1 = (f[i].first * f[i].second) + (i+2 < n ? dp[i+2] : 0); // means we pick up the current element and hence the i+1th elem gets destroyed
            int option2 = dp[i+1]; // means we assume here that may be the best possibility is one in which the current elem is destroyed and not counted

            dp[i] = max(option1, option2);
        }
        else{
            // since here, by picking up the current elem, nothing is going to get destroyed,
            // its obviously profitable to pick up the current elem and add it to dp[i+1]
            dp[i] = (f[i].first * f[i].second) + dp[i+1];
        }
    }

    return dp[0];
}

int main(){
    int t;
    cin >> t;

    vector<int> answers;
    while(t--){
        int n;
        cin >> n;

        vector<int> freq(1001, 0);
        for(int i=0; i<n; i++){
            int num;
            cin >> num;

            freq[num]++;
        }

        vector<pair<int,int>> freqPairs;
        for(int i=1000; i>=0; i--){
            if(freq[i]){
                pair<int,int> p(i, freq[i]);
                freqPairs.push_back(p);
            }
        }

        answers.push_back(solve(freqPairs));
    }

    for(auto i : answers) cout << i << endl;

    return 0;
}