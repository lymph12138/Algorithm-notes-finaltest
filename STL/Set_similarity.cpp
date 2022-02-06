/*
try to caculate the similarity of two sets
*/
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
const int N=51;
set<int> st[N];

void compare(int x,int y){
    int totalnum=st[y].size(),samnum=0;
    for(auto it=st[x].begin();it!=st[x].end();it++){
        if(st[y].find(*it)!=st[y].end())    samnum++;
        else    totalnum++;
    }
    printf("%.1f%\n",(double)samnum*100/totalnum);
}

int main(){
    int setnum,m,k,temp,s1,s2;
    scanf("%d",&setnum);
    for(int i=1;i<=setnum;i++){
        scanf("%d",&m);
        for(int j=0;j<m;j++){
            scanf("%d", &temp);
            st[i].insert(temp);
        }
    }
    scanf("%d", &k);
    for(int i=0;i<k;i++){
        scanf("%d %d",&s1,&s2);
        compare(s1,s2);
    }

    return 0;
}