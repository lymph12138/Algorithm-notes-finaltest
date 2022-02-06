/*
give a sentense, try to caculate the most frequent word
*/
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <map>
#include <cstring>
#include <string>
using namespace std;

bool check(char c){
    if(c>='0' && c<='9')
        return true;
    if(c>='A' && c<='Z')
        return true;
    if(c>='a' && c<='z')
        return true;
    return false;
}
int main(){
    map<string, int> count;
    string str;
    getline(cin, str);
    int tag=0;
    while(tag<str.length()){
        string word;
        while(tag<str.length() && check(str[tag])==true){
            if(str[tag]>='A' && str[tag]<='Z')
                str[tag]+='a'-'A';
            word += str[tag];
            tag++;
        }
        if(word!=""){
            if(count.find(word)!=count.end())
                count[word]++;
            else
                count[word]=1;
        }
        while(tag<str.length() && check(str[tag])==false)
            tag++;
    }
    string ans;
    int max=0;
    for(auto it=count.begin();it!=count.end();it++){
        if(it->second>max){
            ans=it->first;
            max=it->second;
        }
    }
    cout<<ans<<" "<<max<<endl;

    return 0;
}