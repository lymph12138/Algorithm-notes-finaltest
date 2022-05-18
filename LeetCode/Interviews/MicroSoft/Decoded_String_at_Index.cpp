/*
880
*/

#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string decodeAtIndex(string s, int k) {
        long long int size=0;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(isalpha(s[i]))   size++;
            else    size=size*(s[i]-'0');
        }
        for(int i=n-1;i>=0;i--){
            k=k%size;
            if(k==0 && isalpha(s[i]))
                return (string)""+s[i];
            if(isdigit(s[i]))   size=size/(s[i]-'0');
            else    size--;
        }
        return s.substr(k,1);
    }
};

int main(){
    string s="leet2code3";
    int k=10;
    cout<<Solution().decodeAtIndex(s,k);

    return 0;
}