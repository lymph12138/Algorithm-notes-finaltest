/*
727
*/
class Solution{
public:
    string minWindow(string s1,string s2){
        int n=s1.size(),m=s2.size();
        int minwindow=INT_MAX;
        int s1pos=0,s2pos=0;
        string ans="";
        while(s1pos<n){
            if(s1[s1pos]==s2[s2pos])    s2pos++;
            s1pos++;
            if(s2pos==m){
                int rights1=s1pos-1,rights2=s2pos-1;
                while(rights2>=0){
                    if(s1[rights1]==s2[rights2])    rights2--;
                    rights1--;
                }
                int length=s1pos-rights1-1;
                if(minwindow>length){
                    minwindow=length;
                    ans=s1.substr(rights1+1,length);
                }
                s2pos=0;
                s1pos=rights1+2;
            }
        }
        return ans;
    }
};