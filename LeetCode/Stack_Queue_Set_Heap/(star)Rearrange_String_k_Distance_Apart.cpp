/*
358
*/
#include <cstdio>
#include <vector>
#include <iostream>
#include <string>
#include <cstring>
#include <set>
#include <queue>
#include <unordered_map>
#include <utility>
using namespace std;

class Solution {
public:
    string rearrangeString(string s, int k) {
        priority_queue<pair<int,int>> pq;
        queue<pair<int,int>> temp;
        vector<int> alpha(26,0),pre(26,-1);
        for(auto c:s)   alpha[c-'a']++;
        for(int i=0;i<26;i++){
            if(alpha[i]!=0) pq.push({alpha[i],i});
        }
        string ans;
        int num,alp;
        while(pq.size()){
            num=pq.top().first,alp=pq.top().second;
            while(pq.size() && pre[alp]!=-1 && ans.size()-pre[alp]<k){
                temp.push({num,alp});
                pq.pop();
                num=pq.top().first,alp=pq.top().second;
            }
            if(!pq.size())  return "";
            pq.pop();
            pre[alp]=ans.size();
            ans.push_back(alp+'a');
            if(num!=1)  pq.push({num-1,alp});
            while(temp.size()){
                num=temp.front().first,alp=temp.front().second;
                pq.push({num,alp});
                temp.pop();
            }  
        }
        return ans;
    }
};

int main(){
    string s="aaadbbcc";
    int k=2;
    cout<<Solution().rearrangeString(s,k);

    return 0;
}