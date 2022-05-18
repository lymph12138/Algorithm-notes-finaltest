/*
856
*/
class Solution {
public:
    int scoreOfParentheses(string s) {
        int ans=0;
        stack<int> num;
        for(auto a:s){
            if(a=='('){
                num.push(ans);
                ans=0;
            }else{
                ans+=num.top()+max(ans,1);
                num.pop();
            }
        }
        return ans;
    }
};