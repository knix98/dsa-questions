/*
https://classroom.codingninjas.com/app/classroom/me/22205/content/575420/offering/8882865/problem/9063
*/



// latest clean and short code written by me...for approach you can look at second code
struct TrieNode{
    TrieNode* next[2];

    TrieNode(){
        next[0] = next[1] = NULL;
    }
};

void insert(TrieNode *node, int n){
    for(int i=30; i>=0; i--){
        int bit = (n & (1<<i)) > 0 ? 1 : 0;
        if(!node->next[bit]){
            node->next[bit] = new TrieNode();
        }
        node = node->next[bit];
    }
}

int maxXorValue(TrieNode *node, int n) {
    int ans = 0;
    for(int i=30; i>=0; i--){
        int nBit = (n & (1<<i)) > 0 ? 1 : 0;
        if(node->next[!nBit]) {
            ans += (1<<i);
            node = node->next[!nBit];
        }
        else{
            node = node->next[nBit];
        }
    }

    return ans;
}

int maxXOR(int n, int m, vector<int> &arr1, vector<int> &arr2) 
{
    TrieNode* root = new TrieNode();
    for(int i : arr1) insert(root, i);

    int maxAns = 0;
    for(int i : arr2) {
        int smallAns = maxXorValue(root, i);
        if(smallAns > maxAns) maxAns = smallAns;
    }

    return maxAns;
}




// basically approach would be => while doing xor of any number with any other number, we should try to make 1 at every bit position,
// as we are doing xor starting from the MSB.
#define ll long long

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
    bitPos = bitPos<<30;  // we will be treating each number as a 31 bit representation with bits at positions, i = 0 to 30

    for(int i=0; i<=30; i++){
        if(n&bitPos){ 
            if(node->next[1] == NULL) node->next[1] = new TrieNode();
            node = node->next[1];
        }
        else {
            if(node->next[0] == NULL) node->next[0] = new TrieNode();
            node = node->next[0];
        }

        bitPos = bitPos>>1;  // we started from MSB and moving left bit by bit
    }
}

// this func, would try to calculate max xor value possible when we try to xor any number present in the trie and n.
int maxXOR(TrieNode* node, int n) {
    int ans = 0;
    int bitPos = 1;
    bitPos = bitPos<<30;

    for(int i=0; i<=30; i++){
        if(n&bitPos){  // n has 1 at current bit position
            if (node->next[0] != NULL) {  // so if 0 is present at this bit position of some number, then we will take that, because then only xor ans would contain 1 at this position
              ans += bitPos;  // if we are able to form 1 at this bit position, so we can add decimal representation of this in ans
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

// first store all nums in arr1 in the trie, and then 1 by 1 we will take nums from arr2 and try to calculate max xor possible with this num from arr2
int maxXOR(int n, int m, vector<int> &arr1, vector<int> &arr2) 
{
    TrieNode* root = new TrieNode();

    for(int i : arr1) insertInTrie(root, i);

    int ans = 0;
    int smallAns;
    for(int i : arr2) {
        smallAns = maxXOR(root, i);
        if(smallAns > ans) ans = smallAns;
    }

    return ans;
} 