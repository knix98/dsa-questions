/*
https://classroom.codingninjas.com/app/classroom/me/22205/content/575420/offering/8882873/problem/9437
*/



// intuition and approach written in CN CP hand notes of tries chapter
#include<bits/stdc++.h>
using namespace std;

#define ll long long

class TrieNode{
    public:
    TrieNode* next[2];
    int count;  // keeping count of number of nums having this prefix (or passing through this node)

    TrieNode(){
        next[0] = NULL;
        next[1] = NULL;
        count = 0;
    }
};

void insertInTrie(TrieNode* node, int n){
    int bitPos = 1;
    bitPos = bitPos<<30;

    for(int i=0; i<=30; i++){
        if(n&bitPos){
            if(node->next[1] == NULL) node->next[1] = new TrieNode();
            node = node->next[1];
        }
        else {
            if(node->next[0] == NULL) node->next[0] = new TrieNode();
            node = node->next[0];
        }

        node->count++;
        bitPos = bitPos>>1;
    }
}

ll subArrays(TrieNode* node, int &n, int &k, int bitIndex) {
    if(bitIndex < 0) return 0;

    ll ans = 0;
    int bitPos = 1<<bitIndex;

    if(k&bitPos){  // k has 1
        if(n&bitPos){  // n has 1
            if(node->next[0] != NULL){  // xor has 1
                // since at this bitindex k and our xor both has 1, so still no decision, so move forward
                ans += subArrays(node->next[0], n, k, bitIndex-1); // move forward
            } 
            if(node->next[1] != NULL) { // xor has 0
                // since at this bitindex k has 1 but our xor has 0, so we have made xor lesser than k, so add the count of all numbers passing through this node in the final count and dont move forward anymore
                ans += node->next[1]->count;
            }
        }
        else{   // n has 0
            if(node->next[0] != NULL){  // xor has 0
                ans += node->next[0]->count; 
            } 
            if(node->next[1] != NULL) { // xor has 1
                ans += subArrays(node->next[1], n, k, bitIndex-1); // move forward
            }
        }
    }
    else{   // k has 0
        if(n&bitPos){  // n has 1
            if(node->next[0] != NULL){  // xor has 1
                // since at this bitindex k has 0 but our xor has 1, so we have made xor greater than k, so dont count any numbers on this path 
                ans += 0;
            } 
            if(node->next[1] != NULL) { // xor has 0
                ans += subArrays(node->next[1], n, k, bitIndex-1); // move forward
            }
        }
        else{   // n has 0
            if(node->next[0] != NULL){  // xor has 0
                ans += subArrays(node->next[0], n, k, bitIndex-1); // move forward
            } 
            if(node->next[1] != NULL) { // xor has 1
                ans += 0;
            }
        }
    }

    return ans;
}

int main(){
    TrieNode* root = new TrieNode();
    int n, k;
    cin >> n >> k;

    int prefixXOR = 0;
    insertInTrie(root, prefixXOR);  // inserting 0 in trie initially , 0 signifies prefixXOR at index -1 , so that we can get xor values of nums from i=0 to 5 suppose

    int num;
    ll ans = 0;
    for(int i=0; i<n; i++){
        cin >> num;
        prefixXOR ^= num;
        ans += subArrays(root, prefixXOR, k, 30);
        insertInTrie(root, prefixXOR);
    }

    cout << ans << endl;
    
    return 0;
}