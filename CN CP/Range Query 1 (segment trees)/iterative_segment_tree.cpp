/*
explanation video = https://www.youtube.com/watch?v=8CuVOdIWLfA
*/

#include <bits/stdc++.h>
using namespace std;
#define int long long

// if the original array size = n, then in segment tree, all these n values would be stored in leaf nodes
// therefore number of nodes in binary tree having n leaf nodes = 2n-1
/*
The size of a segment tree array exceeding 
2n is related to the representation of the tree structure in the array. While the total number of nodes in a segment tree is 
2n−1, the size of the array needed to represent the tree may need to be larger than 
2n to provide a convenient and efficient implementation.
Also, always remember that the numbering inside the segment tree array is 1-based
that is i=1 is root node and then the other nodes
Now this 1 based indexing means that the segment tree's node's values are present at these indexes in the segment tree array,
so it doesnt mean that we cannot store 0 or -ve values in iterative segment tree (because of 1-based indexing)
i = 1-based indexing represents only the node index in segment tree, but the value inside that st[i] can be anything
*/
int sgt[200005];
void build(int n){
    // since the n leaf nodes (from n to 2n-1) are already filled with the respective values
    // now we need to fill the remaining nodes (from 1 to n-1)
    for(int i=n-1;i>=1;i--){
        //if i is parent then it's left child is 2*i and it's right child is 2*i+1
        sgt[i]=sgt[2*i]+sgt[2*i+1];
    }
}
int query(int l, int r, int n)
{
    l+=n;
    r+=n;
    int sum=0;
    while(l<=r)
    {
        if(l&1) {  // means l is left end of range, but right child of its parent
            // so instead of taking l's parent contribution in ans, we take only l's contribution in ans
            sum=sum+sgt[l];
            l++;
        }
        if(!(r&1)){  // means r is right end of range, but left child of its parent
            // so instead of taking r's parent contribution in ans, we take only r's contribution in ans
            sum=sum+sgt[r];
            r--;
        }
        l=l>>1;  //l=l/2;
        r=r>>1;  //r=r/2;
    }
    return sum;
}

void update(int in, int n,int value)
{
    in+=n;
    sgt[in]=value;
    //for root in=1
    while(in>1)
    {
      in=in>>1;//in=in/2;
      //in=1
      sgt[in] = sgt[in*2]+sgt[in*2+1];
    }
    return;
}
int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,q;
    cin>>n>>q;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        sgt[n+i]=arr[i];
    }

    build(n);

    while(q--){
        int type;
        cin>>type;

        if(type==0){
           int l,r;
           cin>>l>>r;
           cout<<query(l,r,n)<<"\n";
        }
        else{
          int in,val;
          cin>>in>>val;
          update(in,n,val);
        }

    }
    return 0;
}
