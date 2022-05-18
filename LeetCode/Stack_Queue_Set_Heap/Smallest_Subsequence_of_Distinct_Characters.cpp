/*
1081
*/
class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> cnt(26,0),vis(26,0);
        int n=s.size();
        for(auto c:s)   cnt[c-'a']++;
        string ans="";
        for(auto c:s){
            cnt[c-'a']--;
            if(vis[c-'a']>0)    continue;
            while(ans.size() && ans.back()>c && cnt[ans.back()-'a']>0){
                vis[ans.back()-'a']=0;
                ans.pop_back();
            }
            ans.push_back(c);
            vis[c-'a']++;
        }
        return ans;
    }
};