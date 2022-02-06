/*
give two set contains n integers. try to caculate the biggest sum 
when you select one interger from the two set times and sum n times.
*/
#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;
#define maxn 100000
int A1[maxn], A2[maxn];
int main(){
    int m,n;
    scanf("%d", &m);
    for(int i=0;i<m;i++)
        scanf("%d", &A1[i]);
    scanf("%d", &n);
    for(int i=0;i<n;i++)
        scanf("%d", &A2[i]);
    sort(A1,A1+m);
    sort(A2,A2+n);
    int l=0,k=0,ans=0;
    while(l<m && k<n && A1[l]<0 && A2[k]<0)
        ans+=A1[l++]*A2[k++];
    l=m-1;k=n-1;
    while(l>=0 && k>=0 && A1[l]>0 && A2[k]>0)
        ans+=A1[l--]*A2[k--];
    printf("%d", ans);

    return 0;
}