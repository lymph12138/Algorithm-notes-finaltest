/*
1328
*/
class Solution {
public:
    string breakPalindrome(string palindrome) {
        int m=palindrome.size();
        if(m==1)    return "";
        int tag=0;
        for(;tag<m;tag++){
            if(m%2 && tag==m/2)   continue;
            if(palindrome[tag]!='a'){
                palindrome[tag]='a';
                tag=m+1;
                break;
            }
        }
        if(tag==m)  palindrome[tag-1]='b';
        return palindrome;
    }
};