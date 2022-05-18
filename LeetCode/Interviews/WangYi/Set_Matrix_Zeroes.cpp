/*
73
*/
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<vector<int>> zeros;
        int m=matrix.size();int n=matrix[0].size();
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                if(matrix[i][j]==0)
                    zeros.push_back({i,j});
        for(int i=0;i<zeros.size();i++){
            int row=zeros[i][0];
            for(int j=0;j<n;j++)
                matrix[row][j]=0;
            int column=zeros[i][1];
            for(int j=0;j<m;j++)
                matrix[j][column]=0;
        }
    }
};