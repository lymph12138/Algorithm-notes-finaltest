/*
give two integers n and k, such as abc,abc+cba until abc is a palindromic number 
*/
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
string str;
void add(string t){
    int flag=0;
    int len=t.length();
    for(int i=len-1;i>=0;i--){
        str[i]=str[i]+t[i]+flag-'0';
        flag=0;
        if(str[i]>'9'){
            flag=1;
            str[i]=str[i]-10;
        }
    }
    if(flag==1)
        str='1'+str;
}
int main(){
    int k,steps;
    cin>>str>>k;
    for(steps=0;steps<k;steps++){
        string t=str;
        reverse(t.begin(),t.end());
        if(t==str)
            break;
        add(t);
    }
    reverse(str.begin(),str.end());
    cout<<str<<"\n"<<steps;

    return 0;
}