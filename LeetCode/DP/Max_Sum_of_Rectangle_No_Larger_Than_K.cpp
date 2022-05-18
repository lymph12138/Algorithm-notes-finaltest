/*
363
*/

class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int n=matrix.size();int m=matrix[0].size();int ans=INT_MIN;
        for(int i=0;i<n;i++){
            vector<int> dp(m);
            for(int j=i;j<n;j++){
                for(int c=0;c<m;c++)
                    dp[c]+=matrix[j][c];
                set<int> lr;
                lr.insert(0);
                int s=0;
                for(int c=0;c<m;c++){
                    s+=dp[c];
                    auto lb=lr.lower_bound(s-k);
                    if(lb!=lr.end())    ans=max(ans,s-*lb);
                    lr.insert(s);
                    if(ans==k)  break;
                }
                if(ans==k)  break;
            }
            if(ans==k)  break;
        }
        return ans;
    }
};