/*
https://classroom.codingninjas.com/app/classroom/me/22205/content/575422/offering/8882917/problem/9073?leftPanelTabValue=PROBLEM
*/


#include<bits/stdc++.h>
using namespace std;

#define M (st+en)/2

vector<int> str;
vector<int> cow;
vector<int> ST(400000);   // will store index of the choosen soldier for given range in this segment tree

// this func would decide and return the index based on the child answer indices i1 and i2
int decideSTIndex(int i1, int i2){
    if(i1 == -1 && i2 == -1) return -1;
    else if(i1 == -1 || i2 == -1) return max(i1, i2);

    if(str[i1] > str[i2]) return i1;
    else if(str[i1] < str[i2]) return i2;
    else if(cow[i1] > cow[i2]) return i2;
    else if(cow[i1] < cow[i2]) return i1;
    else return min(i1, i2);
}

void buildSt(int stIndex, int st, int en){
    if(st == en) {  // means leaf node, containing only 1 element , or range is of length 1
        ST[stIndex] = st;
        return;
    }

    buildSt(2*stIndex + 1, st, M); 
    buildSt(2*stIndex + 2, M+1, en);

    ST[stIndex] = decideSTIndex(ST[2*stIndex + 1], ST[2*stIndex + 2]);
}

int query(int i, int st, int en, int ql, int qr){
    if(st >= ql && en <= qr) return ST[i];
    else if (qr < st || ql > en) return -1;

    int leftAns = query(2*i+1, st, M, ql, qr);
    int rightAns = query(2*i+2, M+1, en, ql, qr);

    return decideSTIndex(leftAns, rightAns);
}

int main(){
    int n, q;
    cin >> n;

    int temp;
    for(int i=0; i<n; i++) cin >> temp, str.push_back(temp);    
    for(int i=0; i<n; i++) cin >> temp, cow.push_back(temp);

    buildSt(0, 0, n-1);

    cin >> q;
    int a, b;
    while(q--){
        cin >> a >> b;
        cout << query(0, 0, n-1, a-1, b-1) + 1 << endl;
    }
    
    return 0;
}