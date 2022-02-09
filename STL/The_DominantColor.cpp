/*

*/
#include <cstdio>
#include <map>
#include <iostream>
using namespace std;

int main(){
    int m,n,temp;
    scanf("%d %d", &n, &m);
    map<int, int> count;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%d", &temp);
            if(count.find(temp)!=count.end())
                count[temp]++;
            else
                count[temp]=1;
        }
    }
    int k=0,max=0;
    for(auto it=count.begin();it!=count.end();it++){
        if(it->second>max){
            k=it->first;
            max=it->second;
        }
    }
    printf("%d", k);
    
    return 0;
}