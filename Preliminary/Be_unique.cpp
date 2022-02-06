/*
give a positive integer n less than 10^4, following n number.
try to find out the first number appear one time.
*/
#include <cstdio>
#include <algorithm>
int figure[10011]={0};
int main(){
    int n;
    scanf("%d", &n);
    int a[n]={0};
    for(int i=0;i<n;i++){
        scanf("%d", &a[i]);
        figure[a[i]]++;
    }
    for(int i=0;i<n;i++){
        if(figure[a[i]]==1){
            printf("%d", a[i]);
            return 0;
        }
    }
    printf("None");

    return 0;
}