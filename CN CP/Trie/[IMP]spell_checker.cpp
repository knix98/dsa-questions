/*
https://classroom.codingninjas.com/app/classroom/me/22205/content/575420/offering/8882873/problem/11016
*/



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
        if(node->next[s[i]-'a'] == NULL) break;

        sug += s[i];
        node = node->next[s[i]-'a'];
        i++;
    }

    if(i == s.size() && node->isTerminal) return;  // word found in dictionary, so return []

    findWords(node, sug, ans);
}

vector<string> spellChecker(vector<string> &dictionary, string &query){
    TrieNode* root = new TrieNode();
    for(string i : dictionary) insertInTrie(root, i, 0);

    vector<string> ans;
    searchInTrie(root, query, 0, ans);
    return ans;
}