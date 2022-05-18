/*
8
*/
class Solution {
public:
    int myAtoi(string s) {
        int tag=0;
        while(s[tag]==' ')    tag++;
        bool sign=true;
        if(s[tag]=='-'){
            sign=false;
            tag++;
        }
        else if(s[tag]=='+')  tag++;
        while(s[tag]=='0')    tag++;
        int ans=0;
        for(;tag<s.size();tag++){
            if(s[tag]<'0' || s[tag]>'9')    return ans*(sign?1:-1);
            if(ans>(INT_MAX-(s[tag]-'0'))/10 && sign)    return INT_MAX;
            if(ans>(INT_MAX-(s[tag]-'0'))/10 && !sign)  return INT_MIN;
            ans=ans*10+(s[tag]-'0');
        }
        return ans*(sign?1:-1);
    }
};
