/*
224
*/
class Solution {
public:
    int solve(string& s,int b,int e){
        int sum=0,sign=1,num=0;
        for(int i=b;i<=e;i++){
            if(s[i]==' ')   continue;
            else if(s[i]>='0' && s[i]<='9')
                num=num*10+(s[i]-'0');
            else if(s[i]=='+' || s[i]=='-'){
                sum+=sign*num;
                num=0;
                if(s[i]=='+')   sign=1;
                else    sign=-1;
            }
            else if(s[i]=='('){
                int c=1,j=i+1;
                while(true){
                    if(s[j]=='(')   c++;
                    if(s[j]==')')   c--;
                    if(c==0)    break;
                    j++;
                }
                num=solve(s,i+1,j-1);
                i=j;
            }
        }
        sum+=sign*num;
        return sum;
    }
    int calculate(string s) {
        int n=s.size();
        return solve(s,0,n-1);
    }
};