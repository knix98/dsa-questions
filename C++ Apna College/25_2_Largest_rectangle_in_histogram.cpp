#include<bits/stdc++.h>
using namespace std;

int larRect(vector<int> &v){
    int maxArea = 0;

    stack<int> remainingIndices;  // will contain all the indices whose area calculation is still left
    remainingIndices.push(0);

    int i = 1; // this i will traverse over the vector v

    while(i < v.size()){
        while(!remainingIndices.empty() && v[remainingIndices.top()] >= v[i]){ // remove all such indices from top whose value is >= v[i]
            int index = remainingIndices.top();
            remainingIndices.pop();

            if(v[index] != v[i]){ // no need to calculate area of such index whose value is equal to v[i]
                int ls = remainingIndices.empty() ? -1 : remainingIndices.top();
                int rs = i;

                int indexArea = v[index] * ((rs - ls) - 1);
                maxArea = maxArea < indexArea ? indexArea : maxArea;
            }
        }

        remainingIndices.push(i++);
    }

    while(!remainingIndices.empty()){
        int index = remainingIndices.top();
        remainingIndices.pop();

        int ls = remainingIndices.empty() ? -1 : remainingIndices.top();
        int indexArea = v[index] * ((v.size() - ls) - 1);
        maxArea = maxArea < indexArea ? indexArea : maxArea;
    }

    return maxArea;
}

int main() {
    vector<int> v{3,1,5,6,2,3};
    cout << larRect(v);
}