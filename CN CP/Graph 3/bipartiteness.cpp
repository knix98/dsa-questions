/*
https://classroom.codingninjas.com/app/classroom/me/22205/content/575426/offering/8882988/problem/20253?leftPanelTabValue=PROBLEM
*/



int bipartite(vector<vector<int>>& edges, int n) {
    vector<vector<int>> g(n+1, vector<int>(0));
    for(auto edge : edges){
        g[edge[0]].push_back(edge[1]);
        g[edge[1]].push_back(edge[0]);
    }

    int g0 = 0;  // count of nodes in group 0
    int g1 = 0;  // count of nodes in group 1
    vector<int> group(n+1, -1);  // to store the group number of each node

    // bfs...
    queue<pair<int,int>> pending;
    pending.push({1, 0});
    group[1] = 0;

    while(!pending.empty()){
        pair<int,int> front = pending.front();
        pending.pop();
        int node = front.first;
        int groupNumber = front.second;
        if(groupNumber == 0) g0++;
        else g1++;

        for(int child : g[node]){
            if(group[child] == -1) {
                // means not visited
                pending.push({child, groupNumber^1});
                group[child] = groupNumber^1;
            }
        }
    }

    int ans = 0;
    for(int i=1; i<=n; i++){
        if(group[i] == 0){
            ans += (g1 - g[i].size());
        }
    }

    return ans;
}