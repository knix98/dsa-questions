/*
https://classroom.codingninjas.com/app/classroom/me/11692/content/204218/offering/2650138/problem/13795?leftPanelTabValue=PROBLEM

All you have to do is to find the longest substring having no repeated characters.

String ‘B’ is a substring of string ‘A’ if it can be obtained from ‘A’ by deletion of several (possibly, zero or all) characters from the beginning and several (possibly, zero or all) characters from the end.

For Example :
If the given input string is "aabc", then you should return "abc" as the longest substring without repeating characters.
Note :
If there are multiple substrings with the same length, then you should print the substring which comes earlier in the given string. 
Detailed explanation ( Input/output format, Notes, Images )
Constraints :
1 <= T <= 10
1 <= N <= 10^5

Time Limit: 1 sec
Sample Input 1 :
2
6
ababab
8
aabcabab
Sample Output 1 :
ab
abc
a
Explanation for Sample Input 1 :
In the 1st test case, “ab” is the longest substring having no repeated characters.

In the 2nd test case, “abc” and “bca” are the longest substrings but “cab” comes earlier in the given string.
Sample Input 2 :
1
10
aababacdeb
Sample Output 2 :
bacde
*/

string longestUniqueSubstring(string &s, int n){
    int fq[26] = {0};
    fq[s[0] - 'a']++;  // considering first chr before hand only

    int i = 0, j = 1;  // will start the right end of window from second char
    int ans_i = 0, ans_j = 0;
    while(j < n){
        fq[s[j] - 'a']++;  // current j is fresh char
            
        while(fq[s[j] - 'a'] > 1) {  // if after adding the current char, this was a second same char in the window then
            // remove chars from left end untill window again becomes uniq substr
            fq[s[i] - 'a']--;
            i++;
        }

        if(j-i+1 > ans_j-ans_i+1) ans_i = i, ans_j = j;  // checking size of window

        j++;  // move to next char
    }

    return s.substr(ans_i, ans_j-ans_i+1);
}