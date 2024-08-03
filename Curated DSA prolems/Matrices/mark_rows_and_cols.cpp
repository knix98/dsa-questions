/*
https://classroom.codingninjas.com/app/classroom/me/11692/content/204223/offering/2650147/problem/13859?leftPanelTabValue=PROBLEM

Ninja was feeling bored one day. He went out for a walk and thought of the following problem.

You are given a binary matrix 'mat' with 'M' rows and 'N' columns. You can do the following operations on the matrix -

If the initial value at mat[i][j] is 1, then we set all the cells at the i-th row and j-th column as 1.
Your task is to return the final matrix after all modifications.

Note: Try doing it without any extra space.

Detailed explanation ( Input/output format, Notes, Images )
Sample Input:
3
4
1 0 0 1
0 0 1 0
0 0 0 0
Sample Output:
1 1 1 1
1 1 1 1
1 0 1 1
*/


#include<bits/stdc++.h>
using namespace std;

int main() {
    int r,c;
    cin >> r >> c;

    vector<bool> rowRemaining(r, true);   // the rows which are not affected will be true
    vector<bool> colRemaining(c, true);   // the cols which are not affected will be true
    
    vector<vector<int>> v(r, vector<int>(c));
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++){
            cin >> v[i][j];
            if(v[i][j] == 1) rowRemaining[i] = false, colRemaining[j] = false;
        }   
    }

    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            if(rowRemaining[i] && colRemaining[j]) {
                cout << 0 << " ";
            }
            else cout << 1 << " ";
        }
        cout << endl;
    }
}
