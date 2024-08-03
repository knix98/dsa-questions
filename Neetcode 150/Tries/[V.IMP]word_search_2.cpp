/*
https://leetcode.com/problems/word-search-ii/description/
*/


class TrieNode{
   public:
      vector<TrieNode*> children = vector<TrieNode*>(26, NULL);
      bool isTerminal = false;
      int count = 0;

      ~TrieNode() {
         for(TrieNode* c : children) delete c;
      }
};

class Solution {
private:
   TrieNode* root;
   vector<vector<char>> board;
   vector<vector<bool>> vis;
   vector<string> ans;
   vector<vector<int>> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

   bool check(int &x, int &y) {
      return (x >= 0 && x < board.size() && y >= 0 && y < board[0].size());
   }

   void insertInTrie(string &word) {
      TrieNode *temp = root;
      for(char c : word) {
         if(!temp->children[c - 'a']) {
            temp->children[c - 'a'] = new TrieNode();
         }
         temp = temp->children[c - 'a'];
         temp->count++;
      }
      temp->isTerminal = true;
   }

   pair<int, TrieNode*> helper(int x, int y, TrieNode* node, string &curr) {
      curr.push_back(board[x][y]);
      vis[x][y] = true;
      int wordsFound = 0;

      if(node->isTerminal) {
         ans.push_back(curr);
         node->isTerminal = false;
         wordsFound++;
      }

      int nx, ny;
      for(int i=0; i<4; i++) {
         nx = x + dirs[i][0];
         ny = y + dirs[i][1];

         if(check(nx, ny) && !vis[nx][ny] && node->children[board[nx][ny] - 'a']) {
            pair<int, TrieNode*> smallAns = helper(nx, ny, node->children[board[nx][ny] - 'a'], curr);
            wordsFound += smallAns.first;
            node->children[board[nx][ny] - 'a'] = smallAns.second;
         }
      }

      node->count -= wordsFound;
      if(node->count == 0) {
         delete node;
         node = NULL;
      }
      vis[x][y] = false;
      curr.pop_back();

      return {wordsFound, node};
   }

public:
   vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
      root = new TrieNode();
      this->board = board;
      vis = vector<vector<bool>>(board.size(), vector<bool>(board[0].size(), false));
      ans.clear();

      for(string s : words) insertInTrie(s);

      char c;
      string curr = "";
      for(int i=0; i<board.size(); i++) {
         for(int j=0; j<board[0].size(); j++) {
            c = board[i][j];
            if(root->children[c - 'a']) {
               pair<int, TrieNode*> smallAns = helper(i, j, root->children[c - 'a'], curr);
               root->children[c - 'a'] = smallAns.second;
            }
         }
      }

      delete root;
      return ans;
   }
};