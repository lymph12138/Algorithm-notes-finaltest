/*
1289
*/
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        if(m==1)    return grid[0][0];
        int first=-1,second=-1;
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                if(first==-1)   first=j;
                else if(grid[i-1][j]<=grid[i-1][first]){
                    second=first;
                    first=j;
                }
                else if(second==-1 || grid[i-1][j]<grid[i-1][second])
                    second=j;
            }
            for(int j=0;j<m;j++){
                if(first!=j)    grid[i][j]=grid[i][j]+grid[i-1][first];
                else grid[i][j]=grid[i][j]+grid[i-1][second];
            }
        }
        int ans=grid[n-1][0];
        for(int j=1;j<m;j++)    ans=min(ans,grid[n-1][j]);
        return ans;
    }
};