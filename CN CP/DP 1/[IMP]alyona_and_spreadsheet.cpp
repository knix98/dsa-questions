/*
Alyona and Spreadsheet

During the lesson small girl Alyona works with one famous spreadsheet computer program and learns how to edit tables.
Now she has a table filled with integers. The table consists of n rows and m columns. By ai, j we will denote the integer located at the i-th row and the j-th column. We say that the table is sorted in non-decreasing order in the column j if ai, j ≤ ai + 1, j for all i from 1 to n - 1.
Teacher gave Alyona k tasks. For each of the tasks two integers l and r are given and Alyona has to answer the following question: if one keeps the rows from l to r inclusive and deletes all others, will the table be sorted in non-decreasing order in at least one column? Formally, does there exist such j that ai, j ≤ ai + 1, j for all i from l to r - 1 inclusive.
Alyona is too small to deal with this task and asks you to help!

Input
The first line of the input contains two positive integers n and m (1 ≤ n·m ≤ 100 000) — the number of rows and the number of columns in the table respectively. Note that your are given a constraint that bound the product of these two integers, i.e. the number of elements in the table.

Each of the following n lines contains m integers. The j-th integers in the i of these lines stands for ai, j (1 ≤ ai, j ≤ 109).

The next line of the input contains an integer k (1 ≤ k ≤ 100 000) — the number of task that teacher gave to Alyona.

The i-th of the next k lines contains two integers li and ri (1 ≤ li ≤ ri ≤ n).
Output
Print "Yes" to the i-th line of the output if the table consisting of rows from li to ri inclusive is sorted in non-decreasing order in at least one column. Otherwise, print "No".

Sample Input
5 4
1 2 3 5
3 1 3 2
4 5 2 3
5 5 3 2
4 4 3 4
6
1 1
2 5
4 5
3 5
1 3
1 5
Sample Output
Yes
No
Yes
Yes
Yes
No
Explanation
In the sample, the whole table is not sorted in any column. However, rows 1–3 are sorted in column 1, while rows 3-5 are sorted in column 3.
*/




#include <bits/stdc++.h>
using namespace std;

int main()
{
    int r,c;
    cin >> r >> c;

    vector<vector<int>> a;
    for(int i=0; i<r; i++){
        vector<int> v(c);
        for(int j=0; j<c; j++) cin >> v[j];

        a.push_back(v);
    }

    int k;
    cin >> k;
    vector<pair<int,int>> pairs(k);
    for(int i=0; i<k; i++){
        int L1, R1;
        cin >> L1 >> R1;
        pair<int,int> p(L1, R1);
        pairs[i] = p;
    }

    vector<int> rowIncreasingEnd(r); // this would represent the current column in consideration
                                                        // and would store for each row in the current column => what is the 1-based index upto which there exists
                                                        // a continuous increasing subsequence starting from the current row
    
    vector<int> maxIncreasingEnd(r, 0); // this would store => for a particular row of the table, what is the max 1-based index upto which,
                                                            // there exists a continuos increasing sequence in 1 of the columns 

    for(int j=0; j<c; j++){
        // first calculating the increasing end value for the last row separately
        // max increasing end for last row = the last row itself
        rowIncreasingEnd[r-1] = r;
        // comparing the max-increasing-end for this row of the current column with the global max-increasing-end of this row for the whole table
        if(maxIncreasingEnd[r-1] < rowIncreasingEnd[r-1]) maxIncreasingEnd[r-1] = rowIncreasingEnd[r-1];

        for(int i=r-2; i>=0; i--){
            if(a[i+1][j] >= a[i][j]) rowIncreasingEnd[i] = rowIncreasingEnd[i+1]; // means an increasing subsequence exists ahead
            else rowIncreasingEnd[i] = i+1; // means no increasing subsequence ahead

            if(maxIncreasingEnd[i] < rowIncreasingEnd[i]) maxIncreasingEnd[i] = rowIncreasingEnd[i];
        }
    }
    

    vector<string> answers;
    for(int i=0; i<k; i++){
        int L = pairs[i].first, R = pairs[i].second;
        if(maxIncreasingEnd[L-1] >= R) answers.push_back("Yes");
        else answers.push_back("No");
    }

    for(auto i : answers) cout << i << endl;

    return 0;
}