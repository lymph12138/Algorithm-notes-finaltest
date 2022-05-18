/*
1987
*/
class Solution {
public:
    int numberOfUniqueGoodSubsequences(string binary) {
        int mod=1e9+7,zeros=0,ones=0,tag=0;
        for(auto c:binary){
            if(c=='1')
                ones=(zeros+ones+1)%mod;
            else{
                zeros=(zeros+ones)%mod;
                tag=1;
            }
        }
        
        return (zeros+ones+tag)%mod;
    }
};