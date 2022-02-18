/*
dfs
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> fac, ans, temp;
int n, k, p, maxfacsum=-1;
int power(int x){
    int ans=1;
    for(int i=0;i<p;i++)
        ans*=x;
    return ans;
}
void init(){
    int i=0,tmp=0;
    while(tmp<=n){
        fac.push_back(tmp);
        tmp=power(++i);
    }
}
void DFS(int index,int nowK,int sum,int facsum){
    if(nowK==k && sum==n){
        if(facsum>maxfacsum){
            ans=temp;
            maxfacsum=facsum;
        }
        return ;
    }
    if(sum>n || nowK>k) return ;
    if(index>=1){
        temp.push_back(index);
        DFS(index,nowK+1,sum+fac[index],facsum+index);
        temp.pop_back();
        DFS(index-1,nowK,sum,facsum);
    }
}

int main(){
    scanf("%d %d %d", &n, &k, &p);
    init();
    DFS(fac.size()-1,0,0,0);
    if(maxfacsum==-1)
        printf("Impossible\n");
    else{
        printf("%d = %d^%d",n,ans[0],p);
        for(int i=1;i<ans.size();i++)
            printf(" + %d^%d",ans[i],p);
    }


    return 0;
}
