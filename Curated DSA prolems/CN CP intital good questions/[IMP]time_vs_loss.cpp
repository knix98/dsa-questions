/*
https://classroom.codingninjas.com/app/classroom/me/22205/content/575394/offering/8882389/problem/15476?leftPanelTabValue=PROBLEM

Ninja works in an XYZ MNC which follows a very strict rule regarding the pay. Ninja has been assigned ‘N’ tasks. 
\Each task requires some days to finish, which is given in the form of an array ‘TIME’. 
For each day of delay before starting to work in task ‘i’ a loss is incurred on Ninjas’ pay which is given in an array ‘LOSS’. 
Ninja asks you for help to find the order in which the tasks should be completed such that there is a minimum loss in Ninjas’ pay.

Note:
If there are multiple solutions, print the order with smaller indices first.
Example:
Let ‘TIME’ array be: [2, 4, 1]
Let ‘LOSS’ array be: [1, 2, 3]
Order 1 2 3 will cause loss of 4 + 18 = 22
Order 3 1 2 will cause loss of 1+ 6 = 7 which is the minimum possible loss.
Hence the answer is [3, 1, 2].
Detailed explanation ( Input/output format, Notes, Images )
Constraints :
1 <= T <= 10
1 <= N <= 10^5
1<= TIME[i], LOSS[i] <= 10^7

Time Limit: 1 sec
Sample Input 1 :
2
4
4 1000 2 5
3 1 2 4
3
2 4 1
1 2 3
Sample Output 1 :
3 4 1 2
3 1 2
Explanation For Sample Input 1 :
For test case 1: 
Order 1 2 3 4 will cause a loss of 4 + 2008 + 4024 = 6036
Order 2 3 1 4 will cause loss of 2000 + 6006 + 4024 = 12030
Order 3 4 1 2 wil.l cause loss of 8 + 21 + 11 = 40 which is the minimum possible loss.

For test case 2: 
Order 1 2 3 will cause loss of 4 + 18 = 22
Order 3 1 2 will cause loss of 3 + 3 = 6 which is the minimum possible loss.
Sample Input 2 :
1
5
2 4 1 3 2
1 2 3 5 6
Sample Output 2 :
3 5 4 1 2
*/



#include<bits/stdc++.h>

// APPROACH and thinking process is written in CN CP notes
// Basically : index of a job is proportional to time/loss
vector<int> minLoss(int n, vector<int> &time, vector<int> &loss) {
    vector<pair<float,int>> ratioIndices;

    for(int i=0; i<n; i++){
        float temp = (float)(time[i]) / loss[i]; 
        pair<float,int> p(temp, i+1);
        ratioIndices.push_back(p);
    }    

    sort(ratioIndices.begin(), ratioIndices.end());

    vector<int> ans;

    for(int i=0; i<n; i++){
        ans.push_back(ratioIndices[i].second);
    }

    return ans;
}