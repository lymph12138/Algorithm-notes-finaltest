/*
give a cluster of number, try to caculate five types of number.
A1 : n%5=0 && n%2=0, n1+n2+n3;A2 : n%5=1, n1-n2+n3-n4; A3 : n%5=3, number of A3;
A4 : n%5=3, average of A4; A5 : n%5=4, max of A5
*/
#include <cstdio>
#include <cmath>
#include <algorithm>
int main(){
    int A[5]={0};
    int ans[5]={0};
    int a[5]={0};
    int n,temp;
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        scanf("%d", &temp);
        if(temp%5==0 && temp%2==0){
            ans[0]=ans[0]+temp;
            a[0]++;
        }
        else if(temp%5==1){
            if(a[1]%2==0) ans[1]=ans[1]+temp;
            else ans[1]=ans[1]-temp;
            a[1]++;
        }
        else if(temp%5==2){
            ans[2]++;
            a[2]++;
        } 
        else if(temp%5==3){
            ans[3]=ans[3]+temp;
            a[3]++;
        }
        else{
            if(temp>ans[4])
                ans[4]=temp;
            a[4]++;
        }
    }
    for(int i=0;i<5;i++){
        if(i==3){
            if(a[3]!=0) printf("%.1f ", (double)ans[3]/a[3]);
            else printf("N ");
            continue;
        }
        if(a[i]!=0) printf("%d", ans[i]);
        else printf("N");
        if(i!=4) printf(" ");
    }

    return 0;
}