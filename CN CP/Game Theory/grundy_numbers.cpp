/*
https://classroom.codingninjas.com/app/classroom/me/22205/content/575417/offering/8882808/problem/9343
*/


// everything about grundy nums and sprague grundy theorem is written in CN CP hand notes
/*
doing precalculation of 10^6 grundy numbers was leading to TLE
So then I switched to memoization solution. 
But in that, 1 thing to take care => if I use a global set for the purpose of finding mex of grundy nums
and think that I would keep clearing the set , for the next Grundy function call , then it would give wrong results
because recursion was getting called before the clearing of the set and hence in the next recursive call, the set was not actually cleared
and giving wrong results.
Hence better is to initialise a new set for each recursive call as the set belonging to only that recursive call
Code with global set is coded and commented in the later below.
*/

#include<bits/stdc++.h>
using namespace std;

vector<int> grundy(1000001, -1);

int Grundy(int i){
    if(grundy[i] != -1) return grundy[i];

    set<int> vals;
    vals.insert(Grundy(i/2));
    vals.insert(Grundy(i/3));
    vals.insert(Grundy(i/6));

    grundy[i] = 0;
    auto it = vals.find(grundy[i]);
    while(it != vals.end()){ // finding mex
        grundy[i]++;
        it = vals.find(grundy[i]);
    } 

    return grundy[i];
}

int main(){
    grundy[0] = 0;

    int t, n;
    cin >> t;
    while(t--){
        cin >> n;
        cout << Grundy(n) << endl;
    }
    
    return 0;
}