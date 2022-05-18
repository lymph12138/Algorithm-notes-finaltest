/*
523
*/
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int sum=0;
        map<int,int> mp;
        mp[0]=-1;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            sum%=k;
            if(mp.count(sum)>0){
                if(i-mp[sum]>1) 
                    return true;
            }
            else    mp[sum]=i;
        }
        return false;
    }
};