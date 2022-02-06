/*
give array A has n number, try to caculate A[n] move m steps to the right
*/
#include <cstdio>
#include <cmath>
#include <algorithm>
int main(){
    int n=0,m=0,count=0;
    scanf("%d %d", &n, &m);
    int A[n];
    m=m%n;
    for(int i=0;i<n;i++)
        scanf("%d", &A[i]);
    for(int i=n-m;i<n;i++){
        printf("%d", A[i]);
        count++;
        if(count<n)
            printf(" ");
    }
    for(int i=0;i<n-m;i++){
        printf("%d", A[i]);
        count++;
        if(count<n)
            printf(" ");
    }

    return 0;
}