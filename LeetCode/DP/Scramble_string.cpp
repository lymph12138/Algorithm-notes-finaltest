/*
87
class Solution {
public:
    map<string,bool> mp;
    bool isScramble(string s1, string s2) {
        if(s1.size()!=s2.size())    return false;
        if(s1.size()==0 || s1==s2)    return true;
        int n=s1.size();
        string copys1=s1,copys2=s2;
        sort(copys1.begin(),copys1.end());
        sort(copys2.begin(),copys2.end());
        if(copys1!=copys2)  return false;
        string key=s1+" "+s2;
        if(mp.find(key)!=mp.end())
            return mp[key];
        bool flag=false;
        for(int i=1;i<n;i++){
            if(isScramble(s1.substr(0,i),s2.substr(0,i))&&isScramble(s1.substr(i,n-i),s2.substr(i,n-i))){
                flag=true;
                return true;
            }
            if(isScramble(s1.substr(0,i),s2.substr(n-i,i))&&isScramble(s1.substr(i,n-i),s2.substr(0,n-i))){
                flag=true;
                return true;
            }
            mp[key]=flag;
        }
        return false;
    }
};
*/