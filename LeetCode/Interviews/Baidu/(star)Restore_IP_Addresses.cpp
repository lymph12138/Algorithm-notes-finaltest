/*
93
*/
class Solution {
public:
    vector<string> ans;
    void dfs(string s, int idx, string single, int dots, string total){
        if(dots>3)  return;
        else if(idx==s.size() && dots==3)   ans.push_back(total+'.'+single);
        else if(s.size()>idx){
            if(stoi(single+s[idx])<256 && (single.size()==0 || single[0]!='0'))
                dfs(s,idx+1,single+s[idx],dots,total);
            dfs(s,idx+1,string(1,s[idx]),dots+1,(total.size()==0)?single:total+'.'+single);
        }
    }
    vector<string> restoreIpAddresses(string s) {
        dfs(s,1,string(1,s[0]),0,"");
        return ans;
    }
};
