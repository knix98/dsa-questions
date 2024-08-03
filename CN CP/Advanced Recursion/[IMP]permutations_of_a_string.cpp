/*
You are given a string 'STR' consisting of lowercase English letters. Your task is to return all permutations of the given string in lexicographically increasing order.
String A is lexicographically less than string B, if either A is a prefix of B (and A ≠ B), or there exists such i (1 <= i <= min(|A|, |B|)), that A[i] < B[i], and for any j (1 <= j < i) A[i] = B[i]. Here |A| denotes the length of the string A.
For example :
If the string is “bca”, then its permutations in lexicographically increasing order are { “abc”, “acb”, “bac”, “bca”, “cab”, “cba” }.
Note:
Given string contains unique characters.
Input Format :
The first line of input contains a single integer 'T', representing the number of test cases or queries to be run. Then the T test cases follow.

The first line and only line of each test case contains a string 'STR' consisting of lowercase English letters.
Output Format :
For every test case, the permutations of the given string are printed in lexicographically increasing order separated by space.

The output of each test case is printed in a separate line.
Note :
You do not need to print anything, it has already been taken care of. Just implement the given function.
Constraints :
1 <= T <= 5
1 <= |STR| <= 9

Where |STR| is the length of the string.

Time Limit: 1 sec
Sample Input 1:
3
abc
bc
c
Sample Output 1:
abc acb bac bca cab cba
bc cb
c
Explanation for Sample Input 1:
In the 1st test case, there are 6 permutations of the given string.
In the 2nd test case, there are 2 permutations of the given string.
In the 3rd test case, there is only 1 permutation of the given string.
Sample Input 2:
1
xyz
Sample Output 2:
xyz xzy yxz yzx zxy zyx 
*/



#include<algorithm>

// Explanation written in CN CP notes
// APPROACH : 1 => keep calcualting the next permutation in a loop until you have reached the last permutation
// Time : n * n! (since total n! permutations, and for each permut, we are doing O(n) operations)
// Space : O(1)
void swaps(string &str, int a, int b){
    if(a != b){
        str[a] ^= str[b] ^= str[a] ^= str[b];
    }
}

void reverses(string &str, int a, int b){
    while(a < b){
        swaps(str, a, b);
        a++;
        b--;
    }
}

vector<string> generatePermutations(string &str)
{
    int l = str.size();
    vector<string> ans;
    sort(str.begin(), str.end());  // the ascendingly sorted string is always the 1st permutation

    while(true){
        ans.push_back(str);

        int j = l-2;  
        while(j >= 0 && str[j] >= str[j+1]) j--;  // finding the alphabet which is not part of the increasing series starting from the end

        if(j < 0) break;  // if all elements are in decreasing order, then that means we have found the last permu, and already stored it also

        int k = j+2;
        int smallestGreaterCharIndex = j+1;   // finding the next greater alphabet (to the one found in the previous step) in the decreasing series 
        while(k < l){
            if(str[k] > str[j] && str[k] < str[smallestGreaterCharIndex]) smallestGreaterCharIndex = k;
            k++;
        }
        // NOTE : the above operation of finding the smallestGreaterCharIndex can also be done using a binary search custom function in logn time for optimisation

        swaps(str, j, smallestGreaterCharIndex);   // swapping 

        reverses(str, j+1, l-1);  // reversing the decreasing series to finally get the next permutation
    }

    return ans;
}




// APPROACH 2 : generating permutations on leaf node of recursive tree by swapping first element for each recursive step
// either with himself only or with the other forward elements
// Time : n*n! (reaching every permutation at recursive leaf takes n recursive steps)
// Space : O(n)
// draw recursive tree for "abc" using this algo and then you will understand better
void swaps(string &str, int a, int b){
    if(a != b){
        str[a] ^= str[b] ^= str[a] ^= str[b];
    }
}

void helper(string &str, int i, vector<string> &ans) {
    // base case
    if(i == str.size()-1){
        ans.push_back(str);
        return;
    }

    for(int j = i; j<str.size(); j++){
        swaps(str, i, j);
        helper(str, i+1, ans);
        swaps(str, i, j);
    }
}

vector<string> generatePermutations(string &str) {
    sort(str.begin(), str.end());
    vector<string> ans;
    helper(str, 0, ans);

    sort(ans.begin(), ans.end());
    return ans;
}
