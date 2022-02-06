/*
give two integers n and k, then followed n lines each contains student's name

*/
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <iostream>
using namespace std;
#define smax 40010
#define cmax 2510
#define maxn 26*26*26*10+10

bool cmp(int i,int j){
    return i<j;
}
int getID(char name[]){
    int id=0;
    for(int i=0;i<3;i++)
        id=id*26+(name[i]-'A');
    id=id*10+name[3]-'0';
    return id;
}
void getstring(int id,char name[]){
    name[4]='\0';
    name[3]=id%10+'0';
    id/=10;
    for(int i=2;i>=0;i--){
        name[i]=id%26+'A';
        id/=26;
    }
}

vector<int> course[cmax];
int main(){
    int snum,cnum,id;
    scanf("%d %d",&snum,&cnum);
    char name[5];
    for(int i=0;i<snum;i++){
        int n,temp;
        scanf("%s %d",name,&n);
        id=getID(name);
        for(int j=0;j<n;j++){
            scanf("%d", &temp);
            course[temp].push_back(id);
        }
    }
    char str[5];
    for(int i=1;i<=cnum;i++){
        printf("%d %d\n",i,course[i].size());
        sort(course[i].begin(),course[i].end(),cmp);
        for(int j=0;j<course[i].size();j++){
            getstring(course[i][j],str);
            printf("%s\n",str);
        }
    }

    return 0;
}