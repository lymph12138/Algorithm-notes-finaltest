/*
1074
*/
class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int n=matrix.size(),m=matrix[0].size();
        for(int i=0;i<n;i++)
            for(int j=1;j<m;j++)
                matrix[i][j]+=matrix[i][j-1];
        unordered_map<int,int> mp;
        int ans=0;
        for(int i=0;i<m;i++){
            for(int k=i;k<m;k++){
                mp={{0,1}};
                int cur=0;
                for(int j=0;j<n;j++){
                    cur+=matrix[j][k]-(i>0?matrix[j][i-1]:0);
                    ans+=mp.find(cur-target)!=mp.end()?mp[cur-target]:0;
                    mp[cur]++;
                }
            }
        }
        return ans;
    }
};