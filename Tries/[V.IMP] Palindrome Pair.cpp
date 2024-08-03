/*
Given 'n' number of words, you need to find if there exist any two words which can be joined to make a palindrome or any word, which itself is a palindrome.
The function should return either true or false. You don't have to print anything.

Constraints:
0 <= n <= 10^5
Time Limit: 1 sec

Sample Input 1 :
4
abc def ghi cba
Sample Output 1 :
true
Explanation of Sample Input 1:
"abc" and "cba" forms a palindrome

Sample Input 2 :
2
abc def
Sample Output 2 :
false
Explanation of Sample Input 2:
Neither their exists a pair which forms a palindrome, nor any of the words is a palindrome in itself. Hence, the output is 'false.'
*/

// APROACH 1 : using maps
bool isPalindrome(string word)
{
    if (word.size() == 0)
        return true;

    for (int i = 0, j = word.size() - 1; i < j; i++, j--)
    {
        if (word[i] != word[j])
            return false;
    }

    return true;
}

bool isPalindromePair(vector<string> words)
{
    unordered_map<string, int> um; // will store the reverse of each of the words
    for (int i = 0; i < words.size(); i++)
    {
        string word = words[i];
        reverse(word.begin(), word.end());
        um[word]++;
    }

    um[""]++; // will also store an empty string/word

    for (int i = 0; i < words.size(); i++)
    {
        string word = words[i];

        // case 1: if the palindrome is a substr present at the end of the word
        // if the whole word turns out to be palindrome, then the code wud check for "" (empty string) inside map
        // that's why we inserted "" inside map, so that if the word itself is a palindrome then we return true
        for (int j = word.size(); j >= 0; j--)
        {
            if (isPalindrome(word.substr(j)))
            {
                // if a substr at the end of word is a palindrome, then check if the remaining word is present in the map or not
                if (um.count(word.substr(0, j)) > 0)
                    return true;
            }
            else
            {
                // else if this substr at the end of word is not a palindrome, then continue the loop till the whole word is checked
                continue;
            }
        }

        // case 2: if the palindrome is a substr present at the start of the word
        // in this loop, we will not check for the "" and "whole_word" cases, since they are already checked in the above case 1
        for (int j = 1; j < word.size(); j++)
        {
            if (isPalindrome(word.substr(0, j)))
            {
                if (um.count(word.substr(j)) > 0)
                    return true;
            }
            else
            {
                continue;
            }
        }
    }

    return false;
}

// APPROACH 2 : using tries

#include <bits/stdc++.h>
using namespace std;

// class TrieNode
// {
// public:
//     char data;
//     TrieNode **children;
//     bool isTerminal;
//     int childCount;

//     TrieNode(char data)
//     {
//         this->data = data;
//         children = new TrieNode *[26];
//         for (int i = 0; i < 26; i++)
//         {
//             children[i] = NULL;
//         }
//         isTerminal = false;
//         childCount = 0;
//     }
// };

// class Trie
// {
//     TrieNode *root;

// public:
//     int count;

//     Trie()
//     {
//         this->count = 0;
//         root = new TrieNode('\0');
//     }

//     bool add(TrieNode *root, string word)
//     {
//         // Base case
//         if (word.size() == 0)
//         {
//             if (!root->isTerminal)
//             {
//                 root->isTerminal = true;
//                 return true;
//             }
//             else
//             {
//                 return false;
//             }
//         }

//         // Small calculation
//         int index = word[0] - 'a';
//         TrieNode *child;
//         if (root->children[index] != NULL)
//         {
//             child = root->children[index];
//         }
//         else
//         {
//             child = new TrieNode(word[0]);
//             root->children[index] = child;
//             root->childCount++;
//         }

//         // Recursive call
//         return add(child, word.substr(1));
//     }

//     void add(string word)
//     {
//         if (add(root, word))
//         {
//             this->count++;
//         }
//     }

/*..................... Palindrome Pair................... */
bool isPalindrome(string word)
{ // checks whether the given word is a palindrome or not
    for (int i = 0, j = word.length() - 1; i < j; i++, j--)
    {
        if (word[i] != word[j])
        {
            return false;
        }
    }
    return true;
}

// this function would take a root of trie, and check if any 1 word present in this trie is a Palindrome or not
// this funcn wud also recieve a string at the beginning which it will use to build and check all of the
// words present in this trie using recursion
bool stringMaker(TrieNode *root, string str)
{
    str += root->data; // first insert root->data in the str

    if (root->isTerminal)
    { // if root is terminal node, this means a word is formed, so check this word for Palindrome
        if (isPalindrome(str))
        { // if this word was a palindrome, return true
            return true;
        }
    }

    for (int i = 0; i < 26; i++)
    { // move forward in the trie
        if (root->children[i] != NULL)
        {
            if (stringMaker(root->children[i], str))
            {
                return true;
            }
        }
    }

    // if we reach here means no word in this trie was palindrome in combination with the str passed as argument
    return false;
}

// this helper wud recieve a trie root and check whether the 'rev' forms palindrome pair with any of the words in this trie or not
// this function wud start checking for the 'rev' with words starting from one of the children nodes of root
bool helper(TrieNode *root, string rev)
{
    // 1st base case : if we reach the end of 1 word in the trie
    if (root->isTerminal == true)
    {
        if (rev.length() == 0)
        {
            return true;
        }
        if (isPalindrome(rev))
        {
            return true;
        }
    }
    // 2nd base case : if we reach the end of the rev itself
    else if (rev.length() == 0)
    {
        // then we will check whether any of the words present ahead of this root is a palindrome or not
        for (int i = 0; i < 26; i++)
        {
            if (root->children[i] != NULL)
            {
                if (stringMaker(root->children[i], ""))
                {
                    return true;
                }
            }
        }

        return false;
    }

    // not any base case...
    int index = rev[0] - 'a';
    if (root->children[index] == NULL)
    {
        return false;
    }
    else
    {
        return helper(root->children[index], rev.substr(1));
    }
}

bool isPalindromePair(vector<string> words)
{
    // Write your code here
    for (int i = 0; i < words.size(); i++)
    {
        add(words[i]);
    }
    for (int i = 0; i < words.size(); i++)
    {
        reverse(words[i].begin(), words[i].end());

        // helper wud check if words beginning from 1 of the children node(of root), forms a palindrome pair with words[i] or not
        if (helper(root, words[i]))
        {
            return true;
        }
    }

    return false;
}
