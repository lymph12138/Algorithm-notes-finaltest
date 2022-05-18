/*
1254
*/
class Solution {
public:
    void dfs(int i,int j,vector<vector<bool>>& vis,vector<vector<int>>& grid){
        int n=vis.size(),m=vis[0].size();
        if(i<0 || i>=n || j<0 || j>=m )  return ;
        if(grid[i][j]==1 || grid[i][j]==2 || vis[i][j])  return ;
        if(grid[i][j]!=1)   grid[i][j]=2;
        vis[i][j]=true;
        dfs(i-1,j,vis,grid);
        dfs(i+1,j,vis,grid);
        dfs(i,j-1,vis,grid);
        dfs(i,j+1,vis,grid);
        vis[i][j]=false;
    }
    int closedIsland(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        for(int i=0;i<n;i++){
            dfs(i,0,vis,grid);
            dfs(i,m-1,vis,grid);
        }
        for(int j=0;j<m;j++){
            dfs(0,j,vis,grid);
            dfs(n-1,j,vis,grid);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0){
                    dfs(i,j,vis,grid);
                    ans++;
                }
            }
        }
        /*
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2)
                    grid[i][j]=0;
            }
        }
        */
        return ans;
    }
};