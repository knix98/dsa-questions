/*
https://leetcode.com/problems/design-add-and-search-words-data-structure/description/
*/

/*
Time : thinking of worst case would be when we are given a word to search = "..."
so at each char we would have to search all the 26 children of each node so 26*26*26 = 26^3
and for worst case we can also consider that this dfs paths would happen for all the words present in the trie
so Time = O(m x 26^n) -> m = # of words, n = length of words

Space = O(mn) , in worst case all the words would be stored separately in the trie with no matching char
*/
class TrieNode{
   public:
      vector<TrieNode*> children = vector<TrieNode*>(26, NULL);
      bool isTerminal = false;
};

class WordDictionary {
private:
   TrieNode *root;

    // this func would be given a TrieNode* and the index wi of the char in &word that we need to search for in the children of the TrieNode*
   bool search(TrieNode *node, string &word, int wi) {
      if(wi == word.size()) {
         return node->isTerminal;
      }

      if(word[wi] == '.') {
         for(int i=0; i<26; i++) {
            if(node->children[i] && search(node->children[i], word, wi+1)) return true;
         }
      }
      else {
         if(node->children[word[wi] - 'a']) return search(node->children[word[wi] - 'a'], word, wi+1); 
      }

      return false;
   }

public:
   WordDictionary() {
      root = new TrieNode();
   }
   
   void addWord(string word) {
      TrieNode *temp = root;
      for(char c : word) {
         if(!temp->children[c - 'a']) {
            temp->children[c - 'a'] = new TrieNode();
         }
         temp = temp->children[c - 'a'];
      }

      temp->isTerminal = true;
   }
   
   bool search(string word) {
      return search(root, word, 0);
   }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */