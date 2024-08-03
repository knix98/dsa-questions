#include <iostream>
#include <string>
using namespace std;

// class for 1 TrieNode in the Trie
class TrieNode
{
public:
    // data members
    char data;
    TrieNode **children;
    bool isTerminal;

    // constructor
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

// Trie class
class Trie
{
    TrieNode *root;

    // private helper function to insert any word
    void insertWord(TrieNode *root, string word)
    {
        // base case
        if (word.size() == 0)
        {
            root->isTerminal = true;
            return;
        }

        int index = word[0] - 'a';
        if (root->children[index] == NULL)
        {
            TrieNode *newChild = new TrieNode(word[0]);
            root->children[index] = newChild;
        }

        insertWord(root->children[index], word.substr(1));
    }

    // private helper function to search any word
    bool searchWord(TrieNode *root, string word)
    {
        if (word.size() == 0)
        {
            return (root->isTerminal ? true : false);
        }

        int index = word[0] - 'a';
        if (root->children[index] == NULL)
            return false;
        else
            return searchWord(root->children[index], word.substr(1));
    }

    // private helper function to remove any word
    void removeWord(TrieNode *root, string word)
    {
        if (word.size() == 0)
        {
            root->isTerminal = false;
            return;
        }

        int index = word[0] - 'a';
        TrieNode *child = root->children[index];
        if (child == NULL)
            return; // means word not found so return...

        removeWord(child, word.substr(1));

        if (child->isTerminal)
            return;

        // if the child is not terminal, then check whether child is useless node?
        for (int i = 0; i < 26; i++)
        {
            if (child->children[i] != NULL)
                return; // child is not useless, so return
        }

        // means child->isTerminal == false && no children of child...so child is useless
        delete child;
        root->children[index] = NULL;
        return;
    }

    // public functions...
public:
    // constructor
    Trie()
    {
        root = new TrieNode('\0');
    }

    // public function to insert any word in the Trie
    void insertWord(string word)
    {
        if (word.size() == 0)
            return;

        insertWord(root, word); // calling a private helper function written above
    }

    // public function to search any word in the Trie
    bool searchWord(string word)
    {
        if (word.size() == 0)
            return false;

        return searchWord(root, word);
    };

    // public function to remove any word in the Trie
    void removeWord(string word)
    {
        if (word.size() == 0)
            return;

        removeWord(root, word);
    }
};

int main()
{
    Trie t;
    t.insertWord("abcd");
    t.insertWord("abc");
    t.insertWord("abcdef");
    t.insertWord("ab");
    t.insertWord("ass");
    t.insertWord("linking");
    t.insertWord("link");

    cout << t.searchWord("link") << endl; // true
    cout << t.searchWord("emin") << endl; // false

    cout << t.searchWord("ab") << endl;  // true
    cout << t.searchWord("abc") << endl; // true
    t.removeWord("abc");
    cout << t.searchWord("abc") << endl; // false
}