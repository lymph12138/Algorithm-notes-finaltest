/*
80
*/
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        if(n<=2)    return n;
        int j=0,c=1;
        for(int i=0;i<n-1;i++){
            if(nums[i]==nums[i+1])  c++;
            else{
                c=(c>=2)?2:1;
                while(c--)  nums[j++]=nums[i];
                c=1;
            }
        } 
        c=(c>=2)?2:1;
        while(c--)  nums[j++]=nums[n-1];
        return j;
    }
};