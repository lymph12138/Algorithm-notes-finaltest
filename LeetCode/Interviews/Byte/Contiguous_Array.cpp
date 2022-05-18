/*
525
*/
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n=nums.size();
        map<int,int> mp;
        int ans=0,c=0;
        for(int i=0;i<n;i++){
            if(nums[i]==0)    c--;
            else    c++;
            if(c==0)    ans=i+1;
            if(mp.find(c)==mp.end())    mp[c]=i;
            else    ans=max(ans,i-mp[c]);
        }
        return ans;
    }
};
