/*
https://classroom.codingninjas.com/app/classroom/me/22205/content/575420/offering/8882873/problem/9455
*/



#include<bits/stdc++.h>
using namespace std;

class TrieNode{
    public:
    TrieNode* next[26];
    bool isTerminal;

    TrieNode(){
        for(int i=0; i<26; i++) next[i] = NULL;
        isTerminal = false;
    }
};

void insertInTrie(TrieNode* node, string &s, int i){
    while(i < s.size()){
        if(node->next[s[i]-'a'] == NULL) node->next[s[i]-'a'] = new TrieNode();

        node = node->next[s[i]-'a'];
        i++;
    }

    node->isTerminal = true;
}

void findWords(TrieNode* node, string &sug, vector<string> &ans){
    if(node->isTerminal) ans.push_back(sug);

    for(int i=0; i<26; i++){
        if (node->next[i] != NULL) {
            sug += (char)(i + (int)'a');
            findWords(node->next[i], sug, ans);
            sug.pop_back();
        }
    }
}

void searchInTrie(TrieNode* node, string &s, int i, vector<string> &ans){
    string sug = ""; // suggestions
    
    while(i < s.size()){
        if(node->next[s[i]-'a'] == NULL) {
            // means this word is not present as prefix in trie
            insertInTrie(node, s, i);
            ans.push_back("No suggestions");
            return;
        }

        sug += s[i];
        node = node->next[s[i]-'a'];
        i++;
    }

    findWords(node, sug, ans);
}

int main(){
    TrieNode* root = new TrieNode();

    int n, q;
    string s;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s;
        insertInTrie(root, s, 0);
    }

    cin >> q;
    vector<string> ans;
    for(int i=0; i<q; i++) {
        cin >> s;
        searchInTrie(root, s, 0, ans);
    }

    for(string i : ans) cout << i << endl;

    return 0;
}