/*
1494
*/
class Solution {
public:
    int solve(int mask, int k, vector<int>& rela, vector<int>& dp){
        int n=rela.size(),fullmask=(1<<n)-1;
        if(mask==fullmask)  return 0;
        if(dp[mask])    return dp[mask];
        dp[mask]=n;
        int cando=0;
        for(int remaining=fullmask^mask; remaining; remaining&=(remaining-1)){
            int last=__builtin_ctz(remaining);
            if((rela[last]&mask)==rela[last])
                cando |= (1<<last);
        }
        int maxchoose=min(k,__builtin_popcount(cando));
        for(int subset=cando;subset;subset=cando&(subset-1)){
            if(__builtin_popcount(subset)==maxchoose)
                dp[mask]=min(dp[mask],1+solve(mask|subset, k, rela, dp));
        }
        return dp[mask];
    }
    int minNumberOfSemesters(int n, vector<vector<int>>& relations, int k) {
        vector<int> rela(n,0),dp(1<<n,0);
        for(auto r:relations)
            rela[r[1]-1] |= (1<<(r[0]-1));
        return solve(0,k,rela,dp);
    }
};

