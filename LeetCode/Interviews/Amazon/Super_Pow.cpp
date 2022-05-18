/*
372
*/
class Solution {
public:
    int superPow(int a, vector<int>& b) {
        int ans=1,mul=a%1337;
        for(int i=b.size()-1;i>=0;i--){
            int tenmul=1;
            for(int j=0;j<10;j++){
                if(j<b[i])  ans=(ans*mul)%1337;
                tenmul=(tenmul*mul)%1337;
            }
            mul=tenmul;
        }
        return ans;
    }
};