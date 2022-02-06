/*
give an integer n less than 10^1000, try to caculate the numbers of digits. 
*/
#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;
int main(){
    string str;
    cin>>str;
    int digits[10]={0};
    for(int i=0;i<str.size();i++)
        digits[str[i]-'0']++;
    for(int i=0;i<10;i++)
        if(digits[i]!=0)
            printf("%d:%d\n", i, digits[i]);

    return 0;
}