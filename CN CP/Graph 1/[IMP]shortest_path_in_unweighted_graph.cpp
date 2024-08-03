/*
https://classroom.codingninjas.com/app/classroom/me/22205/content/575410/offering/8882687/problem/8573
*/


// intuition : for finding shortest path between 2 nodes in a unweighted graph -> always do bfs
// because using bfs you can know, that at which level from src ,  the dest lies (and that is the shortest path between the 2)
#include<queue>

bool checkPosition(int x, int y, int r, int c){
    return (x >= 0 && x < r && y >= 0 && y < c);
}

int shortestPathBinaryMatrix(vector<vector<int>> &matrix, pair<int, int> src, pair<int, int> dest)
{
    // base case : if src or dest itself is 0 on the matrix
    if(matrix[src.first][src.second] == 0 || matrix[dest.first][dest.second] == 0) return -1;

    int r = matrix.size();
    int c = matrix[0].size();

    queue<pair<int,int>> pending;
    vector<vector<int>> vis(r, vector<int>(c, 0));

    pending.push({src.first, src.second});
    vis[src.first][src.second] = 1;
    pending.push({-1, -1});

    int rows[] = {-1, 0, 1, 0};
    int cols[] = {0, -1, 0, 1};

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

        for(int i=0; i<4; i++){
            int nx = front.first + rows[i];
            int ny = front.second + cols[i];

            if(checkPosition(nx, ny, r, c) && (matrix[nx][ny] == 1) && !vis[nx][ny]){
                pending.push({nx, ny});
                vis[nx][ny] = 1;
            }
        }
    }
}