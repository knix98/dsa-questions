/*
https://classroom.codingninjas.com/app/classroom/me/22205/content/575426/offering/8882988/problem/7908?leftPanelTabValue=PROBLEM
*/



#include<bits/stdc++.h>
using namespace std;

#define ll long long

const ll mod = 1e9 + 7;
ll fact[1000001];

int rows[] = {-2, -2, -1, 1, 2, 2, 1, -1};
int cols[] = {-1, 1, 2, 2, 1, -1, -2, -2};

bool isValidCell(int x, int y, int n, int m){
    return (x >= 0 && x < n && y>=0 && y<m);
}

void dfs(vector<vector<int>> &board, int x, int y, int &count){
    board[x][y] = 1;
    count++;

    int nx, ny;
    for(int i=0; i<8; i++){
        nx = x + rows[i];
        ny = y + cols[i];

        if(isValidCell(nx, ny, board.size(), board[0].size())) {
            if(board[nx][ny] == 0) dfs(board, nx, ny, count);
        }
    }
}

int main(){
    fact[0] = 1;
    for(int i=1; i<=1000000; i++) fact[i] = (i * fact[i-1]) % mod;

    int t;
    cin >> t;

    int n, m, q, a, b;
    while(t--){
        cin >> n >> m >> q;
        
        vector<vector<int>> board(n+1, vector<int>(m+1, -1));
        for(int i=0; i<q; i++){
            cin >> a >> b;
            board[a][b] = 0;
        }

        ll ans = 1;
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(board[i][j] == 0) {
                    int count = 0;
                    dfs(board, i, j, count);
                    ans = (ans * fact[count]) % mod;
                }
            }
        }

        cout << ans << endl;
    }

    return 0;
}