/*
354
*/

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        vector<int> dp;
        sort(envelopes.begin(),envelopes.end(),[](vector<int>& a,vector<int>& b)
             {return a[0]==b[0]?a[1]>b[1]:a[0]<b[0];});
        dp.push_back(envelopes[0][1]);
        for(int i=1;i<envelopes.size();i++){
            int l=0,r=dp.size()-1,idx=-1;
            while(l<=r){
                int mid=l+(r-l)/2;
                if(dp[mid]>=envelopes[i][1]){
                    idx=mid;
                    r=mid-1;
                }
                else    l=mid+1;
            }
            if(idx==-1) dp.push_back(envelopes[i][1]);
            else    dp[idx]=envelopes[i][1];
        }
        return dp.size();
    }
};