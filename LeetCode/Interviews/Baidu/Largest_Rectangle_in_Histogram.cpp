/*
84
*/
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> s;
        int ans=0;
        for(int i=0;i<=heights.size();i++){
            while(s.size() && (i==heights.size()||heights[s.top()]>=heights[i])){
                int top=s.top();
                s.pop();
                int width=(i-(s.empty()?0:(s.top()+1)));
                ans=max(ans,heights[top]*width);
            }
            if(i!=heights.size())   s.push(i);
        }
        return ans;
    }
};