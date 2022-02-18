/*
bfs
*/
#include <iostream>
#include <queue>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
#define Mmax 1300
#define Nmax 130
#define Lmax 65
int pixel[Mmax][Nmax][Lmax];
bool inq[Mmax][Nmax][Lmax]={false};
int n,m,l,t;
struct node{
    int x,y,z;
}Node;
int Xfloat[6]={1,-1,0,0,0,0};
int Yfloat[6]={0,0,1,-1,0,0};
int Zfloat[6]={0,0,0,0,1,-1};
bool judge(int x, int y, int z){
    if(x>=n || y>=m || z>=l || x<0 || y<0 || z<0)
        return false;
    if(pixel[x][y][z]==0 || inq[x][y][z]==true)
        return false;
    return true;
}

int BFS(int x, int y, int z){
    int total=0;
    queue<node> Q;
    Node.x=x;Node.y=y;Node.z=z;
    Q.push(Node);
    inq[x][y][z]=true;
    while(!Q.empty()){
        node temp=Q.front();
        Q.pop();
        total++;
        for(int i=0;i<6;i++){
            int newx=temp.x+Xfloat[i];
            int newy=temp.y+Yfloat[i];
            int newz=temp.z+Zfloat[i];
            if(judge(newx, newy, newz)){
                Node.x=newx;Node.y=newy;Node.z=newz;
                Q.push(Node);
                inq[newx][newy][newz]=true;
            }
        }
    }
    if(total>=t)    return total;
    else    return 0;
}

int main(){
    scanf("%d %d %d %d", &n, &m, &l, &t);
    for(int i=0;i<l;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<m;k++){
                scanf("%d", &pixel[j][k][i]);
            }
        }
    }
    int ans=0;
    for(int i=0;i<l;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<m;k++){
                if(pixel[j][k][i]==1 && inq[j][k][i]==false){
                    ans+=BFS(j,k,i);
                }
            }
        }
    }
    printf("%d",ans);
    
    return 0;
}