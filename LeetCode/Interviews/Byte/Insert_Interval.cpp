/*
57
*/
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n=intervals.size();
        vector<vector<int>> ans;
        if(n==0){
            ans.push_back(newInterval);
            return ans;
        }
        bool flag=false;
        for(int i=0;i<n;){
            if(intervals[i][1]<newInterval[0] || flag){
                ans.push_back({intervals[i][0],intervals[i][1]});
                i++;
            }
            else if(intervals[i][0]<=newInterval[1] && !flag){
                int left=intervals[i][0];
                int right=intervals[i][1];
                while(i<n && intervals[i][0]<=newInterval[1]){
                    right=max(right,intervals[i][1]);
                    i++;
                }
                left=min(newInterval[0],left);
                right=max(right,newInterval[1]);
                ans.push_back({left,right});
                flag=true;
            }
            else{
                ans.push_back(newInterval);
                flag=true;
            }
        }
        if(newInterval[0]>intervals[n-1][1])    ans.push_back(newInterval);
        return ans;
    }
};