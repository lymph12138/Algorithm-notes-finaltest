/*
980
*/
class Solution {
public:
    vector<string> ans;
    string tempans="";
    int sum=1,x,y;
    vector<vector<int>> dirs={{1,0},{-1,0},{0,1},{0,-1}};
    void dfs(int i,int j,vector<vector<int>>& grid,string tempans){
        if(grid[i][j]==2){
            if(tempans.size()==sum*2)
                ans.push_back(tempans);
            return ;
        }
        grid[i][j]=-2;
        for(int t=0;t<4;t++){
            int x=i+dirs[t][0];
            int y=j+dirs[t][1];
            if(x>=0 && x<grid.size() && y>=0 && y<grid[0].size()){
                if(grid[x][y]==0 || grid[x][y]==2){
                    char c1=x+'a',c2=y+'a';
                    dfs(x,y,grid,tempans+c1+c2);
                }
            }
        }
        grid[i][j]=0;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==0)
                    sum++;
                if(grid[i][j]==1){
                    x=i;
                    y=j;
                }
            }
        }
        dfs(x,y,grid,tempans);
        grid[x][y]=1;
        
        return ans.size();
    }
};