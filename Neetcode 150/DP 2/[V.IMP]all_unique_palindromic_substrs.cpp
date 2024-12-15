/*
ns345 account
https://classroom.codingninjas.com/app/classroom/me/11692/content/204441/offering/2653312/problem/14280?leftPanelTabValue=PROBLEM

You are given a string ‘S’. Your task is to return all distinct palindromic substrings of the given string in alphabetical order.

A string is said to be palindrome if the reverse of the string is the same as the string itself.

For Example:
Consider ‘S’ = ‘abba’, all the possible substrings are [ ‘a’, ‘ab’, ‘abb’, 'abba', 'b', ‘ba’, 'bb', ‘bba’ ] out of which [ ‘a’, ‘abba’, 'b’, 'bb'] are palindromic substrings.
*/



// (Neetcode method) this method is best for finding or counting palindromic substrs in a string
// Time : O(n^2), space : O(1)
void isPalindrome(string &s, set<string> &st, int i, int j) {
    string check = "";
    while(i >= 0 && j < s.size() && s[i] == s[j]) {
        check += s[j];
        if(i != j) check = s[i] + check;
        st.insert(check);
        i--, j++;
    }
}

vector<string> distinctPalindrome(string &s)
{
    set<string> st;
    for(int i = 0; i<s.size(); i++) {
        isPalindrome(s, st, i, i);        
        isPalindrome(s, st, i, i+1);
    }

    vector<string> ans;
    for(string str : st) ans.push_back(str);
    return ans;
}



// another method by me using dp
/*
we just have to use the same dp way of finding palindromes
IMP thing is to take care of i and j index edge cases (out of bounds) errors while doing DP
Time and space = n^2 (space can be optimised to n)
*/
#include<bits/stdc++.h>
using namespace std;

vector<string> distinctPalindrome(string &s)
{
    int n = s.size();
    vector<string> ans;
    set<string> mp;
    vector<vector<bool>> isPalindrome(n, vector<bool>(n, true));

    string check = "";
    for(int i=n-1; i>=0; i--) {
        check = "";
        check += s[i];  // 1 length substr is always palindrome (this had to be done to prevent going out of bounds in DP formula)
        mp.insert(check);

		for(int j=i+1; j<n; j++) {
            check += s[j];
            
			if(s[i] == s[j] && isPalindrome[i+1][j-1]) {
                isPalindrome[i][j] = true;
                mp.insert(check);
            }
			else {
                isPalindrome[i][j] = false;
            }
		}
	}

    for(string st : mp) ans.push_back(st);
    return ans;
}