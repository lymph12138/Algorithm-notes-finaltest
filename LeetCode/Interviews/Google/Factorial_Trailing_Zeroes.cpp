/*
172
*/
class Solution {
public:
    int countfive(int n){
        int ans=0;
        while(n%5==0){
            ans++;
            n/=5;
        }
        return ans;
    }
    int trailingZeroes(int n) {
        int ans=0;
        for(int i=1;i<=n;i++)
            ans+=countfive(i);
        return ans;
    }
};