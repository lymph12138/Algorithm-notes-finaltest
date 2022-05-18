/*
801
*/
class Solution {
public:
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        int swap=1,noswap=0,n=nums1.size();
        for(int i=1;i<n;i++){
            int curswap=n,curnoswap=n;
            if(nums1[i]>nums1[i-1] && nums2[i]>nums2[i-1]){
                curswap=min(curswap,1+swap);
                curnoswap=min(curnoswap,noswap);
            }
            if(nums1[i]>nums2[i-1] && nums2[i]>nums1[i-1]){
                curswap=min(curswap,1+noswap);
                curnoswap=min(curnoswap,swap);
            }
            swap=curswap;
            noswap=curnoswap;
        }
        return min(swap,noswap);
    }
};