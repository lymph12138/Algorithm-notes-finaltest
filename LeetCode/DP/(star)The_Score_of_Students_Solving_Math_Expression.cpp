/*
2019
*/
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <string>
using namespace std;

class Solution {
public:
    int maxans=1024;
    unordered_map<string,vector<int>> dp;
    int solve(string s){
        if(s.size()==1)    return s[0]-'0';
        int res=s[0]-'0',pre=res;
        int tag=0;
        while(tag<s.size()-1){
            int num=s[tag+2]-'0';
            if(s[tag+1]=='+'){
                res=res+num;
                pre=num;
            }
            else{
                res=res-pre+pre*num;
                pre=pre*num;
            }
            tag+=2;
        }
        return res;        
    }
    vector<int> dfs(string s){
        if(dp.count(s))    return dp[s];
        if(s.size()==1) dp[s].push_back(s[0]-'0');
        for(int k=1;k<s.size();k+=2){
            vector<int> left,right;
            left=dfs(s.substr(0,k));
            right=dfs(s.substr(k+1));
            vector<bool> vis(maxans,false);
            for(auto c1:left){
                for(auto c2:right){
                    if(s[k]=='+' && c1+c2<maxans && !vis[c1+c2]){
                        dp[s].push_back(c1+c2);
                        vis[c1+c2]=true;
                    }
                    else if(s[k]=='*' && c1*c2<maxans && !vis[c1*c2]){
                        dp[s].push_back(c1*c2);
                        vis[c1*c2]=true;
                    }
                }
            }
        }
        return dp[s];
    }
    int scoreOfStudents(string s, vector<int>& answers) {
        int n=s.size();
        int res=solve(s);
        dfs(s);
        int score=0;
        vector<bool> vis(maxans,false);
        for(auto c:dp[s])   vis[c]=true;
        for(auto a:answers){
            if(a==res)  score+=5;
            else if(vis[a])    score+=2;
        }
        return score;
    }
};

int main(){
    string s="4+4*2+6+4*4+4*6+4*6+2*6+4";
    vector<int> answers={22};
    cout<<Solution().scoreOfStudents(s,answers);

    return 0;
}

