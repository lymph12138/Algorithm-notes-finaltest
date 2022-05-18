/*
LIS
*/
#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
#define maxn 210
#define maxl 10010
int HashTable[maxn],dp[maxl],s[maxl];
int main(){
    int N,M,L,temp;
    fill(HashTable,HashTable+maxn,0);
    fill(dp,dp+maxl,-1);
    cin>>N>>M;
    for(int i=1;i<=M;i++){
        scanf("%d", &temp);
        HashTable[temp]=i;
    }
    int num=0;
    cin>>L;
    for(int i=0;i<L;i++){
        scanf("%d", &temp);
        if(HashTable[temp]>0)
            s[num++]=HashTable[temp];
    }
    int ans=-1;
    for(int i=0;i<num;i++){
        dp[i]=1;
        for(int j=0;j<i;j++){
            if(s[j]<=s[i]){
                dp[i]=max(dp[i],dp[j]+1);
            }
        }
        ans=max(ans,dp[i]);
    }
    printf("%d", ans);

    return 0;
}