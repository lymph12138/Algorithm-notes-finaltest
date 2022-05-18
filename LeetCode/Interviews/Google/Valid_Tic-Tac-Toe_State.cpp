/*
794
*/
class Solution {
public:
    bool validTicTacToe(vector<string>& board) {
        int player1=0,player2=0;
        bool flag1=false,flag2=false;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(board[i][j]=='O')    player2++;
                else if(board[i][j]=='X')   player1++;
            }
        }
        for(int i=0;i<3;i++){
            if(board[i][0]=='O' && board[i][1]=='O' && board[i][2]=='O')
                flag2=true;
            if(board[i][0]=='X' && board[i][1]=='X' && board[i][2]=='X')
                flag1=true;
        }
        for(int j=0;j<3;j++){
            if(board[0][j]=='O' && board[1][j]=='O' && board[2][j]=='O')
                flag2=true;
            if(board[0][j]=='X' && board[1][j]=='X' && board[2][j]=='X')
                flag1=true;
        }
        if(board[0][0]=='O' && board[1][1]=='O' && board[2][2]=='O')
            flag2=true;
        if(board[0][0]=='X' && board[1][1]=='X' && board[2][2]=='X')
            flag1=true;
        if(board[2][0]=='O' && board[1][1]=='O' && board[0][2]=='O')
            flag2=true;
        if(board[0][0]=='X' && board[1][1]=='X' && board[2][2]=='X')
            flag1=true;
        if(abs(player2-player1)>1) return false;
        if(player2>player1) return false;
        if(flag1 && flag2)  return false;
        if(flag1 && player1-player2!=1) return false;
        if(flag2 && player1!=player2)   return false;
        return true;
    }
};