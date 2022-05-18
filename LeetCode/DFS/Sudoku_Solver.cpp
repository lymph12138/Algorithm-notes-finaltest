/*
37
*/
class Solution{
    private:
    bool line[9][9];
    bool column[9][9];
    bool block[3][3][9];
    bool valid;
    vector<pair<int,int>> spaces;
    public:
    void DFS(vector<vector<char>>& sudo, int pos){
        if(pos==spaces.size()){
            valid=true;
            return;
        }
        auto [i,j]=spaces[pos];
        for(int idx=0;idx<9 && !valid;idx++){
            if(!line[i][idx] && !column[j][idx] && !block[i/3][j/3][idx]){
                line[i][idx]=column[j][idx]=block[i/3][j/3][idx]=true;
                sudo[i][j]=idx+'0'+1;
                DFS(sudo,pos+1);
                line[i][idx]=column[j][idx]=block[i/3][j/3][idx]=false;
            }
        }
    }
    void solveSudoku(vector<vector<char>>& sudo){
        memset(line,false,sizeof(line));
        memset(column,false,sizeof(column));
        memset(block,false,sizeof(block));
        valid=false;
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(sudo[i][j]!='.'){
                    line[i][sudo[i][j]-'0'-1]=true;
                    column[j][sudo[i][j]-'0'-1]=true;
                    block[i/3][j/3][sudo[i][j]-'0'-1]=true;
                }
                else    spaces.emplace_back(i,j);
            }
        }
        DFS(sudo,0);
    }
};
