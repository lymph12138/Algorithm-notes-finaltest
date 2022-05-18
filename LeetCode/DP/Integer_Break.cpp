/*
343
*/

#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int integerBreak(int n) {
        if(n==2)    return 1;
        if(n==3)    return 2;
        if(n%3==2)
            return pow(3,n/3)*2;
        else if(n%3==1)
            return pow(3,n/3-1)*4;
        else    return pow(3,n/3);
    }
};

class Solution {
public:
    int newpow(int n,int k){
        int m=n/k;int l=n%k;
        int ans=1;
        for(int i=1;i<=k;i++){
            if(i<=l) ans*=(m+1);
            else    ans*=m;
        }
        return ans;
    }
    int integerBreak(int n) {
        int ans=0;
        for(int i=2;i<=n;i++)
            ans=max(ans,newpow(n,i));
        return ans;
    }
};

int main(){
    int n=2;
    cout<<Solution().integerBreak(n);

    return 0;
}