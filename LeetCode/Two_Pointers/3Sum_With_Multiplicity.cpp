/*
923
*/
class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        int mod=1e9+7,n=arr.size();
        sort(arr.begin(),arr.end());
        int ans=0;
        for(int i=0;i<n-2;i++){
            int left=i+1,right=n-1;
            while(left<right){
                if(arr[left]+arr[right]==target-arr[i]){
                    if(arr[left]==arr[right]){
                        ans=(ans+(right-left+1)*(right-left)/2)%mod;
                        break;
                    }
                    left++;right--;
                    int l=1,r=1;
                    while(arr[left]==arr[left-1]){
                        l++;
                        left++;
                    }
                    while(arr[right]==arr[right+1]){
                        r++;
                        right--;
                    }
                    ans=(ans+r*l)%mod;
                }
                else if(arr[left]+arr[right]<target-arr[i])
                    left++;
                else    right--;
            }
        }
        return ans;
    }
};