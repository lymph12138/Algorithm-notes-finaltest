/*
542
*/

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m=mat.size(); int n=mat[0].size();
        vector<vector<int>> dp(m,vector<int>(n,m+n));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==0)    dp[i][j]=0;
                else{
                    if(i>0) dp[i][j]=min(dp[i][j],dp[i-1][j]+1);
                    if(j>0) dp[i][j]=min(dp[i][j],dp[i][j-1]+1);
                }
            }
        }
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if(mat[i][j]==0)    dp[i][j]=0;
                else{
                    if(i!=m-1) dp[i][j]=min(dp[i][j],dp[i+1][j]+1);
                    if(j!=n-1) dp[i][j]=min(dp[i][j],dp[i][j+1]+1);
                }
            }
        }
        return dp;
    }
};
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m=mat.size(); int n=mat[0].size();
        queue<vector<int>> q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==1)    mat[i][j]=INT_MAX;
                else    q.push({i,j});
            }
        }
        vector<vector<int>> move={{0,1},{0,-1},{1,0},{-1,0}};
        while(!q.empty()){
            auto p=q.front();
            q.pop();
            for(int i=0;i<move.size();i++){
                int x=p[0]+move[i][0],y=p[1]+move[i][1];
                if(x>=0 && x<m && y>=0 && y<n && mat[x][y]==INT_MAX){
                    mat[x][y]=mat[p[0]][p[1]]+1;
                    q.push({x,y});
                }
            }
        }
        return mat;
    }
};

