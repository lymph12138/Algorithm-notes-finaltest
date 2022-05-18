/*
999
*/
class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int row,column;
        for(int i=0;i<8;i++){
            for(int j=0;j<8;j++){
                if(board[i][j]=='R'){
                    row=i;
                    column=j;
                    break;
                }
            }
        }
        int ans=0;
        for(int i=row;i<8;i++){
            if(board[i][column]=='p'){
                ans++;
                break;
            }
            if(board[i][column]=='B')   break;
        }
        for(int i=row;i>=0;i--){
            if(board[i][column]=='p'){
                ans++;
                break;
            }
            if(board[i][column]=='B')   break;
        }
        for(int j=column;j<8;j++){
            if(board[row][j]=='p'){
                ans++;
                break;
            }
            if(board[row][j]=='B')   break;
        }
        for(int j=column;j>=0;j--){
            if(board[row][j]=='p'){
                ans++;
                break;
            }
            if(board[row][j]=='B')   break;
        }
        return ans;
    }
};
