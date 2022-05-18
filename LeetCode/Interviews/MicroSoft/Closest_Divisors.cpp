/*
1362
*/
class Solution {
public:
    int Find(int num, int& left, int& right){
        int n=sqrt(num);
        if(n*n==num){
            left=n;right=n;
            return 0;
        }
        int ans=num;
        for(int j=n;j>=1;j--){
            int i=num/j;
            if(i*j==num && (i-j)<ans){
                left=j;right=i;ans=right-left;
            }
        }
        return ans;
    }
    vector<int> closestDivisors(int num) {
        int left1,left2,right1,right2;
        int ans1=Find(num+1,left1,right1);
        int ans2=Find(num+2,left2,right2);
        if(ans1<ans2)   return {left1,right1};
        else    return {left2,right2};
    }
};