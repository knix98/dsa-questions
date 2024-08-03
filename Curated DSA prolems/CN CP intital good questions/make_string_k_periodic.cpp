/*
https://classroom.codingninjas.com/app/classroom/me/22205/content/575394/offering/8882381/problem/13531

You are given a string ‘S’ of length ‘N’, an array A of length ‘M’ ( consisting of lowercase letters). and a positive integer ‘K’. You can take a character from 'A' and change any character in 'S' with this character. The task is to minimize the number of swaps required ( between ‘S’ and ‘A’ ) to make the string ‘S’ ‘k’-periodic.

Note:

1. A string ‘S’ is said to be ‘K’ periodic, if for each position  ‘i’ in the string S[i] = S[i+K].

   Consider string ‘S’,
   if S = ”abcabc”, it is 3 periodic string.
   if S= ”aaaaa”,  it is 1 periodic string.

2. In one move, only one character of ‘S’ can be swapped with a character of ‘A’.

3. The characters in ‘A’ can be used more than once.

4. All characters of K-periodic string ‘S’ are elements of array ‘A’.
Detailed explanation ( Input/output format, Notes, Images )
Constraints:
1 <= T <= 5
1 <= N, M <= 2 * 10 ^ 4
1 <=  K < = N

Time limit: 1 sec.
Sample Input 1:
2
7 3 3
abcbbde
a b c
5 2 2
ninja
n i
Sample Output 1:
3
2
Explanation:
In first test case, We need at least 3 swaps to make the string “abcbbde” 3 periodic. One swap between characters at index 3 in string and letter ‘a’ from the array. Second swap between character at index 6 in string and letter ‘a’ from array Third swap between character at index 5 in string and letter ‘c’ from the array.
Sample Input 2:
1
3 1 1
aaa
a
Sample Output 2:
0
Explanation:
In total 0 swaps are required to make string ‘1’-periodic.
*/



#include<bits/stdc++.h>

// APPROACH : if k is 3 suppose then start with 1
// for each 1st postions, check which valid char is occuring the most in these 1st positions. 
// then when we know the freq of char which is occuring the most in these 1st postions, we just have to change
// all chars present in 1st postions to that char , so total number of swaps for 1st postions = (no. of 1st positions) - (freq of most occuring char)
// similarly do for the 2nd and the 3rd postions and add them up

int minSwap (int n, int m, int k, string &s, vector<char> &arr)
{
    unordered_map<char, int> chars; // map for containing all the valid chars()
    for(int i=0; i<m; i++){
        chars[arr[i]]++;
    }

    int ans = 0;

    for(int i=0; i<k; i++){  // loop for each postions
        int j=i;
        int maxFreq = 0; // freq of maximum occuring char in kth postions
        int freq[26] = {0};
        int occurences = 0; // count of total kth postions

        while(j < n){
            occurences++;

            if(chars.count(s[j]) > 0){ // checking whether the current char at kth position is a valid char
                freq[s[j] - 'a']++;
                maxFreq = maxFreq > freq[s[j] - 'a'] ? maxFreq : freq[s[j] - 'a'];
            }

            j += k;
        }

        ans += (occurences - maxFreq);
    }

    return ans;
}