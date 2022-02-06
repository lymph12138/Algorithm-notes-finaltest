/*
first line give a integer a and a polynomial A as same as second line B.
try to caculate A+B for polynomials.
*/
#include <cstdio>
#include <cmath>
#include <algorithm>
typedef struct poly{
    int index;
    float modulus;
}Poly;
int main(){
    int n1,n2;
    Poly L1[22],L2[22],L[22];
    scanf("%d", &n1);
    for(int i=1;i<=n1;i++)
        scanf("%d %f", &L1[i].index, &L1[i].modulus);
    scanf("%d", &n2);
    for(int j=1;j<=n2;j++)
        scanf("%d %f", &L2[j].index, &L2[j].modulus);
    int n3=0,i=1,j=1;
    while(i<=n1 && j<=n2){
        if(L1[i].index>L2[j].index){
            L[n3+1].index=L1[i].index;
            L[n3+1].modulus=L1[i].modulus;
            i++;
        }
        else if(L1[i].index<L2[j].index){
            L[n3+1].index=L2[i].index;
            L[n3+1].modulus=L2[i].modulus;
            j++;
        }
        else{
            L[n3+1].index=L1[i].index;
            L[n3+1].modulus=L1[i].modulus+L2[j].modulus;
            i++;j++;
        }
        if(L[n3+1].modulus!=0)
            n3++;
    }
    while(i<=n1){
        L[n3+1].index=L1[i].index;
        L[n3+1].modulus=L1[i].modulus;
        i++;n3++;
    }
    while(j<=n2){
        L[n3+1].index=L2[i].index;
        L[n3+1].modulus=L2[i].modulus;
        j++;n3++;
    }
    printf("%d", n3);
    for(int k=1;k<=n3;k++)
        printf(" %d %.1f", L[k].index, L[k].modulus);
    
    return 0;
}

int main(){
    float p[1001]={0};
    int n1=0,n2=0;
    scanf("%d", &n1);
    int index;
    float modulus;
    for(int i=0;i<n1;i++){
        scanf("%d %f", &index, &modulus);
        p[index]=p[index]+modulus;
    }
    scanf("%d", &n2);
    for(int i=0;i<n2;i++){
        scanf("%d %f", &index, &modulus);
        p[index]=p[index]+modulus;
    }
    int n3=0;
    for(int i=0;i<1001;i++)
        if(p[i]!=0)
            n3++;
    printf("%d", n3);
    for(int i=1000;i>=0;i--)
        if(p[i]!=0)
            printf(" %d %.1f", i, p[i]);
    
    return 0;
}