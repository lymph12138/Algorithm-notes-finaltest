/*
22
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        DFS(ans,0,0,n,"");
        return ans;
    }
private:
    void DFS(vector<string> &ans,int open,int close,int n,string cur){
        if(cur.size()==2*n){
            ans.push_back(cur);
            return ;
        }
        if(open<n)  DFS(ans,open+1,close,n,cur+"(");
        if(close<open)  DFS(ans,open,close+1,n,cur+")");
    }
};
*/
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
vector <string> ans;
int n;
void DFS(vector<string> &ans, int open, int close, string cur){
    if(cur.size()==2*n){
        ans.push_back(cur);
        return ;
    }
    if(open<n)  DFS(ans,open+1,close,cur+"(");
    if(close<open)  DFS(ans,open,close+1,cur+")");
}

int main(){
    cin>>n;
    DFS(ans,0,0,"");
    for(int i=0;i<ans.size();i++)
        cout<<ans[i]<<endl;

    return 0;
}
