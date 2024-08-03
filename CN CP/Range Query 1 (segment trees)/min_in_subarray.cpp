/*
https://classroom.codingninjas.com/app/classroom/me/22205/content/575422/offering/8882905/problem/9066
*/



#include<bits/stdc++.h>
using namespace std;

#define M (st+en)/2

vector<int> nums;
vector<int> ST(400000);

void buildSt(int stIndex, int st, int en){
    if(st == en) {  // means leaf node, containing only 1 element , or range is of length 1
        ST[stIndex] = nums[st];
        return;
    }

    buildSt(2*stIndex + 1, st, M); 
    buildSt(2*stIndex + 2, M+1, en);

    ST[stIndex] = min(ST[2*stIndex + 1], ST[2*stIndex + 2]);
}

// i = stIndex, ui = update index, v = new update value
void update(int i, int st, int en, int ui, int v){
    if(st == en) {
        ST[i] = v;  // value updated
        return;
    }

    if(ui <= M) update(2*i + 1, st, M, ui, v);
    else update(2*i + 2, M+1, en, ui, v);

    ST[i] = min(ST[2*i + 1], ST[2*i + 2]);
} 

int query(int i, int st, int en, int ql, int qr){
    if(st >= ql && en <= qr) return ST[i];
    else if (qr < st || ql > en) return INT_MAX;

    int leftAns = query(2*i+1, st, M, ql, qr);
    int rightAns = query(2*i+2, M+1, en, ql, qr);

    return min(leftAns, rightAns);
}

int main(){
    int n, q;
    cin >> n >> q;

    int temp;
    for(int i=0; i<n; i++) cin >> temp, nums.push_back(temp);

    buildSt(0, 0, n-1);

    char c;
    int a, b;
    while(q--){
        cin >> c >> a >> b;
        if(c == 'u') update(0, 0, n-1, a-1, b);
        else{
            int ans = query(0, 0, n-1, a-1, b-1);
            cout << ans << endl;
        }
    }
    
    return 0;
}