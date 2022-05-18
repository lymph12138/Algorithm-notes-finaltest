/*
332
*/
#include <cstdio>
#include <algorithm>
#include <map>
#include <queue>
#include <vector>
#include <string>
#include <cstring>
#include <iostream>
using namespace std;
class Solution {
private:
    map<string,priority_queue<string,vector<string>,greater<string>>> graph;
public:
    void dfs(string now,vector<string>& ans){
        while(graph[now].size()!=0){
            string temp=graph[now].top();
            graph[now].pop();
            dfs(temp,ans);
        }
        ans.push_back(now);
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for(int i=0;i<tickets.size();i++){
            string temp1=tickets[i][0];
            string temp2=tickets[i][1];
            graph[temp1].push(temp2);
        }
        string start="JFK";
        vector<string> ans;
        dfs(start,ans);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

int main(){
    vector<vector<string>> s={{"SJC","JFK"},{"JFK","MUC"},{"JFK","SJC"}};
    vector<string> ans;
    ans=Solution().findItinerary(s);

    return 0;
}