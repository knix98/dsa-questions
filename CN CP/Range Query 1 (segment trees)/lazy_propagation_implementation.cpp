/*
basically lazy propagation is used when instead of just single point update, you are asked to do a range update, i.e update the values in range [1,3] by +3
*/ 

#include<bits/stdc++.h>
#define M (beg+end)/2
using namespace std;

const int N = (int)(1e5+5);

int a[N];
int st[4*N];
int lazy[4*N];

void pushdown(int pos, int beg, int end) {
	if(lazy[pos] > 0) {
		st[pos] += (end-beg+1) * lazy[pos];  // first update current node's value. Since all elems of range would be updated, so adding lazy value that much times to current node's value
		if(beg != end) {  // and then update lazy value for child nodes
			lazy[2*pos+1] += lazy[pos];
			lazy[2*pos+2] += lazy[pos];
		}
		lazy[pos] = 0;   // since current node's lazy value has been dealt with, so make it 0
	} 
}

void build(int beg, int end, int pos) {
	if(beg == end) {
		st[pos] = a[beg];
		return;
	}

	build(beg, M, 2*pos+1);
	build(M+1, end, 2*pos+2);
	st[pos] = st[2*pos+1] + st[2*pos+2];
}

void update(int beg, int end, int ul, int ur, int val, int pos) {
	pushdown(pos, beg, end);  // always call pushdown first
	if(ul <= beg and ur >= end) {
        // means this node's range is completely inside our query range,
        // so first just add the lazy value here and then call pushdown , so that this node's value will be updated and also lazy value pushed down to child nodes as well
        // and return
		lazy[pos] += val;
		pushdown(pos, beg, end);
		return;
	}

	if(ul > end or ur < beg) return;

	update(beg, M, ul, ur, val, 2*pos+1);
	update(M+1, end, ul, ur, val, 2*pos+2);
	st[pos] = st[2*pos+1] + st[2*pos+2];
}

int query(int beg, int end, int ql, int qr, int pos) {
	pushdown(pos, beg, end);  // always call pushdown first
	if(ql <= beg and qr >= end) {
		return st[pos];
	}

	if(ql > end or qr < beg) return 0;

	return query(beg, M, ql, qr, 2*pos+1) + query(M+1, end, ql, qr, 2*pos+2);
}

signed main() {

	a[0] = 1;
	a[1] = 5;
	a[2] = 3;
	a[4] = 2;
	build(0, 3, 0);
	cout<< query(0, 3, 0, 2, 0) <<"\n";  // sum query for range [0,2]
	update(0, 3, 1, 2, 2, 0);            // update range [1,2] by +2
	cout<< query(0, 3, 0, 2, 0) <<"\n";  // sum query for range [0,2]

	return 0;
}
// [1, 7, 5, 2]