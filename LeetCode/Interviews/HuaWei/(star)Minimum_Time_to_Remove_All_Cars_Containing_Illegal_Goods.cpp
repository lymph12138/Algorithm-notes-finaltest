/*
2167
*/
class Solution {
public:
    int minimumTime(string s) {
        int preimin=INT_MAX,countone=0,ans=INT_MAX;
        for(int j=0;j<s.size();j++){
            preimin=min(preimin,j-2*countone);
            if(s[j]=='1')   countone++;
            if(s.size()==1) return countone;
            ans=min(2*countone-j+preimin,ans);
        }
        return min(ans+s.size()-1,s.size());
    }
};