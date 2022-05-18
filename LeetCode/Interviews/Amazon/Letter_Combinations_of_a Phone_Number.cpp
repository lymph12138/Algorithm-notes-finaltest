/*
17
*/
class Solution {
public:
    vector<string> ans;
    vector<string> letter={"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    void dfs(string digits, int idx, string temp){
        if(idx==digits.size()){
            ans.push_back(temp);
            return ;
        }
        for(int i=0;i<letter[digits[idx]-'2'].size();i++)
            dfs(digits,idx+1,temp+letter[digits[idx]-'2'][i]);
    }
    vector<string> letterCombinations(string digits) {
        if(digits.size()==0)    return ans;
        dfs(digits,0,"");

        return ans;
    }
};