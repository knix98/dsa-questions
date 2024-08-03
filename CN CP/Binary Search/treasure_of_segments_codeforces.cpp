/*
Problem name on codeforces -> F. The Treasure of The Segments
*/

#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
 
// APPROACH : For each segment, we would have to count the number of lines which are not intersecting with the current line
// this can be done in this way : for current line segment count how many right end points are smaller than the current segment's left end point
// similarly for current line segment count how many left end points are larger than the current segment's right end point
// summation of above 2 are the number of segments which do not intersect with current segment
int main() {
    int t;
    cin >> t;
 
    vector<ll> answers;
 
    while(t--){
        int n;
        cin >> n;
 
        vector<pair<ll, ll>> segments(n); 
        vector<ll> lefts(n); 
        vector<ll> rights(n);
 
        for(int i=0; i<n; i++){
            cin >> lefts[i] >> rights[i];
            pair<ll, ll> segment(lefts[i], rights[i]);
            segments[i] = segment;
        }
 
        sort(lefts.begin(), lefts.end());
        sort(rights.begin(), rights.end());
 
        int ans = n;  // max answer can be n = total number of lines
        for(int i=0; i<n; i++){
            ll curL = segments[i].first;  // current left end point
            ll curR = segments[i].second;
 
            int curAns = 0;  // count of line segments not intersecting current line
 
            // while counting we should not count in such points whose right value is equal to curr's left point (because 1 point touching is also intersecting, according to question)
            auto it1 = lower_bound(rights.begin(), rights.end(), curL);
            curAns += distance(rights.begin(), it1);
 
            // now finding : for current line segment count how many left end points are larger than the current segment's right end point
            auto it2 = upper_bound(lefts.begin(), lefts.end(), curR);
            if(it2 != lefts.end()){
                int biggerLefts = (distance(lefts.begin(), lefts.end()) - distance(lefts.begin(), it2));
                curAns += biggerLefts;
            }
 
            ans = ans < curAns ? ans : curAns;
        }
 
        answers.push_back(ans);
    }
 
    for(int i=0; i<answers.size(); i++){
        cout << answers[i] << endl;
    }
 
    return 0;
}