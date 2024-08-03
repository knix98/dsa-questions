/*
https://classroom.codingninjas.com/app/classroom/me/22205/content/575426/offering/8882974/problem/9441?leftPanelTabValue=PROBLEM
*/



#include<stack>

vector<vector<int>> g(2001);
bool visited[2001], onStack[2001];
int inTime[2001], low[2001];
int timer;
stack<int> st;
vector<vector<int>> ans;

void dfs(int node){
    inTime[node] = low[node] = timer++;
    visited[node] = onStack[node] = true;
    st.push(node);

    for(int v : g[node]){
        if(visited[v]){
            // in case of back edge, we only compare low-link value if v is onStack
            if(onStack[v]) low[node] = min(low[node], inTime[v]);
        }
        else{
            dfs(v);
            low[node] = min(low[node], low[v]);
        }
    }

    if(low[node] == inTime[node]){
        // that means this current node is the starting point of a SCC
        vector<int> scc;
        while(st.top() != node){
            scc.push_back(st.top());
            st.pop();
        }

        // the last remaining int in stack would be the node itself
        scc.push_back(st.top());
        st.pop();

        // push this scc in ans
        ans.push_back(scc);
    }
}

vector<vector<int>> stronglyConnectedComponents(int n, vector<vector<int>> &edges)
{
    // clearing macros
    for(int i=0; i<n; i++) {
        g[i].clear();
        visited[i] = onStack[i] = false;
    }
    timer = 0;
    ans.clear();

    // making adjacency list for directed graph
    for(auto edge : edges){
        g[edge[0]].push_back(edge[1]);
    }

    for(int i=0; i<n; i++) if(!visited[i]) dfs(i);
    return ans;
}









