/*
329
*/
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool valid(int i, int j, vector<vector<int>>& matrix){
        int n=matrix.size();int m=matrix[0].size();
        if(i<0 || j<0 || i>n-1 || j>m-1)    return false;
        return true;
    }
    int DFS(int i, int j, vector<vector<int>>& matrix, vector<vector<int>>& dp){
        int n=matrix.size();int m=matrix[0].size();
        if(i<0 || j<0 || i>n-1 || j>m-1)    return 0;
        if(dp[i][j]!=-1)    return dp[i][j];
        int w=0,a=0,s=0,d=0;
        if(valid(i-1,j,matrix) && matrix[i-1][j]>matrix[i][j]) w=DFS(i-1,j,matrix,dp);
        if(valid(i+1,j,matrix) && matrix[i+1][j]>matrix[i][j]) s=DFS(i+1,j,matrix,dp);
        if(valid(i,j-1,matrix) && matrix[i][j-1]>matrix[i][j]) a=DFS(i,j-1,matrix,dp);
        if(valid(i,j+1,matrix) && matrix[i][j+1]>matrix[i][j]) d=DFS(i,j+1,matrix,dp);
        dp[i][j]=max({w,a,s,d})+1;
        return dp[i][j];
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n=matrix.size();int m=matrix[0].size();
        int temp,ans=0;
        vector<vector<int>> dp(n,vector<int>(m,-1));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                temp=DFS(i,j,matrix,dp);
                ans=max(ans,temp);
            }
        }
        return ans;
    }
};