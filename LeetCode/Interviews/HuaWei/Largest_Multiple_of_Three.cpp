/*
1363
*/
#include <cstdio>
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    void remove(int n,int& x1,int& x2,int& x3){
        while(n && x1){n--;x1--;}
        while(n && x2){n--;x2--;}
        while(n && x3){n--;x3--;}
    }
    string largestMultipleOfThree(vector<int>& digits) {
        int n=digits.size();
        vector<int> num(10,0);
        for(int i=0;i<n;i++)    num[digits[i]]++;
        int mod0=num[0]+num[3]+num[6]+num[9];
        int mod1=num[1]+num[4]+num[7];
        int mod2=num[2]+num[5]+num[8];
        int modall=(mod1+mod2*2)%3;
        if(modall==1){
            if(mod1>=1) remove(1,num[1],num[4],num[7]);
            else if(mod2>=2)    remove(2,num[2],num[5],num[8]);
            else return "";
        }
        else if(modall==2){
            if(mod2>=1) remove(1,num[2],num[5],num[8]);
            else if(mod1>=2)    remove(2,num[1],num[4],num[7]);
            else return "";
        }
        string ans="";
        for(int i=9;i>=0;i--){
            while(num[i]--) ans+='0'+i;
        }
        if(ans.size() && ans[0]=='0') return "0";

        return ans;
    }
};

int main(){
    vector<int> digits={8,7,2,9,0,1};
    Solution().largestMultipleOfThree(digits);

    return 0;
}