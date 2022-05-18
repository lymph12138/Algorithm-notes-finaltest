#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;


int main(){
    vector<int> s,t;
    int vis=1e4+5;
    vector<int> temp={-3,-2,-1,0,0,1,2,3};
    int d=1;
    int sz=temp.size();
    int left=0,right=0;
    while(true){
        while(left<sz && temp[left]==vis)   left++;
        if(left==sz)    break;
        s.push_back(temp[left]);
        temp[left]=vis;
        while(right<sz && (temp[right]==vis || temp[right]!=s.back()+d))
            right++;
        t.push_back(temp[right]);
        temp[right]=vis;
    }
    for(int i=0;i<s.size();i++)
        cout<<s[i];
    
    return 0;
}