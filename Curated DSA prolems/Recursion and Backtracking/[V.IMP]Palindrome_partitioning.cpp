/*
https://classroom.codingninjas.com/app/classroom/me/11692/content/204224/offering/2650148/problem/14051?leftPanelTabValue=PROBLEM

You are given a string S. The task is to divide S into palindromic substrings. You need to return all possible ways to do that.

Note:

A substring is a contiguous segment of a string.
For Example :
For a given string “AABB”
4 possible palindrome partitioning of the given string are:
["A", "A", "B", "B"]
["A", "A", "BB"]
["AA", "B", "B"]
["AA", "BB"]
Detailed explanation ( Input/output format, Notes, Images )
Constraints :
0 <= |S|<= 15
where |S| denotes the length of string S.

Time Limit: 1 sec
Sample Input 1 :
zYY
Sample Output 1 :
["z", "Y", "Y"]
["z", "YY"]
Explanation for input 1 :
For the given string "zYY" there are two partitions in which all substring of partition is a palindrome.
Sample Input 2 :
AbbA
Sample Output 2 :
[“A”, “b”, “b”, “A”]
[“A”, “bb”, “A”]
[“AbbA”]
Explanation for input 2 :
For the given string "AbbA", there are 3 partitions that can be made in which every substring is palindromic substrings.
*/



#include<bits/stdc++.h>
using namespace std;

void helper(string &s, int i, vector<vector<bool>> &isPalindrome, vector<vector<string>> &ans, vector<string> &t){
    int n = s.size();
    if(i == n){
        ans.push_back(t);
        return;
    }

    string curr = "";
    for(int j=i; j<n; j++){  // starting from current s[i] and will keep on adding s[i] to it uptill i==n-1
        curr += s[j];
        if(isPalindrome[i][j]){  // whichever substring is palindrome , add it and call recursion
            t.push_back(curr);
            helper(s, j+1, isPalindrome, ans, t);
            t.pop_back();
        }
    }
}

vector<vector<string>> partition(string s) 
{
    int n = s.size();

    // preprocessing the whole string and marking all the palindromes in the whole string
    vector<vector<bool>> isPalindrome(n, vector<bool>(n, false));
    for(int i=n-1; i>=0; i--){
        for(int j=i; j<n; j++){
            if(s[i] == s[j]){
                if((j-i <= 2) || isPalindrome[i+1][j-1]) isPalindrome[i][j] = true;
            }
        }
    }

    vector<vector<string>> ans; 
    vector<string> t;
    helper(s, 0, isPalindrome, ans, t);
    return ans;
}