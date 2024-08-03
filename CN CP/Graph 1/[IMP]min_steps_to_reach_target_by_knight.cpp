/*
this question is similar to previous question => shortest_path_in_unweighted_graph.cpp

https://classroom.codingninjas.com/app/classroom/me/22205/content/575410/offering/8882688/problem/8560
*/



// two ways of doing this 
// 1: with maintaining level approach, using {-1, -1} to indicate change of level in bfs
// 2. maintaining a dist vector denoting the distance of each cell from the dest cell, and marking the dist of each cell = dist of parent cell + 1

// approach 1...
#include<queue>

bool checkPosition(int x, int y, int n){
    return (x >= 0 && x < n && y >= 0 && y < n);
}

int minSteps(pair<int, int> src, pair<int, int> dest, int n) {
    src = {src.first - 1, src.second - 1};
    dest = {dest.first - 1, dest.second - 1};

    queue<pair<int,int>> pending;
    vector<vector<int>> vis(n, vector<int>(n, 0));

    pending.push({src.first, src.second});
    vis[src.first][src.second] = 1;
    pending.push({-1, -1});

    int rows[] = {-2, -1, 1, 2, 2, 1, -1, -2};
    int cols[] = {1, 2, 2, 1, -1, -2, -2, -1};

    int level = 0;
    while(!pending.empty()){
        pair<int,int> front = pending.front();
        pending.pop();

        if(front.first == -1){
            if(pending.empty()) return -1;
            else{
                level++;
                pending.push({-1, -1});
                continue;
            }
        }

        if(front.first == dest.first && front.second == dest.second) return level;

        for(int i=0; i<8; i++){
            int nx = front.first + rows[i];
            int ny = front.second + cols[i];

            if(checkPosition(nx, ny, n) && !vis[nx][ny]){
                pending.push({nx, ny});
                vis[nx][ny] = 1;
            }
        }
    }
}


// approach 2 ...
// // intuition : for finding shortest path between 2 nodes in a graph -> always do bfs
// // because using bfs you can know, that at which level from src ,  the dest lies (and that is the shortest path between the 2)
#include<queue>

bool checkPosition(int x, int y, int n){
    return (x >= 0 && x < n && y >= 0 && y < n);
}

int minSteps(pair<int, int> src, pair<int, int> dest, int n) {
    src = {src.first - 1, src.second - 1};
    dest = {dest.first - 1, dest.second - 1};

    queue<pair<int,int>> pending;
    vector<vector<int>> vis(n, vector<int>(n, 0));

    pending.push({src.first, src.second});
    vis[src.first][src.second] = 1;

    int rows[] = {-2, -1, 1, 2, 2, 1, -1, -2};
    int cols[] = {1, 2, 2, 1, -1, -2, -2, -1};

    vector<vector<int>> dist(n, vector<int>(n, 0));  // will store the distance of each cell from the dest cell
    while(!pending.empty()){
        pair<int,int> front = pending.front();
        pending.pop();

        if(front.first == dest.first && front.second == dest.second) return dist[front.first][front.second];

        for(int i=0; i<8; i++){
            int nx = front.first + rows[i];
            int ny = front.second + cols[i];

            if(checkPosition(nx, ny, n) && !vis[nx][ny]){
                pending.push({nx, ny});
                vis[nx][ny] = 1;
                dist[nx][ny] = dist[front.first][front.second] + 1;
            }
        }
    }
}