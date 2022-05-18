#include <iostream>
#include <set>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <string>
using namespace std;

class Solution{
    private:
    char ItoC(int n){
        return char(97+n);
    }
    int CtoI(char s){
        return s-'0'-49;
    }
    void Solve(string s1,string s2){
        int m=s1.size();
        int n=s2.size();
        int i=0;
        while(i<m&&i<n){
            if(s1[i]!=s2[i])
                break;
            i++;
        }
        G[CtoI(s1[i])][CtoI(s2[i])]=true;
    }
    int TopSort(){
        int temp=-1;
        bool tag=true;
        for(int i=0;i<26;i++){
            tag=true;
            for(int j=0;j<26;j++){
                if(G[j][i]==true && i!=j)   tag=false;
            }
            if(tag==true && G[i][i]==true){
                temp=i;
                break;
            }
        }
        if(temp!=-1)
            for(int i=0;i<26;i++)
                G[temp][i]=false;
        return temp;
    }
    public:
    int G[26][26]={false};
    string alienOrder(vector<string>& words){
        int n=words.size();
        set<int> s;
        for(int i=0;i<n;i++){
            for(int j=0;j<words[i].size();j++){
                G[CtoI(words[i][j])][CtoI(words[i][j])]=true;
                s.insert(CtoI(words[i][j]));
            }
        }
        for(int i=0;i<n;i++)
            for(int j=i+1;j<n;j++)
                Solve(words[i],words[j]);
        for(int i=0;i<26;i++)
            for(int j=i+1;j<26;j++)
                if(G[i][j]==true && G[j][i]==true)
                    return "";
        string ans="";
        while(!s.empty()){
            int temp=TopSort();
            if(temp!=-1){
                ans=ans+ItoC(temp);
                s.erase(temp);
                continue;
            }
            set<int>::iterator it;
            for(it=s.begin();it!=s.end();it++){
                ans=ans+ItoC(*it);
                break;
            }
        }
        return ans;
    }
};

int main()
{
    vector<string> s;
    s.push_back("z");
    s.push_back("x");
    s.push_back("z");
    cout << Solution().alienOrder(s);
    return 0;
}
