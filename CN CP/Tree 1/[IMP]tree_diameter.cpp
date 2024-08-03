/*
Tree Diameter

You are given a tree with N vertex and N - 1 edge and you are supposed to find the diameter of the tree.
Diameter of a tree is defined as the maximum distance between any pair of leaves of a tree.
Input Format:
The first line of input will contain T(number of test case), each test case follows as.
Line1: contain an integer N denoting the number of a vertex in the tree.
Next, N - 1 line contains two space-separated integers u and v denoting the edge between the vertex u and v.
Output Format:
For each test case print the diameter of the tree in a new line.
Constraints:
1 <= T <= 100
2 <= N <= 10^4
1 <= u, v <= N
Sample Input:
1
8
1 7
5 1
2 7
5 6
8 1
3 6
2 4
Sampe output:
6
*/




#include<bits/stdc++.h>
using namespace std;

// this func would return the height of the root tree, and also calculate the max dia of a path that diverges at this root
// and then this func would check whether the dia calculated at this root is greater than the global maxDia 
// and this way after the completion of this function, we would get the maxDia value stored in the global reference variable
int solve(int root, int parent, vector<int> *tree, int &maxDia){
    int bestSubtreeHeight = -1;
    int secondBestSubtreeHeight = -1;

    for(int i=0; i<tree[root].size(); i++){
        if(tree[root][i] != parent){
            int subtreeHeight = solve(tree[root][i], root, tree, maxDia);

            if(subtreeHeight >= bestSubtreeHeight){
                secondBestSubtreeHeight = bestSubtreeHeight; 
                bestSubtreeHeight = subtreeHeight;
            }
            else if(subtreeHeight >= secondBestSubtreeHeight){
                secondBestSubtreeHeight = subtreeHeight; 
            }
        }
    }

    int maxDiaAtCurrRoot = bestSubtreeHeight + secondBestSubtreeHeight + 2;
    maxDia = maxDia > maxDiaAtCurrRoot ? maxDia : maxDiaAtCurrRoot;

    return bestSubtreeHeight + 1;
}

int main(){
    int t;
    cin >> t;

    vector<int> answers;
    while(t--){
        int n;
        cin >> n;

        // preparation of the adjacency list for the tree
        vector<int> tree[n+1];
        for(int i=0; i<n-1; i++){
            int u, v;
            cin >> u >> v;

            tree[u].push_back(v);
            tree[v].push_back(u);
        }

        int ans = 0;
        solve(1, 0, tree, ans);
        answers.push_back(ans);
    }

    for(int i : answers) cout << i << endl;

    return 0;
}