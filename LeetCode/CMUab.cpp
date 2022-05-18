#include <vector>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;

class Solution{
public:
    void Change(string& s, int l, int r){
        if(l>r) return ;
        if(l==0 && r==s.size()-1)
            for(int i=0;i<r+1;i++)
                s[i]=i%2?'a':'b';
        else if(l==0)
            for(int i=r;i>=0;i--)
                s[i]=(s[r+1]=='b')?((r-i)%2?'b':'a'):((r-i)%2?'a':'b');
        else if(r==s.size()-1)
            for(int i=l;i<r+1;i++)
                s[i]=(s[l-1]=='b')?((i-l)%2?'b':'a'):((i-l)%2?'a':'b');
        else{
            for(int i=0;i<(r-l+1)/2;i++){
                s[l+i]=(s[l-1]=='b')?(i%2?'b':'a'):(i%2?'a':'b');
                s[r-i]=(s[r+1]=='b')?(i%2?'b':'a'):(i%2?'a':'b');
            }
        }
    }
    int MinSubstring(string& s){
        int n=s.size();
        if(n==1)    return 1;
        int l=0,r=0;
        for(int i=0;i<n;i++){
            if(s[i]!='?')   continue;
            l=i;
            while(s[i]=='?'){
                r=i;
                i++;
            }
            Change(s,l,r);
        }
        int ans=1;int temp=1;
        for(int i=1;i<n;i++){
            if(s[i]=='?'){
                int ans1=0;
                while(s[i-ans1-1]==s[i-1])
                    ans1++;
                int ans2=0;
                while(s[i+ans2+1]==s[i+1])
                    ans2++;
                ans=max(ans,min(ans1,ans2)+((s[i-1]==s[i+1])?0:1));
                ans=max(ans,temp);
                temp=1;
            }
            if(s[i]==s[i-1])
                temp++;
            else{
                ans=max(ans,temp);
                temp=1;
            }
        }
        return ans;
    }
};

int main(){
    string s="??a??aaabbbb??a???b??a?a";
    cout<<s<<endl;
    cout<<Solution().MinSubstring(s)<<endl;
    cout<<s;

    return 0;
}