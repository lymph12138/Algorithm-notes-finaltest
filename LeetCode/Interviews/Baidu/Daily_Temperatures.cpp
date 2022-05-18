/*
739
*/
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        stack<int> s;
        vector<int> ans(t.size(),0);
        for(int i=0;i<t.size();i++){
            while(s.size() && t[s.top()]<t[i]){
                int top=s.top();
                s.pop();
                ans[top]=i-top;
            }
            s.push(i);
        }
        return ans;
    }
};