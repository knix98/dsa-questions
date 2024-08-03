/*
https://classroom.codingninjas.com/app/classroom/me/22205/content/575420/offering/8882873/problem/9924

or leetcode => https://leetcode.com/problems/word-ladder/description/
*/


// methods written in CN CP hand notes of trie chapter, here is the solution using trie method
#include<bits/stdc++.h>
using namespace std;

class TrieNode{
	public:
	TrieNode* next[26];
	int count; // count of words passing through this node
	                // not keeping isTerminal, since every word in this problem is of same length, so every word would end at leaf node only

	TrieNode(){
		for(int i=0; i<26; i++) next[i] = NULL;
		count = 0;
	}
};

void insertInTrie(TrieNode* node, string &s, int i){
	while(i<s.size()){
		if(node->next[s[i]-'a'] == NULL) node->next[s[i]-'a'] = new TrieNode();
		node = node->next[s[i]-'a'];
		node->count++;
		i++;
	}
}

void deleteFromTrie(TrieNode* node, string &s, int i) {
	while(i<s.size()){
		node->next[s[i]-'a']->count--;

		if(node->next[s[i]-'a']->count == 0) {
			node->next[s[i]-'a'] = NULL;
			return;
		}
		
		node = node->next[s[i]-'a'];
		i++;
	}
}

// func would take current node, root node, pair of the word which we initially started with, int i = index over this original word, bool = have we found 1 different albhabet yet,
// sring ans = storing all the alphabets that we have passed through in the current dfs path, pending queue for bfs
void findOneDifferenceWords(TrieNode* root, TrieNode* node, pair<string, int> &p, int i, bool oneDifferenceFound, string &ans, queue<pair<string,int>> &pending){
	string original = p.first;
	
	if(i == original.size()){  // if we reach a leaf node, that means this is a valid word so push in queue and remove from trie
		pending.push({ans, p.second+1});
		deleteFromTrie(root, ans, 0);
		return;
	}
	
	for(int j=0; j<26; j++){  // do dfs over all possible children of this current node
		if(node->next[j] != NULL){
			bool popAns = false; // wil tell me after if else block that I need to pop the last alphabet from ans string or not
			int charInOriginal = original[i] - 'a';
			
            if(charInOriginal == j) {  // means no change alphabet, so move forward
				ans += (char)(j + (int)('a'));
				popAns = true;
				findOneDifferenceWords(root, node->next[j], p, i+1, oneDifferenceFound, ans, pending);
			}
			else{ // means here is a change in current alphabet
				if(oneDifferenceFound == false){ // only if 1 change has not been encountered till now, then we will move forward
                                                 // because otherwise if 1 change has already been found earlier, and 1 more change found at current then dont take this path ahead
					ans += (char)(j + (int)('a'));
					popAns = true;
					findOneDifferenceWords(root, node->next[j], p, i+1, true, ans, pending);
				}
			}

			if(popAns) ans.pop_back();  // if we had gone ahead in dfs , then remove the residual alphabet at the end
		}
	}
}

int wordLadder(string begin, string end, vector<string> &dict) 
{
	TrieNode* root = new TrieNode();
	for(string s : dict) if(s != begin) insertInTrie(root, s, 0);  // I dont want to push begin in trie, since begin I am going to insert in pending queue first-hand
																						// and which ever words are present in pending queue -> means they have been visited in the bfs traversal of the dict words
																						// so these words should be removed from the trie, as soon as they are pushed

	int ans = 0;
	queue<pair<string, int>> pending;  // each node would be pair of {word, level of bfs}
	pending.push({begin, 1});

	while(!pending.empty()){
		pair<string, int> front = pending.front();
		pending.pop();

		if(front.first == end) return front.second;  // means during bfs we found, the end word, so just return the level at which this end is found

		string temp = "";
		findOneDifferenceWords(root, root, front, 0, false, temp, pending);
	}

	return -1;
}