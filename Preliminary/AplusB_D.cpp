/*
give three integers A and B and D with decimal, try to caculate A+B in D base.
*/
#include <cstdio>
#include <cmath>
#include <algorithm>
int main(){
    int A, B, D;
    scanf("%d %d %d", &A, &B, &D);
    int ans[32]={0};
    int sum=A+B;
    int num=0;
    do{
        ans[num++]=sum%D;
        sum=sum/D;
    }while(sum!=0);
    for(int i=num-1;i>=0;i--)
        printf("%d", ans[i]);

    return 0;
}