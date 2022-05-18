/*
670
*/
class Solution {
public:
    int caculate(vector<int> temp){
        int res=0;
        for(int i=temp.size()-1;i>=0;i--)
            res=res*10+temp[i];
        return res;
    }
    int maximumSwap(int num) {
        vector<int> digits;
        int ans=num;
        if(num<10)  return num;
        while(num){
            int x=num%10;
            digits.push_back(x);
            num/=10;
        }
        for(int i=1;i<digits.size();i++){
            for(int j=0;j<i;j++){
                vector<int> temp=digits;
                swap(temp[i],temp[j]);
                ans=max(ans,caculate(temp));
            }
        }
        return ans;
    }
};