/*
212
*/
#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <string>
using namespace std;

class Trie{
public:
    string word;
    Trie* next[26];
    void insert(string word){
        Trie* node=this;
        for(auto c:word){
            if(!node->next[c-'a'])
                node->next[c-'a']=new Trie();
            node=node->next[c-'a'];
        }
        node->word=word;
    }
};
class Solution {
public:
    vector<vector<int>> dirs={{1,0},{-1,0},{0,1},{0,-1}};
    bool dfs(int i,int j,Trie* root,vector<string>& ans,vector<vector<char>>& board){
        char c=board[i][j];
        if(!root->next[c-'a'])  return false;
        root=root->next[c-'a'];
        if(root->word.size()){
            ans.push_back(root->word);
            root->word="";
        }
        board[i][j]='*';
        for(int t=0;t<4;t++){
            int x=i+dirs[t][0];
            int y=j+dirs[t][1];
            if(x>=0 && x<board.size() && y>=0 && y<board[0].size() && board[x][y]!='*')
                dfs(x,y,root,ans,board);
        }
        board[i][j]=c;
        
        return true;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie* root=new Trie();
        vector<string> ans;
        for(auto word:words)    root->insert(word);
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                dfs(i,j,root,ans,board);
            }
        }
        
        return ans;
    }
};


int main(){
    vector<vector<char>> board={{'a','a'}};
    vector<string> words={"aa"};
    Solution().findWords(board,words);
}

class Solution {
    struct TrieNode {
        TrieNode *children[26];
        string word;
    };

public:
    /** Inserts a word into the trie. */
    TrieNode *buildTrie(vector<string> &words) {
        TrieNode *root = new TrieNode();
        for (int j = 0; j < words.size(); j++) {
            string word = words[j];
            TrieNode *curr = root;
            for (int i = 0; i < word.length(); i++) {
                char c = word[i] - 'a';
                if (curr->children[c] == nullptr) {
                    curr->children[c] = new TrieNode();
                }
                curr = curr->children[c];
            }
            curr->word = word;
        }
        return root;
    }
    void dfs(vector<vector<char>> &board, int i, int j, TrieNode *p, vector<string> &result) {
        char c = board[i][j];
        if (c == '#' || !p->children[c - 'a']) return;
        p = p->children[c - 'a'];
        if (p->word.size() > 0) {
            result.push_back(p->word);
            p->word = "";
        }

        board[i][j] = '#';
        if (i > 0) dfs(board, i - 1, j, p, result);
        if (j > 0) dfs(board, i, j - 1, p, result);
        if (i < board.size() - 1) dfs(board, i + 1, j, p, result);
        if (j < board[0].size() - 1) dfs(board, i, j + 1, p, result);
        board[i][j] = c;
    }
    vector<string> findWords(vector<vector<char>> &board, vector<string> &words) {
        TrieNode *root = buildTrie(words);
        vector<string> result;
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                dfs(board, i, j, root, result);
            }
        }
        return result;
    }
};