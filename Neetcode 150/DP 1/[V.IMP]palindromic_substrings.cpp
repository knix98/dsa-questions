/*
Question 1 : https://leetcode.com/problems/longest-palindromic-substring/description/
*/

/*
    Given a string s, return the longest palindromic substring in s
    Ex. s = "babad" -> "bab", s = "cbbd" -> "bb"

    Expand around center, extend as far as possible, store max length

    Time: O(n^2)
    Space: O(1)
*/

class Solution {
public:
    string longestPalindrome(string s) {
        int maxStart = 0;
        int maxLength = 1;
        
        for (int i = 0; i < s.size() - 1; i++) {
            middleOut(s, i, i, maxStart, maxLength);
            middleOut(s, i, i + 1, maxStart, maxLength);
        }
        
        return s.substr(maxStart, maxLength);
    }
private:
    void middleOut(string s, int i, int j, int& maxStart, int& maxLength) {
        while (i >= 0 && j <= s.size() - 1 && s[i] == s[j]) {
            i--;
            j++;
        }
        if (j - i - 1 > maxLength) {
            maxStart = i + 1;
            maxLength = j - i - 1;
        }
    }
};




/*
Question 2 : https://leetcode.com/problems/palindromic-substrings/description/
*/
/*
    Given a string, return # of palindromic substrings in it
    Ex. s = "babad" -> "bab", s = "cbbd" -> "bb"

    2 pointers, middle out, check both odd & even sized strings

    Time: O(n^2)
    Space: O(1)
*/

class Solution {
public:
    int countSubstrings(string s) {
        int result = 0;
        
        for (int i = 0; i < s.size(); i++) {
            middleOut(s, i, i, result);
            middleOut(s, i, i + 1, result);
        }
        
        return result;
    }
private:
    void middleOut(string s, int i, int j, int& result) {
        while (i >= 0 && j < s.size() && s[i] == s[j]) {
            result++;
            i--;
            j++;
        }
    }
};