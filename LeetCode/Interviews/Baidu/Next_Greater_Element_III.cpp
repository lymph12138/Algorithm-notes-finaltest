/*
556
*/
class Solution {
public:
    int nextGreaterElement(int n) {
        vector<int> nums,temp;
        while(n){
            nums.push_back(n%10);
            n/=10;
        }
        temp=nums;
        sort(temp.begin(),temp.end());
        if(temp==nums)  return -1;
        int tag;
        for(tag=0;tag<nums.size()-1;tag++){
            if(nums[tag]>nums[tag+1])   break;
        }
        temp.clear();
        for(int i=0;i<=tag;i++)
            temp.push_back(nums[i]);
        sort(temp.begin(),temp.end());
        bool flag=false;
        for(int i=0;i<=tag;i++){
            if(!flag && temp[i]>nums[tag+1]){
                nums[tag-i]=nums[tag+1];
                nums[tag+1]=temp[i];
                flag=true;
            }
            else    nums[tag-i]=temp[i];
        }
        int ans=0;
        for(int i=nums.size()-1;i>=0;i--){
            if(ans>(INT_MAX-nums[i])/10)    return -1;
            ans=ans*10+nums[i];
        }
        return ans;
    }
};