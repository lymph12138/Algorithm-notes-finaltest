/*
140
*/
#include <cstring>
#include <string>
class Solution {
public:
    vector<string> ans;
    void DFS(string s, int tag, string temp, vector<string>& wordDict){
        int n=s.size();int m=wordDict.size();
        if(tag==n){
            temp.erase(0,1);
            ans.push_back(temp);
            return ;
        }
        for(int i=0;i<m;i++){
            int k=wordDict[i].size();
            if(k+tag>n) continue;
            if(s.substr(tag,k)==wordDict[i])
                DFS(s,tag+k,temp+" "+wordDict[i],wordDict);
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        string temp="";
        DFS(s,0,temp,wordDict);
        return ans;
    }
};