/*
give an integer no more than 20 digits, try to caculate if it is the same permutation when it doubled or not. 
*/
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;

int main(){
    int numbers[10]={0};
    char numstr[21];
    scanf("%s",numstr);
    int len=strlen(numstr);
    int flag=0,temp;
    for(int i=len-1;i>=0;i--){
        temp=numstr[i]-'0';
        numbers[temp]++;
        temp=temp*2+flag;
        flag=0;
        if(temp>=10){
            temp=temp-10;
            flag=1;
        }
        numbers[temp]--;
        numstr[i]=(temp+'0');
    }
    for(int i=0;i<10;i++)
        if(numbers[i]!=0){
            printf("No\n%s%s",flag==0?"":"1",numstr);
            return 0;
        }
    printf("Yes\n%s%s",flag==0?"":"1",numstr);        

    return 0;
}