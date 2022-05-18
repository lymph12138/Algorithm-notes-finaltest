/*
1135
*/
#include <cstdio>
#include <algorithm>
#include <map>
#include <queue>
#include <vector>
#include <string>
#include <cstring>
#include <iostream>
using namespace std;
class Solution {
private:
    int find(int i, vector<int>& tag){
        if(i==tag[i])   return i;
        return find(tag[i],tag);
    }
    void combine(int i, int j, vector<int>& tag, vector<int>& sz){
        int x=find(i,tag);
        int y=find(j,tag);
        if(x==y)    return ;
        if(sz[x]<sz[y]){
            tag[x]=y;
            sz[y]+=sz[x];
        }
        else{
            tag[y]=x;
            sz[x]+=sz[y];
        }
    }
    void Kruskal(vector<vector<int>>& connections, vector<int>& tag, vector<int>& sz, int n, int& sum){
        int start,end,weight,num=0,elem;
        for(int i=0;i<connections.size();i++){
            start=connections[i][0];
            end=connections[i][1];
            weight=connections[i][2];
            if(find(start,tag)!=find(end,tag)){
                num++;
                sum+=weight;
                elem=tag[start];
                combine(start,end,tag,sz);
            }
            if(num==n-1)    break;
        }
        if(num!=n-1)    sum=-1;
    }
public:
    int minimumCost(int n, vector<vector<int>>& connections) {
        vector<int> tag(n+1,0),sz(n+1,1);
        for(int i=0;i<=n;i++)   tag[i]=i;
        sort(connections.begin(),connections.end(),[](vector<int> a, vector<int>b){
            if(a[2]==b[2] && a[0]==b[0])    return a[1]<b[1];
            else if(a[2]==b[2]) return a[0]<b[0];
            else    return a[2]<b[2];
        });
        int sum=0;
        Kruskal(connections,tag,sz,n,sum);
        return sum;
    }
};

int main(){
    int n=7;
    vector<vector<int>> edge={{2,1,87129},{3,1,14707},{4,2,34505},{5,1,71766},{6,5,2615},{7,2,37352}};
    cout<<Solution().minimumCost(n,edge);

    return 0;
}