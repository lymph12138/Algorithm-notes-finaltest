/*
784
*/
class Solution {
public:
    vector<string> ans;
    void dfs(int idx, string s){
        if(idx==s.size()){
            ans.push_back(s);
            return;
        }
        if(s[idx]>='0' && s[idx]<='9')
            dfs(idx+1,s);
        else{
            dfs(idx+1,s);
            if(s[idx]>='a'&&s[idx]<='z')
                s[idx]='A'+(s[idx]-'a');
            else    s[idx]='a'+(s[idx]-'A');
            dfs(idx+1,s);
        }
    }
    vector<string> letterCasePermutation(string s) {
        dfs(0,s);
        
        return ans;
    }
};