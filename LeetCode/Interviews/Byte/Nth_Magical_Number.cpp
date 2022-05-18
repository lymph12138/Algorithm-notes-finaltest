/*
878
*/
class Solution {
public:
    int nthMagicalNumber(int n, int a, int b) {
        int mod=1e9+7;
        int lcm=(a*b)/__gcd(a,b);
        long left=0,right=1e15;
        while(left<right){
            long mid=(left+right)/2;
            long num=mid/a+mid/b-mid/lcm;
            if(num<n)   left=mid+1;
            else    right=mid;
        }
        return left%mod;
    }
};