/*
Sort input array in this order : a[0] >= a[1] <= a[2] >= a[3] <= a[4] >= a[5] <= a[6]
means in this way => 1    2    3    4
                      \  /  \ /  \ /
                        5    6    7
*/

#include<bits/stdc++.h>
using namespace std;

void waveSort(vector<int> &v){
    if(v.size() < 3){
        return;
    }

    int i = 1; // will start from i = 1 and keep jumping by 2
    for( ; i <= v.size() - 2; i += 2){
        if(v[i-1] < v[i]){
            v[i-1] ^= v[i] ^= v[i-1] ^= v[i];
        }
        if(v[i+1] < v[i]){
            v[i+1] ^= v[i] ^= v[i+1] ^= v[i];
        }
    }

    if(i == v.size() - 1){
        if(v[i-1] < v[i]){
            v[i-1] ^= v[i] ^= v[i-1] ^= v[i];
        }
    }
}

int main () {
    vector<int> v{1,3,4,7,5,6,2,8};

    waveSort(v);
    for(int i = 0; i<v.size(); i++){
        cout << v[i] << " ";
    }

    return 0;
}