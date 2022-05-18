/*
313
*/
#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int m=primes.size();
        vector<int> dp(n,0);
        dp[0]=1;
        vector<int> p(m,0);
        int i=1;
        while(i<n){
            int temp=INT_MAX;
            int tag=0;
            for(int j=0;j<m;j++){
                if(temp>dp[p[j]]*primes[j]){
                    tag=j;
                    temp=dp[p[j]]*primes[j];
                }
            }
            for(int j=0;j<m;j++)
                if(temp==dp[p[j]]*primes[j])
                    p[j]++;
            dp[i++]=temp;
        }
        return dp[n-1];
    }
};

int main(){
    vector<int> primes={2,3,5};
    int n=15;
    cout<<Solution().nthSuperUglyNumber(n,primes);

    return 0;
}