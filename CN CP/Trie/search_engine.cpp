/*
https://classroom.codingninjas.com/app/classroom/me/22205/content/575420/offering/8882857/problem/2041
*/


class TrieNode{
    public:
    TrieNode* next[26];
    int maxWeight;  // this would contain the max weight of word which has this prefix

    TrieNode(){
        for(int i=0; i<26; i++) next[i] = NULL;
        maxWeight = 0;
    }
};

void insertInTrie(TrieNode *node, string s, int weight) {
    while(s.size() > 0){
        if(node->next[s[0] - 'a'] == NULL){
            node->next[s[0] - 'a'] = new TrieNode();
        }
        if(weight > node->next[s[0] - 'a']->maxWeight) node->next[s[0] - 'a']->maxWeight = weight;

        node = node->next[s[0] - 'a'];
        s = s.substr(1);
    }
}

int findMaxWeight(TrieNode *node, string s) {
    while(s.size() > 0){
        if(node->next[s[0] - 'a'] == NULL){
            return -1;
        }
        node = node->next[s[0] - 'a'];
        s = s.substr(1);
    }

    return node->maxWeight;
}

vector<int> searchEngine(vector<pair<string, int> > database, vector<string> text)
{
    TrieNode* root = new TrieNode();
    for(int i=0; i<database.size(); i++){
        string s = database[i].first;
        int weight = database[i].second;

        insertInTrie(root, s, weight);
    }

    vector<int> ans;
    for(int i=0; i<text.size(); i++){
        ans.push_back(findMaxWeight(root, text[i]));
    }

    return ans;
}