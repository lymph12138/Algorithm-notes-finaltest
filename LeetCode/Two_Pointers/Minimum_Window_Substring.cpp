/*
76
*/
#include <cstdio>
#include <vector>
#include <iostream>
#include <string>
#include <cstring>
#include <unordered_set>
#include <unordered_map>
using namespace std;


class Solution {
public:
    string minWindow(string s, string t) {
        int n=s.size(),count=0,left=0,right=0;
        unordered_map<char,int> mp;
        unordered_set<char> st;
        for(auto c:t){
            mp[c]++;
            st.insert(c);
        }
        while(right<n){
            if(st.count(s[right])){
                if(mp[s[right]]>0)    count++;
                mp[s[right]]--;
            }
            if(count==t.size())  break;
            right++;
        }
        int res=right-left+1;
        string ans="";
        if(res>n && count<t.size())    return ans;
        ans=s.substr(left,res);
        while(right<n){
            while(left<=right){
                bool tag=false;
                if(st.count(s[left])){
                    if(mp[s[left]]==0)  tag=true;
                    //mp[s[left]]++;
                }  
                if(tag) break;
                if(mp[s[left]]<0)   mp[s[left]]++;
                if(mp[s[left]]>0)   mp[s[left]]--;
                left++;
            }
            if(res>=right-left+1){
                res=right-left+1;
                ans=s.substr(left,res);
            }
            right++;
            while(right<n && s[right]!=s[left]){
                if(st.count(s[right]))  mp[s[right]]--;
                right++;
            }
            
            if(right<n){
                mp[s[right]]--;
                mp[s[left]]++;
                left++;
            }
        }
        return ans;
    }
};

int main(){
    string s="cabefgecdaecf",t="cae";
    cout<<Solution().minWindow(s,t);

    return 0;
}