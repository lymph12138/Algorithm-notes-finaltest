/*
1881
*/
class Solution {
public:
    string maxValue(string n, int x) {
        bool sign=(n[0]=='-'?false:true);
        string ans;
        if(sign){
            int pos=0;
            while(pos<n.size()){
                if(n[pos]-'0'<x)    break;
                pos++;
            }
            char c=x+'0';
            ans=n.substr(0,pos)+c+n.substr(pos,n.size()-pos);
        }
        else{
            int pos=0;
            while(pos<n.size()){
                if(n[pos]-'0'>x)    break;
                pos++;
            }
            char c=x+'0';
            ans=n.substr(0,pos)+c+n.substr(pos,n.size()-pos);
        }
        return ans;
    }
};