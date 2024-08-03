/*
https://classroom.codingninjas.com/app/classroom/me/11692/content/204223/offering/2650147/problem/13860?leftPanelTabValue=PROBLEM

Roy loves eating chocolates. He has a grid 'MAT' of N X N chocolates in which every chocolate has its size value written on it and inside the grid, the chocolates are present in sorted order. That is every row and column of chocolates are in non-decreasing order.

Now Roy wants to eat all the chocolates one by one but he wants to eat the chocolates in sorted order, for this, he wants help from you.

Your task is to return a list containing all the chocolates in ascending order according to their sizes.

For example:

If the chocolate grid 'MAT' is:

12 23 35 41
44 46 49 51
45 52 55 67
61 69 71 72

The output will be the elements of 'MAT' in sorted order:
12 23 35 41 44 45 46 49 51 52 55 61 67 69 71 72.
Follow Up:

Can you solve this in O((N ^ 2) * log(N)) time and O(N) space complexity?
Detailed explanation ( Input/output format, Notes, Images )
Sample Input 1 :
1
3
1 5 6
2 6 7
4 8 9
Sample Output 1:
10 15 20 20 27 29 30 32 33 35 37 38 40 42 46 49
Explanation for Input 1:
After sorting all the chocolates of the 'GRID' in ascending order, we will get 1 2 4 5 6 6 7 8 9.
Sample Input 2 :
2
2
1 2 
5 6
4
10 20 30 40
15 20 35 42
27 29 37 46
32 33 38 49
Sample Output 2:
1 2 5 6
10 15 20 20 27 29 30 32 33 35 37 38 40 42 46 49
*/




#include<queue>
#include<vector>
using namespace  std;

class cmp{
    public:
      bool operator()(pair<vector<int> *, int> &a, pair<vector<int> *, int> &b){
          return (*(a.first)).at(a.second) > (*(b.first)).at(b.second);
      }
};

vector<int> sortedMatrix(vector<vector<int>> &mat, int n) 
{
    priority_queue<pair<vector<int>*, int>, vector<pair<vector<int>*, int>>, cmp> minp;
    vector<int> ans;

    for(int i=0; i<n; i++){
        pair<vector<int>*, int> p;
        p.first = &mat[i];
        p.second = 0;
        minp.push(p);
    }

    while(!minp.empty()){
      pair<vector<int> *, int> top = minp.top();
      minp.pop();
      ans.push_back((*(top.first)).at(top.second));
      top.second++;
      if(top.second < n){
          minp.push(top);
      }
    }

    return ans;
}