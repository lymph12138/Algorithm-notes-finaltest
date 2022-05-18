/*
1944
*/
class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        vector<int> stack;
        int n=heights.size();
        if(n==1)    return {0};
        vector<int> ans(n,0);
        for(int i=n-1;i>=0;i--){
            while(stack.size() && stack.back()<heights[i]){
                stack.pop_back();
                ans[i]++;
            }
            ans[i]+=!stack.empty();
            stack.push_back(heights[i]);
        }
        return ans;
    }
};