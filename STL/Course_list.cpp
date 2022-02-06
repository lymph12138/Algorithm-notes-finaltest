/*
give two positive integers:N and K, then followeed 2*K line
coursei,studenti,and i name.
*/
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstring>
#include <vector>
#define smax 40010
#define cmax 2510
#define maxn 26*26*26*10+10
using namespace std;
int getID(char name[]){
    int id=0;
    for(int i=0;i<3;i++)
        id=id*26+(name[i]-'A');
    id=id*10+name[3]-'0';
    return id;
}
bool cmp(int i,int j){
    return i<j;
}
vector<int> students[maxn];
int main(){
    int snum,cnum,id,course,n;
    char name[5];
    scanf("%d %d", &snum, &cnum);
    for(int i=0;i<cnum;i++){
        scanf("%d %d", &course, &n);
        for(int j=0;j<n;j++){
            scanf("%s",name);
            id=getID(name);
            students[id].push_back(course);
        }
    }
    for(int i=0;i<snum;i++){
        scanf("%s", name);
        id=getID(name);
        printf("%s",name);
        sort(students[id].begin(),students[id].end(),cmp);
        printf(" %d",students[id].size());
        for(int j=0;j<students[id].size();j++)
            printf(" %d", students[id][j]);
        printf("\n");
    }

    return 0;
}