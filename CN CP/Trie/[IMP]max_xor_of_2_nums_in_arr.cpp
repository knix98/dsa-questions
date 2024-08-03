/*
Leetcode => https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/description/
*/


class Solution {
public:
    class TrieNode{
        public:
        TrieNode* next[2];

        TrieNode(){
            next[0] = NULL;
            next[1] = NULL;
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

    int findMaximumXOR(vector<int>& nums) {
        TrieNode* root = new TrieNode();

        int ans = 0;
        int smallAns;
        for(int i : nums) {
            insertInTrie(root, i);     // we need to first insert in trie, because initially when trie is empty, then first nums[i] wouldnt get anything
                                        // to compare with and will give some error of NULL node
            smallAns = maxXOR(root, i);
            if(smallAns > ans) ans = smallAns;
        }

        return ans;
    }
};