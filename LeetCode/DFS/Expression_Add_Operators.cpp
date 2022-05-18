/*
282
*/
class Solution {
public:
    vector<string> ans;
    string s;
    int target;
    void dfs(int idx,string temp,long res,long pre){
        if(idx==s.size()){
            if(res==target)
                ans.push_back(temp);
            return ;
        }
        string numstr;
        long num=0;
        for(int j=idx;j<s.size();j++){
            if(j>idx && s[idx]=='0')    break;
            numstr+=s[j];
            num=num*10+s[j]-'0';
            if(idx==0)    dfs(j+1,temp+numstr,num,num);
            else{
                dfs(j+1,temp+'+'+numstr,res+num,num);
                dfs(j+1,temp+'-'+numstr,res-num,-num);
                dfs(j+1,temp+'*'+numstr,res-pre+pre*num,pre*num);
            }
        }
    }
    vector<string> addOperators(string num, int target) {
        this->s=num;
        this->target=target;
        dfs(0,"",0,0);

        return ans;
    }
};