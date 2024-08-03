/*
Given n number of words and an incomplete word w. You need to auto-complete that word w.
That means, find and print all the possible words which can be formed using the incomplete word w.
Note : Order of words does not matter.

Sample Input 1 :
7
do dont no not note notes den
no
Sample Output 2 :
no
not
note
notes

Sample Input 2 :
7
do dont no not note notes den
de
Sample Output 2 :
den

Sample Input 3 :
7
do dont no not note notes den
nom
Sample Output 3 :
(Empty) There is no word which starts with "nom"
*/

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

class TrieNode
{
public:
    char data;
    TrieNode **children;
    bool isTerminal;

    TrieNode(char data)
    {
        this->data = data;
        children = new TrieNode *[26];
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie
{
    TrieNode *root;

public:
    int count;

    Trie()
    {
        this->count = 0;
        root = new TrieNode('\0');
    }

    bool insertWord(TrieNode *root, string word)
    {
        // Base case
        if (word.size() == 0)
        {
            if (!root->isTerminal)
            {
                root->isTerminal = true;
                return true;
            }
            else
            {
                return false;
            }
        }

        // Small calculation
        int index = word[0] - 'a';
        TrieNode *child;

        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        // Recursive call
        return insertWord(child, word.substr(1));
    }

    void insertWord(string word)
    {
        if (insertWord(root, word))
        {
            this->count++;
        }
    }

    // SOLUTION CODE BEGINS HERE .............................................................................................................

    void print(TrieNode *root, string word, string prt)
    {
        if (word.size() == 0)
        {
            if (root->isTerminal == true)
            {
                cout << prt << endl;
            }

            for (int i = 0; i < 26; i++)
            {
                if (root->children[i] != NULL)
                {
                    print(root->children[i], word, prt + root->children[i]->data);
                }
            }

            return;
        }

        int index = word[0] - 'a';
        if (root->children[index] == NULL)
            return;

        prt += root->children[index]->data;
        print(root->children[index], word.substr(1), prt);
    }

    void autoComplete(vector<string> input, string pattern)
    {
        // Write your code here
        for (int i = 0; i < input.size(); i++)
        {
            // inserting only those words in the trie, which start with pattern[0]
            if (input[i][0] == pattern[0])
                insertWord(input[i]);
        }

        print(root, pattern, "");
    }
};