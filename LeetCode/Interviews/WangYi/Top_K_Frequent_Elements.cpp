/*
347
*/
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> mp;
        priority_queue<pair<int,int>> pq;
        for(int i=0;i<nums.size();i++)
            mp[nums[i]]++;
        for(auto it=mp.begin();it!=mp.end();it++)
            pq.push({it->second,it->first});
        vector<int> ans;
        while(k--){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};

class Solution {
public:
    static bool compare(vector<int> a, vector<int> b){
        if(a[0]==b[0])  return a[1]<b[1];
        else return a[0]>b[0];
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> dp(nums.size(),vector<int>(2,0));
        int j=0;
        int last=nums[0];
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=last){
                j++;
                last=nums[i];
            }
            dp[j][1]=nums[i];
            dp[j][0]++;
        }
        sort(dp.begin(),dp.end(),compare);
        vector<int> ans;
        for(int i=0;i<k;i++)    ans.push_back(dp[i][1]);
        return ans;
    }
};