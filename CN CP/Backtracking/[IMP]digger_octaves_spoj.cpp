/*
After many years spent playing Digger, little Ivan realized he was not taking advantage of the octaves. Oops, sorry! Most of you were not born when Digger came to light!

Digger is a Canadian computer game, originally designed for the IBM personal computer, back in 1983. The aim of the game is to collect precious gold and emeralds buried deep in subterranean levels of and old abandoned mine.

We Digger gurus call a set of eight consecutive emeralds an octave. Notice that, by consecutive we mean that we can collect them one after another. Your Digger Mobile is able to move in the four directions: North, South, West and East.

In a simplified Digger version, consisting only of emeralds and empty spaces, you will have to count how many octaves are present for a given map.

Input
Input starts with an integer T, representing the number of test cases (1<=T<=20). Each test case consists of a map, described as follows:

An integer N (1<=N<=8), representing the side length of the square-shaped map. N lines follow, N characters each. A 'X' character represents an emerald, and a '.' represents an empty space.

Output
For each test case print the number of octaves on a single line.

Example
Input:
2
3
XXX
X.X
XXX
3
XXX
XXX
XXX

Output:
1
5
*/




// Explanation written in CN CP notes
// Time : (N^2)*(3^7) , because in worst case, every one of N^2 squares would be a valid cell, so we start from any 1 of them and then we have 3 directions to move 
// (assuming all three directions are valid in worst case) and we will do it 7 times till we finally reach the 8th valid cell
// Space : O(N^2) , for storing board in N^2 cells (no of recursive calls would go till only 8 at max at any given time)
#include<bits/stdc++.h>
using namespace std;

void solve(vector<vector<int>> &board, int x, int y, string &check, set<string> &ansPaths, vector<vector<int>> &cellNumber) {
    // x,y represents a valid cell , where we should put 0 in the first step
    board[x][y] = 0;
    check += ('0' + cellNumber[x][y]);

    if(check.size() == 8) { // base case
        string temp = check;
        sort(temp.begin(), temp.end());
        ansPaths.insert(temp);
        board[x][y] = 1;        // IMP : Since we have already marked the current position as visited, so in base case also before returning, we need to unmark and then return
        check.pop_back();
        return;
    }

    if(x-1 >= 0 && board[x-1][y] != 0){
        solve(board, x-1, y, check, ansPaths, cellNumber);
    }
    if(y+1 < board.size() && board[x][y+1] != 0){
        solve(board, x, y+1, check, ansPaths, cellNumber);
    }
    if(x+1 < board.size() && board[x+1][y] != 0){
        solve(board, x+1, y, check, ansPaths, cellNumber);
    }
    if(y-1 >= 0 && board[x][y-1] != 0){
        solve(board, x, y-1, check, ansPaths, cellNumber);
    }

    board[x][y] = 1;
    check.pop_back();
    return;
}

int main() {
    int t;
    cin >> t;

    vector<int> ans;

    while(t--) {
        int n;
        cin >> n;

        vector<vector<int>> board(n, vector<int>(n, 0));

        // we will need to store sequence of the cellNumbers visited in a string , so we will get cellNumbers from a universal 2D matrix cellNumber
        vector<vector<int>> cellNumber(n, vector<int>(n, 0));
        int cellNum = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                char c;
                cin >> c;
                if(c == 'X') board[i][j] = 1;
                cellNumber[i][j] = cellNum++;
            }
        }

        string check = "";
        set<string> ansPaths; // so that we store only unique path-strings (after path-string is sorted)

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                // if i,j is a valid starting point...
                if(board[i][j]) solve(board, i, j, check, ansPaths, cellNumber);
            }
        }

        ans.push_back(ansPaths.size());
    }

    for(int i=0; i<ans.size(); i++){
        cout << ans[i] << endl;
    }
}