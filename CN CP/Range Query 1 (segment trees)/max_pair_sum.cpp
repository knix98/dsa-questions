/*
https://classroom.codingninjas.com/app/classroom/me/22205/content/575422/offering/8882903/problem/9069?leftPanelTabValue=PROBLEM
*/


#include<bits/stdc++.h>
using namespace std;

#define M (st+en)/2

vector<int> nums;
vector<pair<int,int>> ST(400000, {-1,-1});

// pair<int,int> maxPair(pair<int,int> &a, pair<int,int> &b){
//     vector<int> v{a.first, a.second, b.first, b.second};
//     sort(v.begin(), v.end());
//     return {v[3], v[2]};
// }

pair<int,int> maxPair(pair<int,int> a, pair<int,int> b){
    if(a.first < b.first) swap(a,b);  // I am able to swap a, b confidently because they are temporary variables and not reference vars
    return {a.first, max(a.second, b.first)};
}

void buildSt(int stIndex, int st, int en){
    if(st == en) {  // means leaf node, containing only 1 element , or range is of length 1
        ST[stIndex] = {nums[st], -1};
        return;
    }

    buildSt(2*stIndex + 1, st, M); 
    buildSt(2*stIndex + 2, M+1, en);

    ST[stIndex] = maxPair(ST[2*stIndex + 1], ST[2*stIndex + 2]);
}

// i = stIndex, ui = update index, v = new update value
void update(int i, int st, int en, int ui, int v){
    if(st == en) {
        ST[i] = {v, -1};  // value updated
        return;
    }

    if(ui <= M) update(2*i + 1, st, M, ui, v);
    else update(2*i + 2, M+1, en, ui, v);

    ST[i] = maxPair(ST[2*i + 1], ST[2*i + 2]);
} 

pair<int,int> query(int i, int st, int en, int ql, int qr){
    if(st >= ql && en <= qr) return ST[i];
    else if (qr < st || ql > en) return {-1,-1};

    pair<int,int> leftAns = query(2*i+1, st, M, ql, qr);
    pair<int,int> rightAns = query(2*i+2, M+1, en, ql, qr);

    return maxPair(leftAns, rightAns);
}

int main(){
    int n;
    cin >> n;

    int temp;
    for(int i=0; i<n; i++) cin >> temp, nums.push_back(temp);

    buildSt(0, 0, n-1);

    int q;
    cin >> q;

    char c;
    int a, b;
    while(q--){
        cin >> c >> a >> b;
        if(c == 'U') update(0, 0, n-1, a-1, b);
        else{
            pair<int,int> ans = query(0, 0, n-1, a-1, b-1);
            cout << ans.first + ans.second << endl;
        }
    }
    
    return 0;
}