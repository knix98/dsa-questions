/*
https://www.spoj.com/problems/ADAINDEX/


Ada the Ladybug has many things to do and almost no time. She wants to to save time while searching for something so she have decided to make a search engine.

She has many words in her TODO list. It costs her precious time to find out, whether a word is in it so she seeks your help. You will get list and some queries. You will be asked, to find out how many words in TODO list have a word as prefix.

Input
The first line contains N, Q: the number words in TODO list and number of queries.

N lines follow, with words (of TODO list) consisting of lowercase letters. The sum of their lengths won't be greater than 106

Q lines follow, with words (queries) consisting of lowercase letters. The sum of their lengths won't be greater than 106

Output
For each query print the number of words in TODO list which have actual word as prefix.

Example Input
12 6
bulldog
dog
dogged
doggedly
doggerel
dogma
dogmatic
dogmatism
dogs
catastroph
catastroph
doctor
cat
dog
dogg
do
doctrinography
dogge
Example Output
2
8
3
9
0
3
*/



// basically try to find the whole query string in the trie. If not found return 0. If found and you reach at the node which signifies
// the last alphabet in the search query string, then return this node->count
#include<bits/stdc++.h>
using namespace std;

class TrieNode{
    public:
    TrieNode* next[26];
    int count;  // this would contain the count of words passing through this node

    TrieNode(){
        for(int i=0; i<26; i++) next[i] = NULL;
        count = 0; 
    }
};

void insertInTrie(TrieNode *node, string s) {
    while(s.size() > 0){
        if(node->next[s[0] - 'a'] == NULL){
            node->next[s[0] - 'a'] = new TrieNode();
        }
        
        node->next[s[0] - 'a']->count++;
        node = node->next[s[0] - 'a'];
        s = s.substr(1);
    }
}

int findCount(TrieNode *node, string s) {
    while(s.size() > 0){
        if(node->next[s[0] - 'a'] == NULL){
            return 0;
        }
        node = node->next[s[0] - 'a'];
        s = s.substr(1);
    }

    return node->count;
}

int main() {
    int n, q;
	cin>>n>>q;

	TrieNode *root = new TrieNode();
	for(int i=0; i<n; i++) {
		string word;
		cin>>word;
		insertInTrie(root, word);
	}

	while(q--) {
		string s;
		cin>>s;
		cout << findCount(root, s) << "\n";
	}
	return 0;
}