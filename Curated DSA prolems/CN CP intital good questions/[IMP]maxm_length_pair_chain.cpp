/*
https://classroom.codingninjas.com/app/classroom/me/22205/content/575391/offering/8882348/problem/9396

You are given ‘N’ pairs of integers in which the first number is always smaller than the second number i.e in pair (a,b) -> a < b always. Now we define a pair chain as the continuous arrangement of pairs in which a pair (c,d) can follow another pair (a,b) only when b < c.

Find the length of the longest pair chain that can be formed using the given pairs.

Example:
Given Pairs =  [3,4], [1,2], [2,3].

The length of the maximum chain will be 2. The longest chain is [1,2] -> [3,4].
Note:
1. You can select a pair only once.

2. You needn’t use up all the given pairs.

3. You can select pairs in any order. 
Detailed explanation ( Input/output format, Notes, Images )
Constraints:
1 <= T <= 100
1 <= N <= 10^4 
-10^9 <= a,b <= 10^9

Where ‘a’ and ‘b’ is the elements of the pair.

Time Limit: 1 sec
Sample Input 1:
2
3
5 8 
3 4
3 4
2
2 3
-1 2
Sample Output 1:
2
1
Explanation for Sample Output 1:
In test case 1, The max length pair chain will be [3,4], -> [5,8] as 4 < 5 that means we can join these two pairs and form a chain of length two.

In test case 2, To join two pairs (a,b), (c,d) we need b < c but this condition is not satisfied by the given pairs in the input hence the max length will be 1 and the max length pair chain will be [2,3] or [-1,2].
Sample Input 2:
2
1
10 20
4
4 6
2 3
9 12
15 20
Sample Output 2:
1
4
Explanation for Sample Output 2:
In test case 1, The max length pair chain will be [10,20] form a chain of length one.

In test case 2, The max length pair chain will be [2,3] -> [4,6] -> [9,12] -> [15,20], that means we can join these two pairs as it satisfies the condition and form a chain of length four.
*/



#include<bits/stdc++.h>

// METHOD : 1 => standard method for such problems in which you need to find the pairs forming longest chain
                       //   just sort on basis of 2nd number and start the chain from the first pair in the sorted array
                       //   and keep adding the pairs which are valid to be added in the continuing chain
                       //   in this method the longest chain always begins from the first pair in the sorted array

bool cmp(pair<int, int> &a, pair<int, int> &b) {
    return a.second < b.second; // sorting in ascending order according to second number
}

int maxLengthChain(vector<pair<int, int>> &p, int n) {
    sort(p.begin(), p.end(), cmp);

    int ans = 1;
    int chainEnd = p[0].second; // chain will always start from the first pair after sorting

    for(int i=1; i<n; i++){
        if(p[i].first > chainEnd){
            ans++;
            chainEnd = p[i].second;
        }
    }

    return ans;
}



// METHOD : 2 => sorting the pairs on the basis of first number
int maxLengthChain(vector<pair<int, int>> &p, int n) {
    if(n == 1) return 1;

    sort(p.begin(), p.end());
    
    stack<pair<int,int>> util; // this stack would contain all the pairs which will be part of the longest chain
    util.push(p[0]);

    for(int i=1; i<n; i++){
        if(util.empty() || p[i].first > util.top().second) {
            // means current pair can be joined in the current chain in the stack
            util.push(p[i]);
        } 
        else{
            // first check whether the top pair in stack is eloping the current pair or not ((a,b) is eloping (c,d) if a <= (c,d) <= b)
            while(!util.empty() && p[i].first >= util.top().first && p[i].second <= util.top().second){
                util.pop(); // then remove the eloping pair
                                // because the pair which is inside has better cance of forming a longer chain
                                // and anyways second number of inside pair would be lesser than second number of eloping pair
                                // so that way also => the pair which is inside has better chance of forming a longer chain
            }

            // now check whether the current pair can be joined in the stack chain or not
            // if stack is empty, then start a new chain with the current pair
            if(util.empty() || util.top().second < p[i].first) util.push(p[i]);
        }
    }

    return util.size();
}