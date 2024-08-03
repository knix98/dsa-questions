/*
https://classroom.codingninjas.com/app/classroom/me/22205/content/575420/offering/8882873/problem/9428
*/


// in this problem, we will need an efficient data struct for finding whether a given substring has already been encountered earlier.
// the best DS is unordered_set O(1), set would take O(logn) where n is number of strings.
// But in this question we were asked to do using trie O(L). So I did.
class TrieNode{
    public:
    TrieNode* next[26];
    bool isTerminal;

    TrieNode() {
        for(int i=0; i<26; i++) next[i] = NULL;
        isTerminal = false;
    }
};

// this func would insert the substring in index [i,j) and would return false if this string already found earlier, else return true
bool insertAndCheck(TrieNode* node, string &s, int i, int j){
    while(i<j){
        if(node->next[s[i] - 'a'] == NULL) {
            node->next[s[i] - 'a'] = new TrieNode();
        }

        node = node->next[s[i] - 'a'];

        i++;
    }

    if(node->isTerminal) return false;
    else {
        node->isTerminal = true;
        return true;
    }
}

int countDistinctSubstrings(string &s)
{
    int ans = 0;
    TrieNode* root = new TrieNode();

    for(int i=0; i<s.size(); i++){  // generating all possible substrings with length >=1
        for(int j=i+1; j<=s.size(); j++){
            if(insertAndCheck(root, s, i, j)) ans++;
        }
    }

    return ans + 1;  // counting one more for empty substring 
}