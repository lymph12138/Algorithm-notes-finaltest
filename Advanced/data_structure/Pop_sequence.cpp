/*
try to caculate the number sequences is the possible sequences of the require stack.
*/
#include <cstdio>
#include <stack>
#include <iostream>
using namespace std;
#define maxn 1010
int arr[maxn];
stack <int> st;
int main(){
    int capacity, len, sequences;
    scanf("%d %d %d", &capacity, &len, &sequences);
    while(sequences--){
        while(!st.empty())
            st.pop();
        for(int j=1;j<=len;j++)
            scanf("%d", &arr[j]);
        int current=1;
        int flag=1;
        for(int i=1;i<=len;i++){
            st.push(i);
            if(st.size()>capacity){
                flag=0;
                break;
            }
            while(!st.empty() && st.top()==arr[current]){
                st.pop();
                current++;
            }  
        }
        if(flag==1 && st.empty())
            printf("YES\n");
        else    printf("NO\n");
    }

    return 0;
}