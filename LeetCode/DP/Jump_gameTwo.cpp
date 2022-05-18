/*
45
O(n^2)
class Solution {
public:
    int jump(vector<int>& N) {
        vector<int> dp(N.size(),10010);
        dp[0]=0;
        for(int i=1;i<N.size();i++)
            for(int j=0;j<i;j++)
                if(j+N[j]>=i)
                    dp[i]=min(dp[i],dp[j]+1);
        return dp[N.size()-1];
    }
};
O(n)
class Solution {
public:
    int jump(vector<int>& N) {
        int steps=0,cur=-1,next=0;
        for(int i=0;next<N.size()-1;i++){
            if(i>cur){
                steps++;
                cur=next;
            }
            next=max(next,N[i]+i);
        }
        return steps;
    }
};

*/

