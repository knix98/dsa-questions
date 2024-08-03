/*
https://classroom.codingninjas.com/app/classroom/me/11692/content/204218/offering/2650138/problem/14344?leftPanelTabValue=PROBLEM

You are given a string ‘S’. You have to find the corresponding column number representing the string ‘S’.

The numbering for column numbers are as follows:

A -> 1
B -> 2
C -> 3
...
Z -> 26
AA -> 27
AB -> 28 
...
For Example:
Consider ‘S’ = “AD”. The column number represented by the string is 30. Hence, the answer is 30.
Detailed explanation ( Input/output format, Notes, Images )
Constraints:
1 <= |S| <= 10

The input contains only uppercase English Alphabet letters.

Time Limit: 1 sec
Sample Input 1:
 AZ
Sample Output 1:
 52
Explaination:
The given string ‘S’ is “AZ”, which represents column number 52. Hence, the answer is 52.
Sample Input 2:
ZZZ
Sample Output 2:
18278
*/



#define ll long long

long long columnNumber(string s)
{
    int n = s.size();
    if(n == 1) return s[0] - 'A' + 1;

    ll multiplier = 1;
    for(int i=1; i<n; i++) multiplier *= 26;

    ll ans = 0;
    for(int i=0; i<n; i++){
        int rank_of_curr_char = s[i] - 'A' + 1;
        ans += (rank_of_curr_char * multiplier);
        multiplier /= 26;
    }

    return ans;
}