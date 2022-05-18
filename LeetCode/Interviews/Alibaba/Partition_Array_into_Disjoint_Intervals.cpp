/*
917
*/
class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int m=nums.size();
        vector<int> dpmin(m,0),dpmax(m,0);

        dpmax[0]=nums[0],dpmin[m-1]=nums[m-1];
        for(int i=1;i<m;i++)
            dpmax[i]=max(dpmax[i-1],nums[i]);
        for(int i=m-2;i>=0;i--)
            dpmin[i]=min(dpmin[i+1],nums[i]);
        for(int i=0;i<m-1;i++)
            if(dpmax[i]<=dpmin[i+1])
                return i+1;
        return m;
    }
};