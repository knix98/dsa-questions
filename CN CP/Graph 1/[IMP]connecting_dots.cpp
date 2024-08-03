/*
https://classroom.codingninjas.com/app/classroom/me/22205/content/575410/offering/8882687/problem/7913
*/


#include<bits/stdc++.h>
using namespace std;

int rows[] = {0, 1, 0, -1};
int cols[] = {1, 0, -1, 0};

bool solve(vector<vector<int>> &board, vector<vector<int>> &vis, int x, int y, int px, int py){  // x,y = current cell; px,py = parent cell
    vis[x][y] = board[x][y];  // marking as visited 

    for(int k=0; k<4; k++){
        int nx = x + rows[k];
        int ny = y + cols[k];

        if(nx >=0 && nx < board.size() && ny >=0 && ny < board[0].size()){
            if(nx == px && ny == py) continue;

            if(board[nx][ny] == board[x][y]){
                if(vis[nx][ny]) return true;

                if(solve(board, vis, nx, ny, x, y)) return true;
            }
        }
    }

    return false;
}

int main(){
    int r, c;
    cin >> r >> c;

    vector<vector<int>> board(r, vector<int>(c));
    char temp;
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cin >> temp;
            board[i][j] = temp;
        }
    }

    vector<vector<int>> vis(r, vector<int>(c, 0));

    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            if(!vis[i][j] && solve(board, vis, i, j, -1, -1)) {
                cout << 1;
                return 0;
            }
        }
    }

    cout << 0;
    return 0;
}