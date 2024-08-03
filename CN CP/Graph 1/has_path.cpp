/*
https://classroom.codingninjas.com/app/classroom/me/22205/content/575410/offering/8882672/problem/7860  
*/



#include<bits/stdc++.h>
using namespace std;

// this problem can be solved using DSU also, because we just need to check whether v1 and v2 belong to same connected graph or not
// In below code I have done using bfs graph traversal just for practice
// just do bfs traversal over graph in which v1 is present and then check whether v2 was visited or not
// in both the implementations : DSU and bfs : Time : O(v+e)

string hasPath(vector<vector<int>> &graph, int v1, int v2){
    int v = graph.size();
    queue<int> pending;
    vector<int> vis(v, 0);

    pending.push(v1);
    vis[v1] = 1;

    while(!pending.empty()){
        int front = pending.front();
        pending.pop();

        for(int i : graph[front]){
            if(i == v2) return "true";   

            if(!vis[i]){
                pending.push(i);
                vis[i] = 1;
            }
        }
    }

    if(vis[v2]) return "true";
    else return "false";
}

int main(){
    int t;
    cin >> t;

    while(t--){
        int v, e;
        cin >> v >> e;

        vector<vector<int>> graph(v);
        int a, b;
        for(int i=0; i<e; i++){
            cin >> a >> b;

            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        int v1, v2;
        cin >> v1 >> v2;

        cout << hasPath(graph, v1, v2) << endl;
    }
    
    return 0;
}