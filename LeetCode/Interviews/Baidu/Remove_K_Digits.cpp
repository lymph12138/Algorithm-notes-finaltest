/*
402
*/
#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        string ans="";
        int n=num.size();
        if(n==k)    return "0";
        for(int i=0;i<n;i++){
            while(ans.size() && ans.back()>num[i] && ans.size()+n-i>n-k){
                ans.pop_back();
            }
            if(ans.size()<n-k)  ans.push_back(num[i]);
        }
        reverse(ans.begin(),ans.end());
        while(ans.size() && ans.back()=='0')    ans.pop_back();
        reverse(ans.begin(),ans.end());
        return ans.size()?ans:"0";
    }
};

int main(){
    int k=1;
    string num="10";
    cout<<Solution().removeKdigits(num,k);

    return 0;
}