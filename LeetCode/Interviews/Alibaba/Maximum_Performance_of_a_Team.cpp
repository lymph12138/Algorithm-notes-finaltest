/*
1383
*/
class Solution {
public:
    int mol=1e9+7;
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pair<int,int>> v;
        for(int i=0;i<n;i++)    v.push_back({efficiency[i],speed[i]});
        sort(v.begin(),v.end(),greater<pair<int,int>>());
        priority_queue<int, vector<int>, greater<int>> q;
        long long int sum=0, ans=0;
        for(auto [eff,spe]:v){
            q.push(spe);
            sum+=spe;
            if(q.size()>k){
                sum-=q.top();
                q.pop();
            }
            ans=max(anx,eff*sum);
        }
        return ans%mol;
    }
};