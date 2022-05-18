/*
165
*/
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <iostream>
using namespace std;
class Solution {
public:
    vector<int> figure(string version){
        int tag=0;
        int ver=0;
        vector<int> ans;
        while(tag<version.size()){
            ver=0;
            while(tag<version.size()-1 && version[tag]=='0')    tag++;
            while(version[tag]!='.' && tag<version.size()){
                ver=ver*10+(version[tag]-'0');
                tag++;
            }
            tag++;
            ans.push_back(ver);
        }
        return ans;
    }
    int compareVersion(string version1, string version2) {
        vector<int> ver1,ver2;
        ver1=figure(version1);
        ver2=figure(version2);
        int m=ver1.size();
        int n=ver2.size();
        if(m<n){
            for(int i=0;i<n-m;i++)
                ver1.push_back(0);
        }
        else{
            for(int i=0;i<m-n;i++)
                ver2.push_back(0);
        }
        for(int i=0;i<ver1.size();i++){
            if(ver1[i]<ver2[i]) return -1;
            else if(ver2[i]<ver1[i])    return 1;
        }
        return 0;
    }
};

int main(){
    string s1="1.0.1";
    string s2="1";
    cout<<Solution().compareVersion(s1,s2);

    return 0;
}