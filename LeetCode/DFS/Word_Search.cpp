/*
79
*/
class Solution {
public:
    bool flag=false;
    void dfs(int i, int j, int idx, string& word, vector<vector<char>>& board,vector<vector<bool>>& vis){
        vis[i][j]=true;
        if(idx==word.size()){
            flag=true;
            return;
        }
        if(i && !vis[i-1][j] && board[i-1][j]==word[idx])
            dfs(i-1,j,idx+1,word,board,vis);
        if(j && !vis[i][j-1] && board[i][j-1]==word[idx])
            dfs(i,j-1,idx+1,word,board,vis);
        if(board.size()-i-1 && !vis[i+1][j] && board[i+1][j]==word[idx])
            dfs(i+1,j,idx+1,word,board,vis);
        if(board[0].size()-j-1 && !vis[i][j+1] && board[i][j+1]==word[idx])
            dfs(i,j+1,idx+1,word,board,vis);
        vis[i][j]=false;
        return ;
    }
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<bool>> vis(board.size(),vector<bool>(board[0].size(),false));
        if(board.size()*board[0].size()<word.size())    return false;
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]==word[0])    dfs(i,j,1,word,board,vis);
                if(flag)    return true;
            }
        }
        return false;
    }
};