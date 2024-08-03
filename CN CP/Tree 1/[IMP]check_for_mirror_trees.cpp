/*
https://classroom.codingninjas.com/app/classroom/me/22205/content/575409/offering/8882659/problem/16324
*/



// first is better approach, second approach is my approach
bool checkMirror(int n, vector<vector<int>> &edgesA, vector<vector<int>> &edgesB)
{
    // in any of the edges vector, edges[0] is the parent and edges[1] is its child
    // so in adjacency list, we can be sure that the values contained in any index is the index's children nodes only
    // so building adjacency lists 
    vector<vector<int>> treeA(n, vector<int>(0));
    vector<vector<int>> treeB(n, vector<int>(0));  // since 0 to n-1 vertices

    for(int i=0; i<edgesA.size(); i++){
        treeA[edgesA[i][0]].push_back(edgesA[i][1]);
    }
    for(int i=0; i<edgesB.size(); i++){
        treeB[edgesB[i][0]].push_back(edgesB[i][1]);
    }

    // The beautiful trick : just check for each same-node in treeA and treeB that,
    // 1. treeA.number_of_children == treeB.number_of_children
    // 2. treeA's children from left to right == treeB's children from right to left
    for(int i=0; i<n; i++){
        int currentParent = i;

        // 1. treeA.number_of_children == treeB.number_of_children
        if(treeA[currentParent].size() != treeB[currentParent].size()) return false;

        // 2. treeA's children from left to right == treeB's children from right to left
        for(int i=0, j=treeB[currentParent].size() - 1; j>=0; i++, j--){
            // i will traverse over treeA and j will traverse over treeB children
            if(treeA[currentParent][i] != treeB[currentParent][j]) return false;
        }
    }

    return true;
}




// in this approach by me : I am using 2 queues to do a level order traversal on treeA and treeB separately
// just the difference being in treeA traversal from left to right, and in treeB traversal from right to left
#include<bits/stdc++.h>

bool bfs(vector<vector<int>> &treeA, vector<vector<int>> &treeB, int n){
    queue<int> a, b;
    vector<bool> visitedA(n, false), visitedB(n, false);
    a.push(0);
    b.push(0);
    visitedA[0] = visitedB[0] = true;  // inserted in queue, so mark visited

    while(!a.empty() || !b.empty()){
        if(a.empty() || b.empty()) return false;

        int afront = a.front();
        int bfront = b.front();
        if(afront != bfront) return false;

        a.pop();
        b.pop();

        for(int i=0; i<treeA[afront].size(); i++){
            int nextNode = treeA[afront][i];
            if(!visitedA[nextNode]) {
                a.push(nextNode);
                visitedA[nextNode] = true;
            }
        }
        for(int i=treeB[bfront].size() - 1; i>=0; i--){
            int nextNode = treeB[bfront][i];
            if(!visitedB[nextNode]) {
                b.push(nextNode);
                visitedB[nextNode] = true;
            }
        }
    }

    return true;
}

bool checkMirror(int n, vector<vector<int>> &edgesA, vector<vector<int>> &edgesB)
{
    vector<vector<int>> treeA(n, vector<int>(0));
    vector<vector<int>> treeB(n, vector<int>(0));

    for(int i=0; i<edgesA.size(); i++){
        treeA[edgesA[i][0]].push_back(edgesA[i][1]);
        treeA[edgesA[i][1]].push_back(edgesA[i][0]);
        treeB[edgesB[i][0]].push_back(edgesB[i][1]);
        treeB[edgesB[i][1]].push_back(edgesB[i][0]);
    }

    return bfs(treeA, treeB, n);
}