/*
131
*/
class Solution {
public:
    vector<vector<string>> ans;
    bool Palidrome(string s){
        int n=s.size();
        if(n==1 || n==0)    return true;
        for(int i=0;i<n/2;i++)
            if(s[i]!=s[n-i-1])
                return false;
        return true;
    }
    
    void DFS(string s, int tag, vector<string> res){
        if(tag==s.size()){
            ans.push_back(res);
            return ;
        }
        for(int i=tag;i<s.size();i++){
            string temp=s.substr(tag,i-tag+1);
            if(Palidrome(temp)){
                res.push_back(temp);
                DFS(s,tag+1,res);
                res.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string> res;
        DFS(s,0,res);
        return ans;
    }
};