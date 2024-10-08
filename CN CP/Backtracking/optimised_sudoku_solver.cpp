/*
You have been given a 9 X 9 2D matrix 'MATRIX' with some cells filled with digits(1 - 9), and some empty cells (denoted by 0).
You need to find whether there exists a way to fill all the empty cells with some digit(1 - 9) such that the final matrix is a valid Sudoku solution.
A Sudoku solution must satisfy all the following conditions-
1. Each of the digits 1 - 9 must occur exactly once in each row.
2. Each of the digits 1 - 9 must occur exactly once in each column.
3. Each of the digits 1 - 9 must occur exactly once in each of the 9, 3 x 3 sub-matrices of the matrix.
Note
1. There will always be a cell in the matrix which is empty.
2. The given initial matrix will always be consistent according to the rules mentioned in the problem statement.
Input Format:
The first line contains a single integer 'T' denoting the number of test cases.
Then 'T' test cases follow.

Every test case contains 9 lines, with each line containing 9 single space-separated digits (0, if the cell is empty or a digit (1 - 9) otherwise).
Output Format:
For each test case, print a single line containing “yes”(without quotes), if there exists a Sudoku solution or “no” (without quotes) otherwise. Note the lowercase format of the output.
Note:
You do not need to print anything, it has already been taken care of. Just implement the given function.
Constraints:
1 <= 'T' <= 5
N = 9
0 <= MATRIX[i][j] <= 9

Where 'N' denotes the size of the given square matrix.

Time Limit: 1sec
Sample Input 1:
1
9 0 0 0 2 0 7 5 0 
6 0 0 0 5 0 0 4 0 
0 2 0 4 0 0 0 1 0 
2 0 8 0 0 0 0 0 0 
0 7 0 5 0 9 0 6 0 
0 0 0 0 0 0 4 0 1 
0 1 0 0 0 5 0 8 0 
0 9 0 0 7 0 0 0 4 
0 8 2 0 4 0 0 0 6
Sample Output 1:
yes
Explanation of the Sample Input1:
One of the possible solutions is:
9 4 1 3 2 6 7 5 8
6 3 7 1 5 8 2 4 9
8 2 5 4 9 7 6 1 3
2 6 8 7 1 4 3 9 5
1 7 4 5 3 9 8 6 2
3 5 9 6 8 2 4 7 1
4 1 3 2 6 5 9 8 7
5 9 6 8 7 3 1 2 4
7 8 2 9 4 1 5 3 6
Sample Input 2:
1
1 5 9 0 0 6 0 3 2
2 7 4 0 0 0 0 0 0
3 8 6 2 0 0 0 0 5
4 9 2 5 0 1 0 8 0
6 3 7 0 4 0 0 0 0
5 1 0 8 2 0 0 0 0
8 2 1 0 0 0 0 0 0
7 6 0 1 0 0 4 2 0
9 4 3 0 7 0 0 6 1
Sample Output 2:
no
Explanation of the Sample Input2:
In the third column from the left, there are two empty cells out of which one has to be filled with ‘8’, but we can’t put 8 in any of those two cells.
*/




// basically we optimised sudoku solver by storing the already present numbers in :
// 1. all rows  2. all cols    3. all 3*3 blocks    in an unordered map
#include<bits/stdc++.h>

void fillHor(vector<unordered_map<int,int>> &hor, int matrix[9][9]) { // func for filling rows map
    for(int i=0; i<9; i++){
        unordered_map<int,int> mp;

        for(int j=0; j<9; j++){
            if(matrix[i][j] > 0) mp[matrix[i][j]]++;
        }

        hor.push_back(mp);
    }
}

void fillVer(vector<unordered_map<int,int>> &ver, int matrix[9][9]) { // func for filling cols map
    for(int i=0; i<9; i++){
        unordered_map<int,int> mp;

        for(int j=0; j<9; j++){
            if(matrix[j][i] > 0) mp[matrix[j][i]]++;
        }

        ver.push_back(mp);
    }
}

void fillBlock(vector<vector<unordered_map<int,int>>> &block, int matrix[9][9]) { // func for filling 3*3 blocks map
    for(int i=0; i<=6; i=i+3){
        vector<unordered_map<int,int>> vect;

        for(int j=0; j<=6; j=j+3){
            unordered_map<int,int> mp;

            for(int x = i; x < i+3; x++){
                for(int y = j; y < j+3; y++){
                    if(matrix[x][y] > 0) mp[matrix[x][y]]++;
                }
            }

            vect.push_back(mp);
        }

        block.push_back(vect);
    }
}

bool solve(int matrix[9][9], int x, int y, vector<unordered_map<int,int>> &hor, vector<unordered_map<int,int>> &ver, vector<vector<unordered_map<int,int>>> &block) {
    for(int i=x; i<9; i++){
        for(int j = i==x ? y : 0; j<9; j++){   // VERY IMP : // initialize j to 0 if, we have gone into a new row of sudoku
            if(matrix[i][j] == 0){
                for(int k = 1; k<=9; k++){
                    if(hor[i][k] > 0) continue;
                    if(ver[j][k] > 0) continue;

                    int blockI = 0;
                    int blockJ = 0;
                    if(i >= 3 && i < 6) blockI = 1;
                    else if(i >= 6) blockI = 2;

                    if(j >= 3 && j < 6) blockJ = 1;
                    else if(j >= 6) blockJ = 2;

                    if(block[blockI][blockJ][k] > 0) continue;

                    matrix[i][j] = k;
                    hor[i][k]++;
                    ver[j][k]++;
                    block[blockI][blockJ][k]++;

                    if(solve(matrix, i, j, hor, ver, block)) return true;

                    matrix[i][j] = 0;
                    hor[i][k]--;
                    ver[j][k]--;
                    block[blockI][blockJ][k]--;
                }

                return false;
            }
        }
    }

    return true;
}

bool isItSudoku(int matrix[9][9]) {
    vector<unordered_map<int,int>> hor;
    vector<unordered_map<int,int>> ver;
    vector<vector<unordered_map<int,int>>> block;

    fillHor(hor, matrix);
    fillVer(ver, matrix);
    fillBlock(block, matrix);

    return solve(matrix, 0, 0, hor, ver, block);
}