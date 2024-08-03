/*
https://classroom.codingninjas.com/app/classroom/me/22205/content/575426/offering/8882988/problem/20513?leftPanelTabValue=PROBLEM
*/


#include<stack>

vector<vector<int>> g(100001);
bool visited[100001], onStack[100001];
int inTime[100001], low[100001];
int timer;
stack<int> st;

void dfs(int node, pair<int,int> &ans, vector<int> &c){
    inTime[node] = low[node] = timer++;
    visited[node] = onStack[node] = true;
    st.push(node);

    for(int v : g[node]){
        if(visited[v]){
            // in case of back edge, we only compare low-link value if v is onStack
            if(onStack[v]) low[node] = min(low[node], inTime[v]);
        }
        else{
            dfs(v, ans, c);
            low[node] = min(low[node], low[v]);
        }
    }

    if(low[node] == inTime[node]){
        // that means this current node is the starting point of a SCC
        int minCost = INT_MAX;
        int minCount = 0;
        while(st.top() != node){
            int topNode = st.top();
            st.pop();

            if(c[topNode-1] < minCost) {
                minCost = c[topNode-1];
                minCount = 1;
            }
            else if(c[topNode-1] == minCost){
                minCount++;
            }
        }

        // the last remaining int in stack would be the node itself
        int topNode = st.top();
        st.pop();

        if(c[topNode-1] < minCost) {
            minCost = c[topNode-1];
            minCount = 1;
        }
        else if(c[topNode-1] == minCost){
            minCount++;
        }

        // push this scc in ans
        ans.first += minCost;
        ans.second *= minCount;
    }
}

pair<int,int> checkpoints(int n, int m, vector<int> &c, vector<pair<int,int>> &edges){
    // clearing macros
    for(int i=1; i<=n; i++) {
        g[i].clear();
        visited[i] = onStack[i] = false;
    }
    timer = 0;

    // making adjacency list for directed graph
    for(auto edge : edges){
        g[edge.first].push_back(edge.second);
    }

    pair<int, int> ans = {0,1};
    for(int i=1; i<=n; i++) if(!visited[i]) dfs(i, ans, c);
    return ans;
}