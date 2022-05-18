/*
1982
*/
#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

class Solution {
public:
    const int vis=1e4+5;
    void split(vector<int> temp,vector<int>& s,vector<int>& t,int d){
        int sz=temp.size();
        int left=0,right=0;
        while(true){
            while(left<sz && temp[left]==vis)   left++;
            if(left==sz)    break;
            s.push_back(temp[left]);
            temp[left]=vis;
            while(right<sz && temp[right]!=s.back()+d)
                right++;
            t.push_back(temp[right]);
            temp[right]=vis;
        }
    }
    vector<int> dfs(int n,vector<int> temp){
        if(n==1){
            if(temp[0]==0)  return {temp[1]};
            if(temp[1]==0)  return {temp[0]};
            return {};
        }
        int d=abs(temp[1]-temp[0]);
        vector<int> s,t;
        split(temp,s,t,d);
        vector<int> ans;
        ans=dfs(n-1,s);
        if(ans.size()){
            ans.push_back(d);
            return ans;
        }
        ans=dfs(n-1,t);
        if(ans.size()){
            ans.push_back(-d);
            return ans;
        }
        return {};
    }
    vector<int> recoverArray(int n, vector<int>& sums) {
        sort(sums.begin(),sums.end());
        int sum=0;
        for(auto s:sums)    sum+=s;
        sum/=1<<(n-1);
        return dfs(n,sums);
    }
};

int main(){
    vector<int> s,t;
    vector<int> temp={-3,-2,-1,0,0,1,2,3};
    int d=1;
    Solution().split(temp,s,t,d);
    for(int i=0;i<s.size();i++)
        cout<<s[i];
    
    return 0;
}