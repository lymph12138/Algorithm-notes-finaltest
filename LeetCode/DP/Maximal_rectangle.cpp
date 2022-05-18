/*
85
class Solution {
public:
    int GetAns(vector<int> height){
        int ans=0;int n=height.size();
        for(int i=0;i<n;i++){
            int mins=300;
            for(int j=i;j<n;j++){
                mins=min(mins,height[j]);
                if(i==j)    ans=max(ans,height[j]);
                else    ans=max(ans,(j-i+1)*mins);
            }
        }
        return ans;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m=matrix.size(); int n=matrix[0].size();
        int ans=0;
        vector<int> height(n,0);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]=='0')   height[j]=0;
                else    height[j]++;
            }
            ans=max(ans,GetAns(height));
        }
        return ans;
    }
};
*/

