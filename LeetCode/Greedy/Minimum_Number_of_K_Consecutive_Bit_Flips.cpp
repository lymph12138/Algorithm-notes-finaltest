/*
995
*/

class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n=nums.size(),ans=0,flip=0;
        for(int i=0;i<n;i++){
            if(nums[i]==flip%2){
                if(i+k>n)   return -1;
                flip++;ans++;
                nums[i]-=2;
            }
            if(i>=k-1 && nums[i-k+1]<0){
                flip--;
                nums[i-k+1]+=2;
            }
        }
        return ans;
    }
};