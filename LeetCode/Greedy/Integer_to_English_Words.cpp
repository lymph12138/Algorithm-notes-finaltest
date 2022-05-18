/*
273
*/
class Solution {
public:
    vector<string> One={"Zero","One","Two","Three","Four","Five","Six","Seven","Eight","Nine"};
    vector<string> Ten={"","","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety"};
    string spell(int num){
        if(num>=1000 || num<=0)  return "";
        if(num==0)  return "Zero";
        string ans="";
        if(num>=100){
            ans=ans+One[num/100]+" Hundred";
            num=num%100;
            if(num==0)  return ans;
            else    ans+=" ";
        }
        if(num>=20){
            ans=ans+Ten[num/10];
            num=num%10;
            if(num==0)  return ans;
            else ans+=" ";
        }
        if(num>=10){
            if(num==10) ans=ans+"Ten";if(num==11) ans=ans+"Eleven";if(num==12) ans=ans+"Twelve";
            if(num==13) ans=ans+"Thirteen";if(num==14) ans=ans+"Fourteen";if(num==15) ans=ans+"Fifteen";
            if(num==16) ans=ans+"Sixteen";if(num==17) ans=ans+"Seventeen";if(num==18) ans=ans+"Eighteen";
            if(num==19) ans=ans+"Nineteen";
        }
        else    ans=ans+One[num];
        return ans;
    }
    string numberToWords(int num) {
        if(num==0)  return "Zero";
        vector<int> digits;
        while(num){
            digits.push_back(num%10);
            num/=10;
        }
        string ans;
        int n,temp;
        if(digits.size()>=10){
            if(digits.back()==1)
                ans=ans+"One Billion";
            else    ans=ans+"Two Billion";
            digits.pop_back();
        }
        if(digits.size()>=7){
            n=digits.size();
            temp=0;
            for(int i=n-1;i>=6;i--){
                temp=temp*10+digits[i];
                digits.pop_back();
            }
            string c=(ans.size())?" ":"";
            if(temp!=0) ans=ans+c+spell(temp)+" Million";
        }
        if(digits.size()>=4){
            n=digits.size();
            temp=0;
            for(int i=n-1;i>=3;i--){
                temp=temp*10+digits[i];
                digits.pop_back();
            }
            string c=(ans.size())?" ":"";
            if(temp!=0) ans=ans+c+spell(temp)+" Thousand";
        }
        n=digits.size();
        temp=0;
        for(int i=n-1;i>=0;i--){
            temp=temp*10+digits[i];
            digits.pop_back();
        }
        string c=(ans.size())?" ":"";
        if(temp!=0) ans=ans+c+spell(temp);

        return ans;
    }
};