/*
316
*/
class Solution {
public:
    bool isValid(vector<int> alpha, char c){
        for(int i=0;i<c-'a';i++)
            if(alpha[i]>0)
                return false;
        return true;
    }
    string removeDuplicateLetters(string s) {
        vector<int> alpha(26,0),visited(26,0);
        for(int i=0;i<s.size();i++)
            alpha[s[i]-'a']++;
        string ans="";
        for(int i=0;i<s.size();i++){
            alpha[s[i]-'a']--;
            if(visited[s[i]-'a'])   continue;
            while(!ans.empty() && s[i]<ans.back() && alpha[ans.back()-'a']){
                visited[ans.back()-'a']=0;
                ans.pop_back();
            }
            ans=ans+s[i];
            visited[s[i]-'a']=1;
        }
        return ans;
    }
};  