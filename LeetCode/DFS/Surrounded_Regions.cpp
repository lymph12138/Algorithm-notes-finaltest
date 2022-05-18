/*
130
class Solution {
public:
    void DFS(vector<vector<char>>& board,int i,int j, int m, int n){
        if(i<0 || j<0 || i>=m || j>=n)  return;
        if(board[i][j]=='O'){
            board[i][j]='V';
            DFS(board,i,j-1,m,n);
            DFS(board,i,j+1,m,n);
            DFS(board,i-1,j,m,n);
            DFS(board,i+1,j,m,n);
        }
    }
    void solve(vector<vector<char>>& board) {
        if(board.empty())   return;
        int m=board.size();
        int n=board[0].size();
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                if(board[i][j]=='O' && (i==0 || j==0 || i==m-1 || j==n-1))
                    DFS(board,i,j,m,n);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='O')
                    board[i][j]='X';
                if(board[i][j]=='V')
                    board[i][j]='O';
            }
        }
    }
};
*/