/*
give two strings S1 and S2, try to caculate S1-S2
*/
#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;

int main(){
    int ascii[200]={0};
    string S1, S2;
    getline(cin, S1);
    getline(cin, S2);
    for(int i=0;i<S2.length();i++)
        ascii[S2[i]]=-1;
    for(int i=0;i<S1.length();i++)
        if(ascii[S1[i]]==0)
            cout<<S1[i];

    return 0;
}