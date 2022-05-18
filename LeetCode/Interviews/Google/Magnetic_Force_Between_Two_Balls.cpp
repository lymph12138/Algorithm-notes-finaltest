/*
1552
*/
class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        int n=position.size();
        sort(position.begin(),position.end());
        int l=0,r=position[n-1],ans;
        while(l<=r){
            int c=1,left=0;
            int mid=(l+r)/2;
            for(int i=1;i<n;i++){
                if(position[i]-position[left]>=mid){
                    c++;
                    left=i;
                }
            }
            if(c>=m){
                ans=mid;
                l=mid+1;
            }
            else    r=mid-1;
        }
        return ans;
    }
};