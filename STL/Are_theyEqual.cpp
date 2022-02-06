/*
give three numbers N, A and B, where N is the number of significant and A and B are the two float numbers
try to caculate A and B are equal or not.
*/
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
int n;
string deal(string s, int &e){
    int k=0;
    while(s.length()>0 && s[0]=='0'){
        s.erase(s.begin());
    }
    if(s[0]=='.'){
        s.erase(s.begin());
        while(s.length()>0 && s[0]=='0'){
            s.erase(s.begin());
            e--;
        }
    }
    else{
        while(k<s.length() && s[k]!='.'){
            k++;
            e++;
        }
        if(k<s.length()){
            s.erase(s.begin()+k);
        }
    }
    if(s.length()==0)
        e=0;
    int tag=0;
    k=0;
    string s1;
    while(tag<n){
        if(k<s.length())
            s1 += s[k++];
        else
            s1 += '0';
        tag++;
    }
    return s1;
}
int main(){
    int e1=0,e2=0;
    string num1, num2, num3, num4;
    cin>>n>>num1>>num2;
    num3=deal(num1,e1);
    num4=deal(num2,e2);
    if(num3==num4 && e1==e2)
        cout<<"YES 0."<<num3<<"*10^"<<e1<<endl;
    else
        cout<<"NO 0."<<num3<<"*10^"<<e1<<" 0."<<num4<<"*10^"<<e2<<endl;

    return 0;
}
