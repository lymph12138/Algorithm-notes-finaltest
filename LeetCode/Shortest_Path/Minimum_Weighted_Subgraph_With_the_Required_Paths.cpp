/*
2203
*/
class Solution {
public:
    void bfs(int node,vector<vector<pair<int,int>>>& l,vector<long long>& path){
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> pq;
        pq.push({0,node});
        while(pq.size()){
            auto [dist,i]=pq.top();pq.pop();
            if(dist!=path[i])   continue;
            for(auto [j,w]:l[i]){
                if(path[j]>dist+w){
                    path[j]=dist+w;
                    pq.push({path[j],j});
                }
            }
        }
    }
    long long minimumWeight(int n, vector<vector<int>>& edges, int src1, int src2, int dest) {
        long long maxval=1e10,res=LLONG_MAX;
        vector<vector<pair<int, int>>> list(n),rlist(n);
        vector<long long> dd(n,maxval),ds1(n,maxval),ds2(n,maxval);
        dd[dest]=ds1[src1]=ds2[src2]=0;
        for(auto e:edges){
            list[e[0]].push_back({e[1],e[2]});
            rlist[e[1]].push_back({e[0],e[2]});
        }
        bfs(dest,rlist,dd);
        bfs(src1,list,ds1);
        bfs(src2,list,ds2);
        if(dd[src1]==maxval || dd[src2]==maxval)
            return -1;
        for(int i=0;i<n;i++)
            res=min(res,dd[i]+ds1[i]+ds2[i]);
        return res;
    }
};