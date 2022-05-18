/*
239
*/
//O(nlogk)
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        set<pair<int,int>> maxheap;
        int left=0,right=0;
        while(right<k){
            maxheap.insert({nums[right],right});
            right++;
        }
        vector<int> ans;
        ans.push_back(maxheap.rbegin()->first);
        while(right<n){
            maxheap.insert({nums[right],right});
            auto iter=maxheap.find({nums[left],left});
            maxheap.erase(iter);
            ans.push_back(maxheap.rbegin()->first);
            left++,right++;
        }
        return ans;
    }
};
//O(n)
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        deque<int> q;
        vector<int> ans;
        for(int i=0;i<n;i++){
            while(q.size() && q.front()<=i-k)   q.pop_front();
            while(q.size() && nums[q.back()]<nums[i])   q.pop_back();
            q.push_back(i);
            if(i>=k-1)  ans.push_back(nums[q.front()]);
        }
        return ans;
    }
};