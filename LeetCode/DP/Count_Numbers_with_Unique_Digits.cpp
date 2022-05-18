/*
357
*/

class Solution {
public:
    int An(int i, int j){
        int ans=1;
        for(int l=j;l>j-i;l--)
            ans*=l;
        return ans;
    }
    int countNumbersWithUniqueDigits(int n) {
        int ans=1;
        for(int i=1;i<=n;i++)
            ans+=An(i,10)-An(i-1,9);
        return ans;
    }
};