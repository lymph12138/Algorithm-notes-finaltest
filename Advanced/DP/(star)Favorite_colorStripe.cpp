/*
LCS update
*/
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;
#define maxn 210
#define maxl 10010
int A[maxn],B[maxl],dp[maxn][maxl];

int main(){
    int N,M,L;
    cin>>N>>M;
    for(int i=1;i<=M;i++)
        scanf("%d", &A[i]);
    cin>>L;
    for(int i=1;i<=L;i++)
        scanf("%d", &B[i]);
    fill(dp[0],dp[0]+maxn*maxl,0);
    for(int i=1;i<=M;i++){
        for(int j=1;j<=L;j++){
            if(A[i]==B[j])
                dp[i][j]=max(dp[i-1][j],dp[i][j-1])+1;
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    cout<<dp[M][L];

    return 0;
}