/*
shuffling card, give card S1, S2,..., S13, H1,..., H13, C1,..., C13, D1,..., D13, J1, J2
example we have five card S3, H5, C1, D13, J2, shuffling order{4, 2, 5, 3, 1},
it becomes J2, H5, D13, S3, C1, again, it becomes C1, H5, S3, J2, D13
input n, shuffling times and 54 card output shuffling result
*/
#include <cstdio>
#include <cmath>
#include <algorithm>
int main(){
    int order[55], order1[2][55];
    int n;
    scanf("%d", &n);
    for(int i=1;i<55;i++){
        scanf("%d", &order[i]);
        order1[0][i]=i;
    }
    for(int i=0;i<n;i++){
        if(i%2==0)
            for(int j=1;j<55;j++)
                order1[1][order[j]]=order1[0][j];
        else
            for(int j=1;j<55;j++)
                order1[0][order[j]]=order1[1][j];
    }
    char c[]="SHCDJ ";
    for(int i=1;i<55;i++)
        printf("%c%d%c", c[(order1[n%2][i]-1)/13],(order1[n%2][i]-1)%13+1,i==54?'\0':c[5]);

    return 0;
}