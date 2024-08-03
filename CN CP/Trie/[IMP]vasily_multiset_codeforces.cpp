/*
https://codeforces.com/problemset/problem/706/D/
*/

/*
10
+ 8
+ 9
+ 11
+ 6
+ 1
? 3
- 8
? 3
? 8
? 11

*/

#include<bits/stdc++.h>
using namespace std;

class TrieNode{
    public:
    TrieNode* next[2];
    int count;

    TrieNode(){
        next[0] = NULL;
        next[1] = NULL;
        count = 0;
    }

    ~TrieNode(){
        for(int i=0; i<2; i++) delete next[i];
    }
};

void insertInTrie(TrieNode* node, int n){
    int bitPos = 1;
    bitPos = bitPos<<30;

    for(int i=0; i<=30; i++){
        node->count++;

        if(n&bitPos){
            if(node->next[1] == NULL) node->next[1] = new TrieNode();
            node = node->next[1];
        }
        else {
            if(node->next[0] == NULL) node->next[0] = new TrieNode();
            node = node->next[0];
        }

        bitPos = bitPos>>1;
    }
}

void deleteFromTrie(TrieNode* node, int n){
    int bitPos = 1;
    bitPos = bitPos<<30;

    TrieNode* prevNode = NULL;
    int prevNodeNextIndex = -1;
    for(int i=0; i<=30; i++){
        node->count--;

        if(node->count == 0){
            delete node;
            prevNode->next[prevNodeNextIndex] = NULL;
            return;
        }

        prevNode = node;
        if(n&bitPos){
            node = node->next[1];
            prevNodeNextIndex = 1;
        }
        else {
            node = node->next[0];
            prevNodeNextIndex = 0;
        }

        bitPos = bitPos>>1;
    }
}

int maxXOR(TrieNode* node, int n) {
    int ans = 0;
    int bitPos = 1;
    bitPos = bitPos<<30;

    for(int i=0; i<=30; i++){
        if(n&bitPos){
            if (node->next[0] != NULL) {
              ans += bitPos;
              node = node->next[0];
            }
            else node = node->next[1];
        }
        else {
            if (node->next[1] != NULL) {
              ans += bitPos;
              node = node->next[1];
            }
            else node = node->next[0];
        }

        bitPos = bitPos>>1;
    }

    return ans;
}

int main() {
    TrieNode* root = new TrieNode();
    insertInTrie(root, 0);

    vector<int> ans;

    int q;
    cin >> q;

    char c;
    int n;
    while(q--){
        cin >> c >> n;

        if(c == '+') insertInTrie(root, n);
        else if(c == '-') deleteFromTrie(root, n);
        else {
            // cout << maxXOR(root, n) << endl;
            ans.push_back(maxXOR(root, n));
        }
    }

    for(int i : ans) cout << i << endl;
} 